#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

#pragma warning(disable : 4996)  

int maxInLine(int dat[][N], int line) {
	int max = dat[line][0];
	for (int i = 1; i < N; i++) {
		if (max < dat[line][i]) {
			max = dat[line][i];
		}
	}
	return max;
}
int minIncolumn(int(*dat)[N], int column) {
	int min = dat[0][column];
	for (int i = 1; i < N; i++) {
		if (min > dat[i][column]) {
			min = dat[i][column];
		}
	}
	return min;
}
//
int minInLine(int(*dat)[N], int line) {
	int min = dat[line][0];
	for (int i = 1; i < N; i++) {
		if (min > dat[line][i]) {
			min = dat[line][i];
		}
	}
	return min;
}
int maxIncolumn(int(*dat)[N], int column) {
	int max = dat[0][column];
	for (int i = 1; i < N; i++) {
		if (max < dat[i][column]) {
			max = dat[i][column];
		}
	}
	return max;
}

void output(int i, int j) {
	printf("[%d,%d]\n", i, j);
}

void input(int(*dat)[N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("enter [%d,%d]\n", i, j);
			while (scanf("%d", &dat[i][j]) == 0) {
				printf("wrong\n");
				fgetc(stdin);
			}
		}
	}
}


void logic(int(*dat)[N]) {
	int minColumn[N];
	int maxColumn[N];
	for (int i = 0; i < N; i++) {
		minColumn[i] = minIncolumn(dat, i);
		maxColumn[i] = maxIncolumn(dat, i);
	}


	for (int i = 0; i < M; i++) {//строки
		int maxline = maxInLine(dat, i);
		int minline = minInLine(dat, i);
		for (int j = 0; j < N; j++) {//столбцы
			if (maxline == minColumn[j]) {
				output(i+1, j+1);
			}
			if (minline == maxColumn[j]) {
				output(i+1, j+1);
			}
		}

	}

	return;
}




