#include <stdio.h>
#include <stdlib.h>
#include "logic.h"

#pragma warning(disable : 4996)  

void ltoao1(long dat, char* s) {
	if (s) sprintf(s, "%08lx", dat);
}

void ltoao2(long dat, char* s) {
	if (s) {
		for (int i = 0; i < 8; i++) {
			s[i] = ' ';
		}
		s[8] = '\0';
		for (int i = 7; i >= 0 ; i--) {
			s[i] = dat & 0xf;
			dat >>= 4;
			if (s[i] <= 9) {
				s[i] += '0';
			}
			else {
				s[i] += 'A' - 10;
			}
		}
	}
}

long input() {
	long dat = 0;
	int yy[3];

	while (scanf("%d", &dat) == 0) {
		printf("wrong\n");
		fgetc(stdin);
	}
	return dat;
}
void output(char* str) {
	printf("%s", str);
}