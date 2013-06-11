#include <xtl.h>
#include <xboxmath.h>
#include <stdio.h>
#include <kernelp.h>
#include <kernel.h>
#include <fstream>
#include <string>
#include <list>

using namespace std;

#include "Other.hpp"

extern "C" const TCHAR szModuleName[] = TEXT( "AllocLogger.dll" );

extern "C"
{
	VOID* MmAllocatePhysicalMemoryEx(DWORD dwFlags, DWORD dwSize, DWORD flProtect, PVOID ulPhysicalAddress, DWORD r7, DWORD ulAlignment);
	DWORD MmFreePhysicalMemory(DWORD r3, PVOID r4);

	DWORD NtAllocateVirtualMemory(DWORD *r3, DWORD *r4, DWORD r5, DWORD r6, DWORD r7);
	DWORD NtFreeVirtualMemory(DWORD *r3, DWORD r4, DWORD r5);

	VOID ExRegisterThreadNotification( PEX_THREAD_REGISTRATION, BOOL );
	DWORD XamGetCurrentTitleId();

	VOID KeSweepIcacheRange( PVOID Address, DWORD cbBytes );

	extern PLDR_DATA_TABLE_ENTRY* XexExecutableModuleHandle;

	extern PKERNEL_VERSION XboxKrnlVersion;
}

typedef struct _MemoryEntry
{
	PVOID Address;
	DWORD Size;
} AllocatedData, *PAllocatedData;

list<AllocatedData> PhysicalMemory;
list<AllocatedData> VirtualMemory;

WSADATA wsa;
SOCKET sock;
struct sockaddr_in server;
struct sockaddr_in client;

DWORD NtImageSize = 0;
PVOID NtImageBase = NULL;

BYTE NtAllocateVirtualMemoryPattern[16];
DWORD NtAllocateVirtualMemoryOffset = 0;

BYTE NtFreeVirtualMemoryPattern[16];
DWORD NtFreeVirtualMemoryOffset = 0;

BYTE MmAllocatePhysicalMemoryExPattern[16];
DWORD MmAllocatePhysicalMemoryExOffset = 0;

BYTE MmFreePhysicalMemoryPattern[16];
DWORD MmFreePhysicalMemoryOffset = 0;

BOOL InitUDPSocket()
{
	BOOL bBroadcast = TRUE;

	DWORD dwStatus = XNetGetEthernetLinkStatus();
	int m_bIsActive = (dwStatus & XNET_ETHERNET_LINK_ACTIVE) != 0;

	if (!m_bIsActive)
	{
		printf("No Ethernet Link Active\n");
		return FALSE;
	}

	XNetStartupParams _XNetStartupParams;
	memset(&_XNetStartupParams, 0, sizeof(_XNetStartupParams));
	_XNetStartupParams.cfgSizeOfStruct = sizeof(XNetStartupParams);
	_XNetStartupParams.cfgSockDefaultRecvBufsizeInK = 128; 
	_XNetStartupParams.cfgSockDefaultSendBufsizeInK = 128;
	_XNetStartupParams.cfgFlags = XNET_STARTUP_BYPASS_SECURITY;

	int iResult = XNetStartup(&_XNetStartupParams);
	if (iResult != NO_ERROR)
	{
		printf("XNetStartup Failed\n");
		return FALSE;
	}

	ZeroMemory(&wsa, sizeof(WSADATA));
	if (WSAStartup(0x0202, &wsa) != 0)
	{
		printf("WSAStartup Failed\n");
		return FALSE;
	}

	sockaddr_in server;

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.S_un.S_addr = ADDR_ANY;
	server.sin_port = htons(3879);

	sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if (sock == INVALID_SOCKET)
	{
		printf("Error While Creating The Socket\n");
		return FALSE;
	}

	if(setsockopt(sock, SOL_SOCKET, 0x5801, (PCSTR)&bBroadcast, sizeof(BOOL)) != 0 )
	{
	   DWORD error = GetLastError();
	   printf("Failed to set socket to 5801, error: %i\n", error);
	   return FALSE;
	}

	if(setsockopt(sock, SOL_SOCKET, 0x5802, (PCSTR)&bBroadcast, sizeof(BOOL)) != 0 )
	{
	   DWORD error = GetLastError();
	   printf("Failed to set socket to 5802, error: %i\n", error);
	   return FALSE;
	}

	if(bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		DWORD error = GetLastError();
		printf("Connection failed: %i\n", error);
		return FALSE;
	}

	return TRUE;
}

//8270D41C NtFreeVirtualMemory
//8270D42C NtAllocateVirtualMemory

//8270D80C MmAllocatePhysicalMemoryEx
//8270D81C MmFreePhysicalMemory

//823D22D0 RtlAllocateHeap
//823D2BB8 RtlFreeHeap

VOID AddToAllocData(list<AllocatedData> *pList, PVOID Addr, DWORD Size)
{
	AllocatedData alloc;

	alloc.Address = Addr;
	alloc.Size = Size;

	pList->push_back(alloc);
}

VOID RemoveFromAllocData(list<AllocatedData> *pList, PVOID Addr)
{
	for (list<AllocatedData>::iterator i = pList->begin(); i != pList->end(); i++)
	{
		if (i->Address == Addr)
		{
			pList->erase(i);
			//printf("Removed Address %08X\n", i->Address);
		}
	}
}

DWORD MmFreePhysicalMemory_Hook(DWORD r3, PVOID r4)
{
	DWORD result = MmFreePhysicalMemory(r3, r4);

	//printf("MmFreePhysicalMemory %08X\n", r4);
	RemoveFromAllocData(&PhysicalMemory, r4);

	return result;
}

DWORD NtFreeVirtualMemory_Hook(DWORD *r3, DWORD r4, DWORD r5)
{
	DWORD result = NtFreeVirtualMemory(r3, r4, r5);

	//printf("NtFreeVirtualMemory %08X\n", r3);
	RemoveFromAllocData(&VirtualMemory, r3);

	return result;
}

VOID* MmAllocatePhysicalMemoryEx_Hook(DWORD dwFlags, DWORD dwSize, DWORD flProtect, PVOID ulPhysicalAddress, DWORD r7, DWORD ulAlignment)
{
	VOID *ptr = MmAllocatePhysicalMemoryEx(dwFlags, dwSize, flProtect, ulPhysicalAddress, r7, ulAlignment);

	//printf("MmAllocatePhysicalMemoryEx Addr = %08X Length = %d\n", ptr, dwSize);
	AddToAllocData(&PhysicalMemory, ptr, dwSize);

	return ptr;
}

DWORD NtAllocateVirtualMemory_Hook(DWORD *r3, DWORD *r4, DWORD r5, DWORD r6, DWORD r7)
{
	DWORD result = NtAllocateVirtualMemory(r3, r4, r5, r6, r7);

	//printf("NtAllocateVirtualMemory Addr = %08X Length = %d\n", *r3, *r4);
	AddToAllocData(&VirtualMemory, (PVOID)(*r3), *r4);

	return result;
}

PVOID __cdecl RtlAllocateHeap_Hook(PVOID HeapHandle, DWORD Flags, DWORD Size)
{
	PVOID result = RtlAllocateHeap(HeapHandle, Flags, Size);

	//printf("RtlAllocateHeap Addr = %08X Length = %d\n", result, Size);

	return result;
}

DWORD __cdecl RtlFreeHeap_Hook(PVOID HeapHandle, DWORD Flags, PVOID BaseAddress)
{
	DWORD result = RtlFreeHeap(HeapHandle, Flags, BaseAddress);

	//printf("RtlFreeHeap Addr = %08X\n", BaseAddress);

	return result;
}

DWORD WINAPI ServerThread(PVOID pParam)
{
	BYTE Buffer[1024];

	while (TRUE)
	{
		ZeroMemory(Buffer, 1024);

		int client_length = sizeof(struct sockaddr_in);
		DWORD bytes_received = recvfrom(sock, (char*)Buffer, 1024, 0, (struct sockaddr *)&client, &client_length);

		if (bytes_received < 0)
		{
			printf("Could not receive datagram.\n");
			break;
		}

		if (strncmp((char*)Buffer, "queryallocateddata", 18) == 0)
		{
			list<AllocatedData> PhysicalMemoryCopy = PhysicalMemory;
			list<AllocatedData> VirtualMemoryCopy = VirtualMemory;

			DWORD sizetoalloc = (PhysicalMemoryCopy.size() * sizeof(AllocatedData)) + (VirtualMemoryCopy.size() * sizeof(AllocatedData));

			PBYTE data = new BYTE[sizetoalloc];
			ZeroMemory(data, sizetoalloc);

			PBYTE dataptr = data;

			for (list<AllocatedData>::iterator i = PhysicalMemoryCopy.begin(); i != PhysicalMemoryCopy.end(); i++)
			{
				PAllocatedData palloc = (PAllocatedData)dataptr;

				palloc->Address = i->Address;
				palloc->Size = i->Size;

				dataptr += sizeof(AllocatedData);
			}

			for (list<AllocatedData>::iterator i = VirtualMemoryCopy.begin(); i != VirtualMemoryCopy.end(); i++)
			{
				PAllocatedData palloc = (PAllocatedData)dataptr;

				palloc->Address = i->Address;
				palloc->Size = i->Size;

				dataptr += sizeof(AllocatedData);
			}

			sendto(sock, (char *)data, sizetoalloc, 0, (struct sockaddr *)&client, client_length);

			delete data;
		}
	}

	return 0;
}

DWORD FindPattern(PVOID pvMemory, DWORD dwSize, PVOID pvPattern, DWORD dwPatternSize)
{
	PBYTE pbMemory = (PBYTE)pvMemory;
	PBYTE pbPattern = (PBYTE)pvPattern;

	for (DWORD i = 0; i < dwSize - dwPatternSize; i++)
	{
		if (memcmp(pbMemory + i, pbPattern, dwPatternSize) == 0)
		{
			return (DWORD)(pbMemory + i);
		}
	}

	return NULL;
}

BOOL PatternScan()
{
	DWORD ImpNtAllocateVirtualMemory = ResolveFunct("xboxkrnl.exe", 204);
	DWORD ImpNtFreeVirtualMemory = ResolveFunct("xboxkrnl.exe", 220);
	DWORD ImpMmAllocatePhysicalMemoryEx = ResolveFunct("xboxkrnl.exe", 186);
	DWORD ImpMmFreePhysicalMemory = ResolveFunct("xboxkrnl.exe", 189);

	// Virtual Memory
	PatchInJump((PDWORD)NtAllocateVirtualMemoryPattern, ImpNtAllocateVirtualMemory, FALSE);
	PatchInJump((PDWORD)NtFreeVirtualMemoryPattern, ImpNtFreeVirtualMemory, FALSE);

	// Physical Memory
	PatchInJump((PDWORD)MmAllocatePhysicalMemoryExPattern, ImpMmAllocatePhysicalMemoryEx, FALSE);
	PatchInJump((PDWORD)MmFreePhysicalMemoryPattern, ImpMmFreePhysicalMemory, FALSE);

	// Find Virtual Memory Patterns
	NtAllocateVirtualMemoryOffset = FindPattern(NtImageBase, NtImageSize, NtAllocateVirtualMemoryPattern, 16);
	NtFreeVirtualMemoryOffset = FindPattern(NtImageBase, NtImageSize, NtFreeVirtualMemoryPattern, 16);

	// Find Physical Memory Patterns
	MmAllocatePhysicalMemoryExOffset = FindPattern(NtImageBase, NtImageSize, MmAllocatePhysicalMemoryExPattern, 16);
	MmFreePhysicalMemoryOffset = FindPattern(NtImageBase, NtImageSize, MmFreePhysicalMemoryPattern, 16);

	printf("NtAllocateVirtualMemoryOffset %08X\n", NtAllocateVirtualMemoryOffset);
	printf("NtFreeVirtualMemoryOffset %08X\n", NtFreeVirtualMemoryOffset);

	printf("MmAllocatePhysicalMemoryExOffset %08X\n", MmAllocatePhysicalMemoryExOffset);
	printf("MmFreePhysicalMemoryOffset %08X\n", MmFreePhysicalMemoryOffset);

	if (NtAllocateVirtualMemoryOffset == NULL || NtFreeVirtualMemoryOffset == NULL || MmAllocatePhysicalMemoryExOffset == NULL || MmFreePhysicalMemoryOffset == NULL)
		return FALSE;
	
	printf("Hooking virtual memory functions\n");
	PatchInJump((PDWORD)NtAllocateVirtualMemoryOffset, (DWORD)NtAllocateVirtualMemory_Hook, FALSE);
	PatchInJump((PDWORD)NtFreeVirtualMemoryOffset, (DWORD)NtFreeVirtualMemory_Hook, FALSE);

	printf("Hooking physical memory functions\n");
	PatchInJump((PDWORD)MmAllocatePhysicalMemoryExOffset, (DWORD)MmAllocatePhysicalMemoryEx_Hook, FALSE);
	PatchInJump((PDWORD)MmFreePhysicalMemoryOffset, (DWORD)MmFreePhysicalMemory_Hook, FALSE);

	return TRUE;
}

VOID LpThreadNotificationRoutine( PEX_THREAD_REGISTRATION pxThreadReg, PKTHREAD pThread, BOOL Creating )
{
	if( Creating && ( pThread->CreateOptions & 0x100 ) )
	{
		DWORD TitleID = XamGetCurrentTitleId();

		NtImageSize = ( *XexExecutableModuleHandle )->SizeOfNtImage;
		NtImageBase = ( *XexExecutableModuleHandle )->NtHeadersBase;

		wprintf( L"Loaded game executable. Path = %s\n", ( *XexExecutableModuleHandle )->FullDllName.Buffer );
		printf("Title ID %08X NtImageSize %08X NtImageBase %08X\n", TitleID, NtImageSize, NtImageBase);

		if (TitleID == 0xFFFE07D1 || TitleID == 0xF5D10000 || TitleID == 0x00000000)
			return;

		PhysicalMemory.clear();
		VirtualMemory.clear();

		AddToAllocData(&VirtualMemory, NtImageBase, NtImageSize);

		printf("Searching for patterns...\n");
		if (PatternScan())
			printf("Search is successful.\n");
		else
			printf("Search Failed!\n");

		printf("Starting UDP socket on port 3879...\n");

		if (InitUDPSocket())
		{
			HANDLE hThread = CreateThread(NULL, NULL, ServerThread, NULL, NULL, NULL);	
			printf("UDP Server Thread Created %08X\n", hThread);
		}
		else
		{
			printf("UDP server failed to start\n");
		}
	}
}

EX_THREAD_REGISTRATION xThreadReg = 
{ 
	LpThreadNotificationRoutine, 
	0, 
	0, 
	0 
};

void EntryPoint()
{
	ExRegisterThreadNotification( &xThreadReg, TRUE );
}

BOOL APIENTRY DllMain(HANDLE hModule, DWORD reason, LPVOID lpReserved) 
{
	if (reason == DLL_PROCESS_ATTACH) 
	{
		HANDLE pthread;
		DWORD pthreadid;
		DWORD sta;

		sta = ExCreateThread(
			&pthread, 
			0, 
			&pthreadid, 
			(VOID*)XapiThreadStartup , 
			(LPTHREAD_START_ROUTINE)EntryPoint, 
			0, 
			0x2
			);

		ResumeThread(pthread);
		CloseHandle(pthread);
	}

	return TRUE;
}

