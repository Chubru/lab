#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

#pragma warning(disable : 4996)  

void ltoao1(long dat, char* s) {
	if (s) sprintf(s, "%08lx", dat);
}

long input() {
	long dat = 0;
	while (scanf("%d", &dat) == 0) {
		printf("wrong\n");
		fgetc(stdin);
	}
	return dat;
}
void output(char* str) {
	printf("%s", str);
}