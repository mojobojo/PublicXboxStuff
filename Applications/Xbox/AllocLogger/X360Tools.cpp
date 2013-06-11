#include "X360Tools.hpp"

void MessageBox(LPCWSTR Text, LPCWSTR Caption) {
	LPCWSTR* text;
	text = new LPCWSTR[1];
	text[0] = L"Ok";
	PXOVERLAPPED over = new XOVERLAPPED();
	memset(over, 0, sizeof(over));
	PMESSAGEBOX_RESULT result = new MESSAGEBOX_RESULT();
	memset(result, 0, sizeof(result));

	while(XShowMessageBoxUI(0, Caption, Text, 1, text, 0, XMB_NOICON, result, over) == ERROR_ACCESS_DENIED)
		Sleep(500);
	while(!XHasOverlappedIoCompleted(over))
		Sleep(500);
}

UINT32 ResolveFunct(char* modname, HANDLE ord) {
	UINT32 ret = 0, ptr2 = 0;
	HANDLE ptr32 = 0;

	ret = XexGetModuleHandle(modname, &ptr32);
	if(ret == 0) {
		ret = XexGetProcedureAddress(ptr32, (DWORD)ord, &ptr2);
		if(ptr2 != 0)
			return(ptr2);
	}
	return(0);
}

DWORD GetPressedButtons() {
	XINPUT_STATE xstate;

	if (XInputGetState(0, &xstate) == ERROR_SUCCESS)
		return xstate.Gamepad.wButtons;
	else
		return (DWORD)-1;
}