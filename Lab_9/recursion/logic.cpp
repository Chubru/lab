#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include <iostream>

#pragma warning(disable : 4996)  


void matrixCat(detInt_t** matrix, detInt_t** newMatrix, int len, int row, int col) {
	int row_ = 0;
	int col_ = 0;
	for (int i = 0; i < len - 1; i++) {
		if (i == row) {
			row_ = 1;
		}
		col_ = 0;
		for (int j = 0; j < len - 1; j++) {
			if (j == col) {
				col_ = 1;
			}
			newMatrix[i][j] = matrix[i + row_][j + col_];
		}
	}
}

detInt_t determinant(detInt_t** matrix, int size) {
	static int n = 0;
	if (size == 10)
		std::cout << n++ << "\n";

	detInt_t det = 0;
	int step = 1;
	if (size == 1) {
		exit(-1);
	}
	if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	detInt_t** newMatrix = new detInt_t* [size - 1];
	for (int i = 0; i < size - 1; i++) {
		newMatrix[i] = new detInt_t[size - 1];
	}
	for (int j = 0; j < size; j++) {
		matrixCat(matrix, newMatrix, size, 0, j);
		det = det + (step * matrix[0][j] * determinant(newMatrix, size - 1));
		step = -step;
	}
	for (int i = 0; i < size - 1; i++) {
		delete[] newMatrix[i];
	}
	delete[] newMatrix;
	return det;
}