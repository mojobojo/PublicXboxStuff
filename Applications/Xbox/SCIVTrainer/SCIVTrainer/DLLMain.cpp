#include "stdafx.h"

extern "C"
{
	NTSYSAPI
	DWORD
	NTAPI
	XexGetModuleHandle(
		IN		PSZ moduleName,
		IN OUT	PHANDLE hand
		); 

	NTSYSAPI
	DWORD
	NTAPI
	XexGetProcedureAddress(
		IN		HANDLE hand,
		IN		DWORD dwOrdinal,
		IN		PVOID Address
		);
}

// Thank you freestyle dash
typedef VOID (*XNOTIFYQUEUEUI)(DWORD ID, DWORD Index, DWORD r5, WCHAR* Text, DWORD r7);
XNOTIFYQUEUEUI XNotifyQueueUI;

#define Notify(Str) XNotifyQueueUI(0x22, 0xFF, 1, Str, 0);

D3DDevice* g_pd3dDevice = NULL;

BOOL GoldCheat = FALSE;
BOOL LockTimer = FALSE;
DWORD TimerLastValue = 0;
BOOL LockOverallTime = FALSE;
BOOL LockHealth = FALSE;

DWORD RenderState = 0;
DWORD RenderStates[] = 
{
	D3DFILL_POINT,
	D3DFILL_WIREFRAME,
	D3DFILL_SOLID,
	//D3DFILL_FORCE_DWORD
};

typedef struct _SC4PLAYER
{
	FLOAT Unk0;
	BYTE  Pad0[32];
	FLOAT Unk1;
	DWORD Unk2;
	FLOAT Unk3;
	FLOAT Unk4;
	FLOAT Unk5;
	FLOAT Unk6;
	FLOAT Health; // Real Health Value
	FLOAT Unk8;
	DWORD Unk9;
	FLOAT HealthCopy; // Setting this does not set health
	BYTE  Pad1[16];
	FLOAT Unk11;
	BYTE  Pad2[20];
	FLOAT Unk12;
} SC4Player, *PSC4Player;

PSC4Player Player1 = (PSC4Player)0x82C52860;
PSC4Player Player2 = (PSC4Player)0x82CAD230;
DWORD *PlayerGold = (DWORD*)0x82DFF150;
DWORD *Timer = (DWORD*)0x82C3467C;
DWORD *OverallTime = (DWORD*)0x82C34688;

//-----------------------------------------------------------------------------
// Desc: Export a global constant variable
//-----------------------------------------------------------------------------
extern "C" const TCHAR szModuleName[] = TEXT( "SCIVTrainer.dll" );

DWORD ResolveFunct(PCHAR modname, DWORD ord)
{
	DWORD ret=0, ptr2=0;
	HANDLE hand;
	ret = XexGetModuleHandle(modname, &hand); //xboxkrnl.exe xam.dll?
	if(ret == 0)
	{
		ret = XexGetProcedureAddress(hand, ord, &ptr2 );
		if(ptr2 != 0)
			return ptr2;
	}
	return 0; // function not found
}

VOID PatchInJump(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3D600000 + (((dest >> 16) & 0xFFFF) + 1); // lis 	%r11, dest>>16 + 1
	else
		addr[0] = 0x3D600000 + ((dest >> 16) & 0xFFFF); // lis 	%r11, dest>>16

	addr[1] = 0x396B0000 + (dest & 0xFFFF); // addi	%r11, %r11, dest&0xFFFF
	addr[2] = 0x7D6903A6; // mtctr	%r11

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
}

VOID PulseController()
{
	XINPUT_VIBRATION xvib;
	xvib.wLeftMotorSpeed = 50000;
	xvib.wRightMotorSpeed = 50000;

	XInputSetState(0, &xvib);

	Sleep(300);

	xvib.wLeftMotorSpeed = 0;
	xvib.wRightMotorSpeed = 0;

	XInputSetState(0, &xvib);
}

VOID LoadD3DPointer()
{
	__asm
	{
		lau		r11, g_pd3dDevice
		lal     r11, r11, g_pd3dDevice
		lis		r12, 0x8311
		ori		r12, r12, 0x0704 // D3D Pointer = 0x83110704
		lwz		r12, 0(r12)
		stw		r12, 0(r11)
	}
}

VOID DllThread()
{
	XINPUT_STATE xstate;

	while(g_pd3dDevice == NULL) // Wait for the d3d device to be created
		LoadD3DPointer();

	while (TRUE)
	{
		if (XInputGetState(0, &xstate) == ERROR_SUCCESS)
		{
			if(xstate.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_A))
			{
				GoldCheat = !GoldCheat;
				PulseController();
				Notify(GoldCheat ? L"Gold Activated" : L"Gold Deactivated");
			}

			if(xstate.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_Y))
			{
				LockTimer = !LockTimer;

				if (LockTimer)
					TimerLastValue = *Timer;
				if (!LockTimer)
					*Timer = TimerLastValue;

				PulseController();
				Notify(LockTimer ? L"Timer Locked" : L"Timer Unlocked");
			}

			if(xstate.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_B))
			{
				LockOverallTime = !LockOverallTime;
				PulseController();
				Notify(LockOverallTime ? L"Overall Time Locked" : L"Overall Time Unlocked");
			}

			if(xstate.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_X))
			{
				LockHealth = !LockHealth;
				PulseController();
				Notify(LockHealth ? L"Health Locked" : L"Health Unocked");
			}

			if(xstate.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_DPAD_UP))
			{
				RenderState++;
				RenderState = RenderState % 3;
				g_pd3dDevice->SetRenderState(D3DRS_FILLMODE, RenderStates[RenderState]);
				PulseController();
				Notify(L"Render State Changed");
			}

			if (GoldCheat)
				*PlayerGold = 999666999;

			if (LockTimer)
				*Timer = -1;

			if (LockOverallTime)
				*OverallTime = 0;

			if (LockHealth)
				Player1->Health = 240.0;
		}

		Sleep(100);
	}
}

LONG WINAPI Exception(struct _EXCEPTION_POINTERS *e)
{
	Notify(L"Trainer crashed for some reason");
	XLaunchNewImage(NULL, NULL);
}

//-----------------------------------------------------------------------------
// Name: Load()
// Desc: Export function
//-----------------------------------------------------------------------------
extern "C" void Load()
{
	SetUnhandledExceptionFilter(Exception);

	XNotifyQueueUI = (XNOTIFYQUEUEUI)ResolveFunct("xam.xex", 656);
	
	if (XNotifyQueueUI == NULL)
		return;

	HANDLE hThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)DllThread, NULL, NULL, NULL);	
	printf("Thread Created %08X\n", hThread);

	Notify(L"Trainer Loaded");
}

//-----------------------------------------------------------------------------
// Name: DllMain()
// Desc: The function which is called at initialization/termination of the process
//       and thread and whenever LoadLibrary() or FreeLibrary() are called.
//       The DllMain routine should not be used to load another module or call a
//       routine that may block.
//-----------------------------------------------------------------------------
BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD ul_reason_for_call,
                       LPVOID lpReserved
                       )
{
    switch( ul_reason_for_call )
    {
        case DLL_PROCESS_ATTACH:
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
        case DLL_PROCESS_DETACH:
            break;

    }
    return TRUE;
}
