#ifndef __OTHER_HPP
#define __OTHER_HPP

DWORD ResolveFunct(PCHAR modname, DWORD ord);
VOID PatchInJump(PDWORD addr, DWORD dest, BOOL linked);
HRESULT MountPath(const char* szDrive, const char* szDevice, BOOL both);
BYTE *GetFile(CHAR *szPath, PDWORD pdwOutSize);
BOOL DumpFile(CHAR *szFileName, BYTE *pbData, DWORD dwSize);
VOID BinaryDump(BYTE *pbData, DWORD dwSize);

#endif