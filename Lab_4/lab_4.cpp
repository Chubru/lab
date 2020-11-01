#include <stdio.h>
#include <ctype.h>


//#pragma warning(disable : 4996)  

//#pragma warning(disable : 4996)  

int checkLetter(char d) {
	d = d | 0x20;
	switch (d)
	{
	case 'a':
	case 'e':
	case 'y':
	case 'u':
	case 'o':
	case 'i':
		return 2;
	}
	if ((d >= 'a') && (d <= 'z')) {
		return 1;
	}
	return 0;
}

struct vbStr {
	char* d;
	int kol;
};

int main() {
	vbStr vb[10000];
	char dat[10000];
	for (int i = 0;i < sizeof(dat);i++) {
		dat[i] = NULL;
	}
	for (int i = 0;i < sizeof(vb) / sizeof(vb[0]);i++) {
		vb[i].d = NULL;
		vb[i].kol = 0;
	}
	//scanf("%d",&len);
	printf("%s", "Enter string\n");

	//scanf("%100[0-9a-zA-Z ]", &dat);
	fgets(dat, sizeof(dat), stdin);


	//printf("%s %d\n", "Kol =", kol);
	bool  st = false;
	int count = 0;
	for (int i = 0;i < sizeof(dat);i++) {
		if (dat[i] == '\n') {
			dat[i] = NULL;
			break;
		}
		if (checkLetter(dat[i]) != 0) {
			if (st == false) {
				vb[count].d = &dat[i];
			}
			if (checkLetter(dat[i]) == 2) {
				vb[count].kol++;
			}
			st = true;

		}
		else {
			dat[i] = NULL;
			st = false;
			count++;
		}
	}
	st = false;
	for (int i=0;;i++) {

		if ((vb[i+1].d == NULL) && (vb[i+1].kol == 0)) {
			if (st == false) {
				break;
			}
			st = false;
			i = 0;
		}
		if (vb[i].kol > vb[i+1].kol) {
			st = true;
			vbStr tmp = vb[i];
			vb[i] = vb[i + 1];
			vb[i + 1] = tmp;
		}

	}
	for (int i = 0;;i++) {
		if ((vb[i].d == NULL) && (vb[i].kol == 0)) {
			break;
		}
		printf("%s\n", vb[i].d);
	}
	return 0;
}