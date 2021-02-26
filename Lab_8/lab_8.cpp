// lab_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "logic.h"
#include <stdio.h>




//int maxInLine(int(*dat)[N], int line) {

//


int main()
{
	int dat[N][M]{ {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	input(dat);
	logic(dat);
	
	//output(str);
	return 0;
}

