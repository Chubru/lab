#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include <iostream>

#pragma warning(disable : 4996)  

detInt_t** init(int size) {
	detInt_t** matrix = new detInt_t * [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new detInt_t[size];
		for (int j = 0; j < size; j++) {
			std::cout << i << " " << j << " \n";
			int tmp;
			std::cin >> tmp;
			matrix[i][j] = tmp;
		}
	}
	return matrix;
}

void del(detInt_t** matrix, int size) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
void out(detInt_t** matrix, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
}
detInt_t determinant(detInt_t** matrix, int size) {
	
	for (int i = 0; i < size -1; i++) { //ведущий элемент
		for (int g = 0; g < size; g++) {//по х
			if (g != i) {
				detInt_t temp = -(matrix[g][i] / matrix[i][i]);
				for (int j = 0; j < size; j++) {// по y
					matrix[g][j] = matrix[g][j] + matrix[i][j] * temp;
				}
				//out(matrix, size);
			}
		}
	}
	detInt_t det = 1;
	for (int i = 0; i < size; i++) {
		det *= matrix[i][i];
	}

	return det;
}