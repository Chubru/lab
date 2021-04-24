// lab_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "logic.h"
#include <stdio.h>
#include <iostream>
#include <time.h>

#pragma warning(disable : 4996)  

using namespace std;


int main()
{



	time_t tStart = time(NULL);
	int size{ 0 };
	std::cout << "size\n";
	std::cin >> size;


	auto  matrix = init(size);
	cout << determinant(matrix, size) << "\n";

	time_t tEnd = time(NULL);
	cout << "\n\nElapsed time:" << tEnd - tStart << " " << tEnd << " " << tStart;

	del(matrix, size);
	return 0;
}







