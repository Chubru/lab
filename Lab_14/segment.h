#pragma once
#include "figure.h"
#include <iostream>
#include <cstring>
#include <iostream>


struct coordinateSTR
{
	int x{ 0 }, y{ 0 };
	friend bool operator !=(coordinateSTR& a, coordinateSTR& b) {
		if (a.x == b.x && a.y == b.y) {
			return false;
		}
		else {
			return true;
		}
	}
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
		std::cout << "segment x1 = " << start.x << " y1 = " << start.y << " x2 = " << end.x << " y2 = " << end.y<<"\n";
	}
	
	void printxy();
private:
	coordinateSTR middle(coordinateSTR nach, coordinateSTR kon) {
		coordinateSTR tmp;
		tmp.x = (nach.x + kon.x)/2;
		tmp.y = (nach.y + kon.y)/2;
		return tmp;
	}
};


