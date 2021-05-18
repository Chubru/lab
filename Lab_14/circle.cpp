#include "circle.h"
#include <conio.h>
#include <windows.h>    // Win32API Header File
#include <cstdio>
#pragma warning(disable : 4996)		



void circle::printxy() {
	HWND hConWnd = GetConsoleWndHandle();
	BCX_Circle(hConWnd, x, y, r, Blue);
}
