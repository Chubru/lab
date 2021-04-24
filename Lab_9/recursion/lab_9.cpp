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
	cout << "new v1\n";
	int N_, M_;
	cout << "razm\n";
	cin >> M_;
	detInt_t** matrix = new detInt_t* [M_];
	for (detInt_t i = 0; i < M_; i++) {
		matrix[i] = new detInt_t[M_];
		for (int j = 0; j < M_; j++) {
			cout << i<<" "<<j<<" \n";
			cin >> matrix[i][j];
		}
	}

	time_t tStart = time(NULL);

	cout << determinant(matrix, M_) << "\n";
	time_t tEnd = time(NULL);
	cout << "\n\nElapsed time:" << tEnd - tStart << " " << tEnd << " " << tStart;

	for (int i = 0; i < M_; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}







