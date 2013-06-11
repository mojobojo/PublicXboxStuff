#include "Mount.hpp"

HRESULT MountPath( const PCHAR szDrive, const PCHAR szDevice )
{
	PCHAR szSysStr = NULL;
	if ( KeGetCurrentProcessType() == SYSTEM_PROC )
		szSysStr = "\\System??\\%s";
	else
		szSysStr = "\\??\\%s";

	CHAR szDestinationDrive[ MAX_PATH ];
	sprintf_s( szDestinationDrive, MAX_PATH, szSysStr, szDrive );

	STRING strDeviceName = MAKE_STRING( szDevice );
	STRING strLinkName = MAKE_STRING( szDestinationDrive );

	ObDeleteSymbolicLink( &strLinkName );

	return ObCreateSymbolicLink( &strLinkName, &strDeviceName );
}

HRESULT UnmountPath( const PCHAR szDrive )
{
	PCHAR szSysStr = NULL;
	if ( KeGetCurrentProcessType() == SYSTEM_PROC )
		szSysStr = "\\System??\\%s";
	else
		szSysStr = "\\??\\%s";

	CHAR szDestinationDrive[ MAX_PATH ];
	sprintf_s( szDestinationDrive, MAX_PATH, szSysStr, szDrive );

	STRING strLinkName = MAKE_STRING( szDestinationDrive );

	return ObDeleteSymbolicLink( &strLinkName );
}
