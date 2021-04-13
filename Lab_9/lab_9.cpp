// lab_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "logic.h"
#include <stdio.h>
#include <iostream>


#pragma warning(disable : 4996)  

using namespace std;





int main()
{
	int N_, M_;
	cin >> N_;
	cin >> M_;
	int** matrix = new int* [N_];
	for (int i = 0; i < N_; i++) {
		matrix[i] = new int[M_];
		for (int j = 0; j < M_; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << determinant(matrix, M_) << "\n";


	for (int i = 0; i < N_; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return 0;
}







