#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#pragma warning(disable : 4996)  

//#pragma warning(disable : 4996)  

int checkLetter(char d) {
	d = d | 0x20;
	if ((d >= 'a') && (d <= 'z')) {
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
	if (s1[i] > s2[i]) {
		return 1;
	}
	else {
		return -1;
	}
}

struct vbStr {
	char vb[1000];
	vbStr* nextVbStr;

};
struct vbStrMerge {
	vbStr* vb;
	vbStrMerge* vbNextMerge;

};
int initVbStr(int fileCod, vbStr* vbStruct) {
	FILE* h;
	if (fileCod == 1) {
		h = fopen("1.txt", "rt");
	}
	else {
		h = fopen("2.txt", "rt");
	}
	if (h == NULL) {
		return -1;
	}
	fseek(h, 0, SEEK_END);
	int len = ftell(h);
	fseek(h, 0, SEEK_SET);
	char str[100000];
	for (int i = 0; i < sizeof(str); i++) {
		str[i] = '\0';
	}
	fread(str, 1, len, h);
	fclose(h);

	int pos = 0;
	bool p = false;

	for (int i = 0; i < sizeof(str); i++) {
		if (checkLetter(str[i]) == 1) {
			if (p == true) {
				vbStr* vbTmp = (vbStr*)malloc(sizeof(vbStr));
				if (vbTmp == NULL) {
					return -1;
				}
				vbTmp->nextVbStr = NULL;
				for (int z = 0; z < 1000; z++) {
					vbTmp->vb[z] = '\0';
				}
				vbStruct->nextVbStr = vbTmp;
				vbStruct = vbTmp;
				p = false;
			}
			vbStruct->vb[pos] = str[i];
			pos++;
		}
		else {
			p = true;
			pos = 0;
		}
	}
	return 0;
}

int merge(vbStr* vbList1, vbStr* vbList2, vbStrMerge* vbKonList) {
	for (;;) {
		if (comparestr(vbList1->vb, vbList2->vb) == -1) {
			vbKonList->vb = vbList1;
			vbStrMerge* vbTmp = (vbStrMerge*)malloc(sizeof(vbStrMerge));
			if (vbTmp == NULL) {
				return -1;
			}
			vbTmp->vbNextMerge = NULL;
			vbKonList->vbNextMerge = vbTmp;
			vbKonList = vbTmp;
			vbList1 = vbList1->nextVbStr;
		}
		else {
			vbKonList->vb = vbList2;
			vbStrMerge* vbTmp = (vbStrMerge*)malloc(sizeof(vbStrMerge));
			if (vbTmp == NULL) {
				return -1;
			}
			vbTmp->vbNextMerge = NULL;
			vbKonList->vbNextMerge = vbTmp;
			vbKonList = vbTmp;
			vbList2 = vbList2->nextVbStr;
		}
		if ((vbList2 == NULL) || (vbList1 == NULL)) {
			break;
		}
	}
	for (;;) {
		if (vbList2 == NULL) {
			break;
		}
		vbKonList->vb = vbList2;
		vbStrMerge* vbTmp = (vbStrMerge*)malloc(sizeof(vbStrMerge));
		if (vbTmp == NULL) {
			return -1;
		}
		vbTmp->vbNextMerge = NULL;
		vbKonList->vbNextMerge = vbTmp;
		vbKonList = vbTmp;
		vbList2 = vbList2->nextVbStr;

	}
	for (;;) {
		if (vbList1 == NULL) {
			break;
		}
		vbKonList->vb = vbList1;
		vbStrMerge* vbTmp = (vbStrMerge*)malloc(sizeof(vbStrMerge));
		if (vbTmp == NULL) {
			return -1;
		}
		vbTmp->vbNextMerge = NULL;
		vbKonList->vbNextMerge = vbTmp;
		vbKonList = vbTmp;
		vbList1 = vbList1->nextVbStr;

	}

	return 0;
}


int out(vbStrMerge* vbKonList) {
	for (;;) {
		if (vbKonList->vbNextMerge == NULL) {
			break;
		}
		printf("%s\n", vbKonList->vb->vb);
		vbKonList = vbKonList->vbNextMerge;
	}
	return 0;
}
int delVbStrMerge(vbStrMerge* vbKonList) {
	if (vbKonList->vbNextMerge != NULL) {
		delVbStrMerge(vbKonList->vbNextMerge);
	}
	free(vbKonList);
	return 0;

}
int delVbStr(vbStr* vbList) {
	if (vbList->nextVbStr != NULL) {
		delVbStr(vbList->nextVbStr);
	}
	free(vbList);
	return 0;

}
int main() {

	//str1[len] = '\0';
	//vbStr* vbStr1 = (vbStr*)malloc(len / 2 * sizeof(vbStr));

	//initVbStr(str1, len, vbStr1, len / 2);

	//char dat[10000];
	//for (int i = 0;i < sizeof(dat);i++) {
	//	dat[i] = NULL;
	//}
	//for (int i = 0;i < sizeof(vb) / sizeof(vb[0]);i++) {
	//	vb[i].d = NULL;
	//}
	////scanf("%d",&len);
	//printf("%s", "Enter string\n");

	////scanf("%100[0-9a-zA-Z ]", &dat);
	//fgets(dat, sizeof(dat), stdin);


	vbStr* vbList1 = (vbStr*)malloc(sizeof(vbStr));
	if (vbList1 == NULL) {
		return -1;
	}
	for (int z = 0; z < 1000; z++) {
		vbList1->vb[z] = '\0';
	}

	initVbStr(1, vbList1);

	vbStr* vbList2 = (vbStr*)malloc(sizeof(vbStr));
	if (vbList2 == NULL) {
		return -1;
	}
	for (int z = 0; z < 1000; z++) {
		vbList2->vb[z] = '\0';
	}
	initVbStr(2, vbList2);


	vbStrMerge* mergeList = (vbStrMerge*)malloc(sizeof(vbStrMerge));
	if (mergeList == NULL) {
		return -1;
	}

	merge(vbList1, vbList2, mergeList);
	out(mergeList);
	delVbStrMerge(mergeList);
	delVbStr(vbList1);
	delVbStr(vbList2);


	return 0;
}