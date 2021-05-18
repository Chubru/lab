#include "figure.h"
#include <conio.h>
#include <windows.h>    // Win32API Header File
#include <cstdio>
#pragma warning(disable : 4996)		

int BCX_Line(HWND Wnd, int x1, int y1, int x2, int y2, int Pen, HDC DrawHDC)
{
	int a, b = 0;
	HPEN hOPen;
	// penstyle, width, color
	HPEN hNPen = CreatePen(PS_SOLID, 2, Pen);
	if (!DrawHDC) DrawHDC = GetDC(Wnd), b = 1;
	hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
	// starting point of line
	MoveToEx(DrawHDC, x1, y1, NULL);
	// ending point of line
	a = LineTo(DrawHDC, x2, y2);
	DeleteObject(SelectObject(DrawHDC, hOPen));
	if (b) ReleaseDC(Wnd, DrawHDC);
	return a;
}



int BCX_Circle(HWND Wnd, int X, int Y, int R, int Pen, int Fill, HDC DrawHDC)
{
	int a, b = 0;
	if (!DrawHDC) DrawHDC = GetDC(Wnd), b = 1;
	// penstyle, width, color
	HPEN   hNPen = CreatePen(PS_SOLID, 2, Pen);
	HPEN   hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
	HBRUSH hOldBrush;
	HBRUSH hNewBrush;
	// if true will fill circle with pencolor
	if (Fill)
	{
		hNewBrush = CreateSolidBrush(Pen);
		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
	}
	else
	{
		hNewBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
	}
	a = Ellipse(DrawHDC, X - R, Y + R, X + R, Y - R);
	DeleteObject(SelectObject(DrawHDC, hOPen));
	DeleteObject(SelectObject(DrawHDC, hOldBrush));
	if (b) ReleaseDC(Wnd, DrawHDC);
	return a;
}


// the hoop ...
HWND GetConsoleWndHandle(void)
{
	HWND hConWnd;
	OSVERSIONINFO os;
	char szTempTitle[64], szClassName[128], szOriginalTitle[1024];

	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	GetVersionEx(&os);
	// may not work on WIN9x
	if (os.dwPlatformId == VER_PLATFORM_WIN32s) return 0;

	GetConsoleTitleA(szOriginalTitle, sizeof(szOriginalTitle));
	sprintf(szTempTitle, "%u - %u", GetTickCount(), GetCurrentProcessId());
	SetConsoleTitleA(szTempTitle);
	Sleep(40);
	// handle for NT
	hConWnd = FindWindowA(NULL, szTempTitle);
	SetConsoleTitleA(szOriginalTitle);

	// may not work on WIN9x
	if (os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
	{
		hConWnd = GetWindow(hConWnd, GW_CHILD);
		if (hConWnd == NULL)  return 0;
		GetClassNameA(hConWnd, szClassName, sizeof(szClassName));
		while (strcmp(szClassName, "ttyGrab") != 0)
		{
			hConWnd = GetNextWindow(hConWnd, GW_HWNDNEXT);
			if (hConWnd == NULL)  return 0;
			GetClassNameA(hConWnd, szClassName, sizeof(szClassName));
		}
	}
	return hConWnd;
}



