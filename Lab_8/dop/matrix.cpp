#include "matrix.h"
#include <iostream>
#include <iomanip>

matrix::matrix() {
	std::cin >> m;//строки
	std::cin >> n;//столбцы
	matrix_p = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix_p[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> matrix_p[i][j];
		}
	}
}
matrix::~matrix() {
	for (int i = 0; i < n; i++) {
		delete[] matrix_p[i];
	}
	delete[] matrix_p;
}
void matrix::localExtremum() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << std::setw(5) << matrix_p[i][j];
		}
		std::cout << std::endl;
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (x > 0 && x < (n-1)) {
				if ((matrix_p[x - 1][y]<matrix_p[x][y] && matrix_p[x][y]>matrix_p[x + 1][y]) ||
					(matrix_p[x - 1][y] > matrix_p[x][y] && matrix_p[x][y] < matrix_p[x + 1][y])) {
					callBack(x, y,"y extremum", NULL);

				}

			}

			if (y > 0 && y < (m-1)) {
				if ((matrix_p[x][y - 1]<matrix_p[x][y] && matrix_p[x][y]>matrix_p[x][y + 1]) ||
					(matrix_p[x][y - 1] > matrix_p[x][y] && matrix_p[x][y] < matrix_p[x + 1][y])) {
					callBack(x, y,"x extremum", NULL);
				}
			}

		}
	}

}
void callBack(int x, int y, const char* massages, void* pt) {
	std::cout << massages << ": [" << x << ":" << y << "]\n";
	return;
}