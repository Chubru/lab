#include "segment.h"
#include <conio.h>
#include <windows.h>    // Win32API Header File
#include <cstdio>
#pragma warning(disable : 4996)		




//

//

void segment::printxy(){
	HWND hConWnd = GetConsoleWndHandle();
	BCX_Line(hConWnd, end.x, end.y, start.x, start.y, Red);
}
