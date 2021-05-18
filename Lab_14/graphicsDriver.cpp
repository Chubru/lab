//#include <windows.h>    // Win32API Header File
//#include <cstdio>
//#include "graphicsDriver.h"
//
//
//#pragma warning(disable : 4996)		
//
//
//
//
//
//HWND    hConWnd;
////
//int     BCX_Line(HWND, int, int, int, int, int = 0, HDC = 0);
//int     BCX_Circle(HWND, int, int, int, int = 0, int = 0, HDC = 0);
////
//HWND    GetConsoleWndHandle(void);
//
//
//int graphicsDriver::BCX_Line(HWND Wnd, int x1, int y1, int x2, int y2, int Pen, HDC DrawHDC)
//{
//	int a, b = 0;
//	HPEN hOPen;
//	// penstyle, width, color
//	HPEN hNPen = CreatePen(PS_SOLID, 2, Pen);
//	if (!DrawHDC) DrawHDC = GetDC(Wnd), b = 1;
//	hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
//	// starting point of line
//	MoveToEx(DrawHDC, x1, y1, NULL);
//	// ending point of line
//	a = LineTo(DrawHDC, x2, y2);
//	DeleteObject(SelectObject(DrawHDC, hOPen));
//	if (b) ReleaseDC(Wnd, DrawHDC);
//	return a;
//}
//
//// converts circle(centerX,centerY,radius,pen) to WinApi function
//// ellipse inside box with upper left and lower right coordinates
//int graphicsDriver::BCX_Circle(HWND Wnd, int X, int Y, int R, int Pen, int Fill, HDC DrawHDC)
//{
//	int a, b = 0;
//	if (!DrawHDC) DrawHDC = GetDC(Wnd), b = 1;
//	// penstyle, width, color
//	HPEN   hNPen = CreatePen(PS_SOLID, 2, Pen);
//	HPEN   hOPen = (HPEN)SelectObject(DrawHDC, hNPen);
//	HBRUSH hOldBrush;
//	HBRUSH hNewBrush;
//	// if true will fill circle with pencolor
//	if (Fill)
//	{
//		hNewBrush = CreateSolidBrush(Pen);
//		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
//	}
//	else
//	{
//		hNewBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
//		hOldBrush = (HBRUSH)SelectObject(DrawHDC, hNewBrush);
//	}
//	a = Ellipse(DrawHDC, X - R, Y + R, X + R, Y - R);
//	DeleteObject(SelectObject(DrawHDC, hOPen));
//	DeleteObject(SelectObject(DrawHDC, hOldBrush));
//	if (b) ReleaseDC(Wnd, DrawHDC);
//	return a;
//}
//
