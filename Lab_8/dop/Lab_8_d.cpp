// Lab_8_d.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iomanip>
#include <iostream>
#include "matrix.h"


void callBack(int x, int y, const char* massages, void* pt) {
	std::cout << massages << ": [" << x << ":" << y << "]\n";
	return;
}
int main()
{
    matrix m;
    m.localExtremum(callBack);
}
