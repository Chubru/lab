// Lab.cpp: определяет точку входа для консольного приложения.
//


#include <stdio.h>
#include "pch.h"





#pragma warning(disable : 4996)  





inline  int checkLetter(char d) {
	if ((d >= 'A') && (d <= 'Z')) {
		return 2;
	}

	if ((d >= 'a') && (d <= 'z')) {
		return 1;
	}
	return 0;
}


