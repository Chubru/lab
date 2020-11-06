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



int main() {
	char vb[1000];
	for (int i = 0;i < sizeof(vb);i++) {
		vb[i] = NULL;
	}
	printf("%s", "Enter word\n");
	//scanf("%s",&vb);
	fgets(vb, sizeof(vb), stdin);
	int len = 0;
	for (int i = 0;i < sizeof(vb);i++) {
		//if (vb[i] == '\n') {
		//	break;
		//}
		if (checkLetter(vb[i]) != 0) {
			len++;
		}
		else {
			break;
		}
	}
	char str[10000];
	for (int i = 0;i < sizeof(str);i++) {
		str[i] = NULL;
	}


	//scanf("%100[0-9a-zA-Z ]", &dat);
	fgets(str, sizeof(str), stdin);
	int kol = 0;
	int lg = 0;
	for (int i = 0; i < sizeof(str);i++) {
		if (str[i] == '\n') {
			break;
		}
		if (checkLetter (str[i]) != 0) {
			lg++;
		}
		else {
			if ((lg != 0)&&(lg==len)) {
				kol++;
			}
			lg = 0;
		}
	}
	printf("\n%d",kol);

	return 0;
}