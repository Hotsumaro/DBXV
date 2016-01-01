// dllmain.cpp : Defines the entry point for the DLL application.
#include "dbxv.h"

void Start()
{
	unsigned int slot = 1;
	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1) & 0x8000)
			slot = 1;
		if (GetAsyncKeyState(VK_NUMPAD2) & 0x8000)
			slot = 2;
		if (GetAsyncKeyState(VK_NUMPAD3) & 0x8000)
			slot = 3;
		if (GetAsyncKeyState(VK_NUMPAD4) & 0x8000)
			slot = 4;
		if (GetAsyncKeyState(VK_NUMPAD5) & 0x8000)
			slot = 5;
		if (GetAsyncKeyState(VK_NUMPAD6) & 0x8000)
			slot = 6;
		if (GetAsyncKeyState(VK_NUMPAD7) & 0x8000)
			slot = 7;
		if (GetAsyncKeyState(VK_NUMPAD8) & 0x8000)
			slot = 8;
		if (GetAsyncKeyState(VK_F1) & 0x8000)
			AddZeny(1000000, slot);
		if (GetAsyncKeyState(VK_F2) & 0x8000)
			AddAttributes(100, slot);
		if (GetAsyncKeyState(VK_F3) & 0x8000)
			AddLevel(1, slot);
		if (GetAsyncKeyState(VK_F4) & 0x8000)
			AddExperience(1000000, slot);
		Sleep(100);
	}
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		MessageBoxA(NULL, "Attached", "Test", 0);
		HANDLE threadHandle = CreateRemoteThread(GetCurrentProcess(), NULL, 0, (LPTHREAD_START_ROUTINE)Start, NULL, 0, NULL);
		if (threadHandle == NULL)
			return false;
	}
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

