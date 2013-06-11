#pragma once
#include <xtl.h>
#include <stdio.h>
#include <kernel.h>

#define APPMOUNTAS "XGP:"

static PCHAR pszDrivesToCheck[] = 
{
	"\\Device\\Mass0\\",
	"\\Device\\Mass1\\",
	"\\Device\\Mass2\\" ,
	"\\Device\\Harddisk0\\Partition1\\",
};

#define DRIVESCOUNT sizeof( pszDrivesToCheck ) / sizeof ( PCHAR )

HRESULT MountPath( const PCHAR szDrive, const PCHAR szDevice );
HRESULT UnmountPath( const PCHAR szDrive );
