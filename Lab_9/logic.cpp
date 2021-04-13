#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

#pragma warning(disable : 4996)  


void matrixCat(int** matrix, int** newMatrix, int len, int row, int col) {
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

int determinant(int** matrix, int size) {
	int det = 0;
	int step = 1;
	if (size == 1) {
		exit(-1);
	}
	if (size == 2) {
		return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	}
	int** newMatrix = new int* [size - 1];
	for (int i = 0; i < size - 1; i++) {
		newMatrix[i] = new int[size - 1];
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