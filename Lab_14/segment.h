#pragma once
#include "figure.h"
#include <iostream>
struct coordinateSTR
{
	int x{ 0 }, y{ 0 };
};
class segment :
	public figure
{
private:
	coordinateSTR start, end;
public:
	segment(int x1, int y1, int x2, int y2) {
		start.x = x1;
		start.y = y1;
		end.x = x2;
		end.y = y2;
	}
	void print() {
		std::cout << "x1 = " << start.x << " y1 = " << start.y << " x2 = " << end.x << " y2 = " << end.y<<"\n";
	}
};

