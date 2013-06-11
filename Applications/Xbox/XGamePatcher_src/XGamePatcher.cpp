#include "XGamePatcher.hpp"
#include "Mount.hpp"

VOID CheckBlacklist( DWORD dwTitleId )
{
}

VOID DoPatches( PBYTE pBuffer, DWORD dwLength )
{
	DbgPrint( "Doing patches...\n" );
	PDWORD pdwData = ( PDWORD )pBuffer;

	// Sanity check
	if ( pdwData[ ( dwLength / 4 ) - 1 ] != -1 )
	{
		DbgPrint( "Bad patch file. End is not FFFFFFFF but is %08X\n", pdwData[ ( dwLength / 4 ) - 1 ] );
		return;
	}

	while ( TRUE )
	{
		DWORD dwAddress = *pdwData++;

		if ( dwAddress == -1 )
			break;

		DWORD dwPatchCount = *pdwData++;

		DbgPrint( "Patch found. Memory location 0x%08X Patch count %d\n", dwAddress, dwPatchCount );

		for ( DWORD i = 0; i < dwPatchCount; i++ )
		{
			DWORD dwAddrToPatch = dwAddress + ( i * 4 );

			DbgPrint( "Data in address %08X\n", *( DWORD* )dwAddrToPatch );
			DbgPrint( "Patching %08X data patching to %08X\n", dwAddrToPatch, *pdwData );

			*( DWORD* )( dwAddrToPatch ) = *pdwData++;
		}

		KeSweepIcacheRange( ( PVOID )dwAddress, dwPatchCount * 4 );
	}

	DbgPrint( "Patching complete\n" );
}

VOID LpThreadNotificationRoutine( PEX_THREAD_REGISTRATION pxThreadReg, PKTHREAD pThread, BOOL Creating )
{
	if( Creating && ( pThread->CreateOptions & 0x100 ) )
	{
		DbgPrint( "Xbox Kernel Version %d.%d.%d\n", XboxKrnlVersion->Major, XboxKrnlVersion->Minor, XboxKrnlVersion->Build );
		wprintf( L"Loaded game executable. Path = %s\n", ( *XexExecutableModuleHandle )->FullDllName.Buffer );

		DWORD dwGameTitleId = XamGetCurrentTitleId();

		if ( dwGameTitleId == NULL )
		{
			DbgPrint( "Unable to pull the games Title ID, patching aborted.\n" );
			return;
		}

		for( int i = 0; i < DRIVESCOUNT; i++ )
		{
			MountPath( APPMOUNTAS, pszDrivesToCheck[ i ] );
			DbgPrint( "Mounted path \'%s\'\n", pszDrivesToCheck[ i ] );
			DbgPrint( "Checking for %08X.patch\n", dwGameTitleId );

			CHAR szFullPatchPath[ MAX_PATH ];
			sprintf_s( szFullPatchPath, MAX_PATH, "XGP:\\Patches\\%08X.patch", dwGameTitleId );

			HANDLE hFile = CreateFile( szFullPatchPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_READONLY, NULL );

			if ( hFile == INVALID_HANDLE_VALUE )
			{
				DbgPrint( "Unable to open file \'%s\' error %08X\n", szFullPatchPath, GetLastError() );
				continue;				
			}

			DWORD dwFileSize = GetFileSize( hFile, NULL );

			if ( dwFileSize <= 0  )
			{
				DbgPrint( "Bad file size. dwFileSize = %08X\n", dwFileSize );
				continue;
			}

			DbgPrint( "File size = %d bytes\n", dwFileSize );

			PBYTE pFileBuffer = new BYTE[ dwFileSize ];
			DWORD dwBytesRead = 0;
			ReadFile( hFile, pFileBuffer, dwFileSize, &dwBytesRead, NULL );

			DbgPrint( "Read %d byte\n", dwBytesRead );

			CloseHandle( hFile );

			DoPatches( pFileBuffer, dwFileSize );

			delete pFileBuffer;
//Unmount:
//			UnmountPath( APPMOUNTAS );
		}

		DbgPrint( "Everything is done!\n" );
	}
}

EX_THREAD_REGISTRATION xThreadReg = 
{ 
	LpThreadNotificationRoutine, 
	0, 
	0, 
	0 
};

VOID MainThread()
{
	ExRegisterThreadNotification( &xThreadReg, TRUE );
}

BOOL APIENTRY DllMain( HANDLE hModule, DWORD dwReason, LPVOID lpReserved ) 
{
	if ( dwReason == DLL_PROCESS_ATTACH ) 
	{
		HANDLE hThread;
		DWORD dwThreadId;
		
		ExCreateThread( &hThread, 0, &dwThreadId, ( PVOID )XapiThreadStartup , ( LPTHREAD_START_ROUTINE )MainThread, 0, 0x2 );

		ResumeThread( hThread );
		CloseHandle( hThread );
	}

	return TRUE;
}

