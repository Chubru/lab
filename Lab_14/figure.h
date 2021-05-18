 
#pragma once
#include <windows.h>  
#define Red  RGB (255,0,0)
#define Lime RGB (206,255,0)
#define Blue RGB (0,0,255)
HWND    GetConsoleWndHandle(void);
int     BCX_Line(HWND, int, int, int, int, int = 0, HDC = 0);
int     BCX_Circle(HWND, int, int, int, int = 0, int = 0, HDC = 0);
class figure
{
public:
	virtual void print()=0;
	virtual void printxy() = 0;
};

