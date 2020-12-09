#include<stdio.h>
#include <malloc.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
struct Spisok_slo {
	char* wb;
	bool out;
};

int checkLetter(char src) {
	if (('A' < src) && (src < 'Z')) {
		return 1;
	}
	if (('a' < src) && (src < 'z')) {
		return 1;
	}
	return 0;
}
int comparestr(const char* s1, const char* s2) {
	int i = 0;
	for (;; i++) {
		if (s1[i] != s2[i])
			break;
		if (s1[i] == 0)
			return 0;
	}
	return s1[i] > s2[i] ? 1 : -1;
}


int main() {
	char str[100000];
	Spisok_slo listVb[5000];
	int sizeListVb = 0;
	printf(" Vvedite stroku : ");
	fgets(str, sizeof(str), stdin);

	for (int i = 0; i < sizeof(str); i++) {
		if (checkLetter(str[i]) != 1) {
			str[i] = '\0';
		}
	}
	int st = 0;
	int countOut = 0;
	for (int i = 0; i < sizeof(str); i++) {
		if (checkLetter(str[i]) == 1) {
			if (st==0) {
				bool s = false;
				for (int z = 0; z < sizeListVb; z++) {
					if (comparestr(&str[i], listVb[z].wb) == 0) {
						if (listVb[z].out == false) {
							printf("%s\n", &str[i]);
							listVb[z].out = true;
							countOut++;
							s = true;
						}
						break;
					}
				}
				if (s == false) {
					listVb[sizeListVb].wb = &str[i];
					listVb[sizeListVb].out = false;
					sizeListVb++;
				}
				st = -1;
			}
		}
		else {
			st = 0;
		}
	}
	if (countOut == 0) {
		printf("the string does not contain duplicate elements\n ");

	}
	return 0;
}
