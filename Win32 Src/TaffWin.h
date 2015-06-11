
#include <Windows.h>
#include <cstdlib>
#include <string.h>
#include <tchar.h>

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow);

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//Global vars
HINSTANCE hInst;