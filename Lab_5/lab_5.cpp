#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#pragma warning(disable : 4996)  

//#pragma warning(disable : 4996)  
using namespace std;
int checkLetter(char d) {
	d = d | 0x20;
	if ((d >= 'a') && (d <= 'z')) {
		return 1;
	}
	return 0;
}


int worldLen(char* str, int len) {
	int lenV = 0;
	for (int i = 0; i < len; i++) {
		if (checkLetter(str[i]) != 0) {
			lenV++;
		}
		else {
			break;
		}
	}
	return lenV;
}

int wordCounter(char* str, int len, int wantLen) {
	int kol = 0;
	int lg = 0;
	for (int i = 0; i < len; i++) {
		if (checkLetter(str[i]) != 0) {
			lg++;
		}
		else {
			if ((lg != 0) && (lg == wantLen)) {
				kol++;
			}
			lg = 0;
		}
		if (str[i] == '\n') {
			break;
		}
	}
	return kol;
}
int main() {
	int lenW = 0;
	for (;;) {
		printf("%s", "Enter len string\n");
		

		char tmp[10000];
		fgets(tmp, sizeof(tmp), stdin);
		int n = sscanf(tmp, "%d", &lenW);
		if ((n != 1) || (lenW < 2) || (lenW > 1000000)) {
			continue;
		}
		break;
	}
	char* vb = (char*)malloc(lenW * sizeof(char));

	for (int i = 0; i < lenW; i++) {
		vb[i] = NULL;
	}
	printf("%s", "Enter word\n");
	//scanf("%s",&vb);
	fgets(vb, lenW, stdin);
	int wantLenWords = worldLen(vb, lenW);

	char* str = (char*)malloc(lenW * sizeof(char));
	for (int i = 0; i < lenW; i++) {
		str[i] = NULL;
	}


	//scanf("%100[0-9a-zA-Z ]", &dat);
	printf("%s", "Enter string\n");

	fgets(str, lenW, stdin);

	printf("\n%d", wordCounter(str, lenW, wantLenWords));
	free(str);
	free(vb);
	return 0;
}