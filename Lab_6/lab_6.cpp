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
	char* vb;
	vbStr* nextVbStr;
};

struct vbStrMerge {
	vbStr* vb;
	vbStrMerge* vbNextMerge;
};

int initVbStr(char* fileName, vbStr* vbStruct) {
	FILE* h;
	h = fopen(fileName, "rt");
	if (h == NULL) {
		return -1;
	}
	fseek(h, 0, SEEK_END);
	int len = ftell(h);
	fseek(h, 0, SEEK_SET);
	char* str = (char*)malloc(sizeof(char) * (len + 2));
	int kol = fread(str, sizeof(char), len, h);
	if (kol > -1) {
		str[kol] = '\0';
	}
	fclose(h);
	len = 0;
	bool p = false;
	int beginword = 0;
	for (int i = 0; i < kol+1 ; i++) {
		if (checkLetter(str[i]) == 1) {
			if (p == true) {
				beginword = i;
				vbStr* vbTmp = (vbStr*)malloc(sizeof(vbStr));
				if (vbTmp == NULL) {
					return -1;
				}
				vbTmp->nextVbStr = NULL;
				vbStruct->nextVbStr = vbTmp;
				vbStruct = vbTmp;
				vbStruct->vb=NULL;
				p = false;
			}
			len++;
		}
		else {
			if (len > 0) {
				vbStruct->vb = (char*)malloc(sizeof(char) * (len+1));
				if (vbStruct->vb == NULL) {
					return -1;
				}
				for (int z = beginword, k = 0; k<len; z++, k++) {
					vbStruct->vb[k] = str[z];
				}
				vbStruct->vb[len] = '\0';
			}
			p = true;
			len = 0;
		}
	}
	free(str);
	return 0;
}


vbStrMerge* insertVbKonList(vbStrMerge* vbKonList) {
	vbStrMerge* vbTmp = (vbStrMerge*)malloc(sizeof(vbStrMerge));
	if (vbTmp == NULL) {
		exit(-1);
	}
	vbTmp->vb = NULL;
	vbTmp->vbNextMerge = NULL;
	return  vbTmp;
}


int merge(vbStr* vbList1, vbStr* vbList2, vbStrMerge* vbKonList) {
	for (;;) {
		if (comparestr(vbList1->vb, vbList2->vb) == -1) {
			vbKonList->vb = vbList1;
			vbKonList->vbNextMerge = insertVbKonList(vbKonList);
			vbKonList = vbKonList->vbNextMerge;
			vbList1 = vbList1->nextVbStr;
		}
		else {
			vbKonList->vb = vbList2;
			vbKonList->vbNextMerge = insertVbKonList(vbKonList);
			vbKonList = vbKonList->vbNextMerge;
			vbList2 = vbList2->nextVbStr;
		}
		if ((vbList2 == NULL) || (vbList1 == NULL)) {
			break;
		}
	}
	for (;;) {
		vbKonList->vb = vbList2;
		vbKonList->vbNextMerge = insertVbKonList(vbKonList);
		vbKonList = vbKonList->vbNextMerge;
		if (vbList2 == NULL) {
			break;
		}
		vbList2 = vbList2->nextVbStr;

	}
	for (;;) {
		vbKonList->vb = vbList1;
		vbKonList->vbNextMerge = insertVbKonList(vbKonList);
		vbKonList = vbKonList->vbNextMerge;
		if (vbList1 == NULL) {
			break;
		}
		vbList1 = vbList1->nextVbStr;
	}

	return 0;
}


int out(vbStrMerge* vbKonList) {
	for (;;) {
		if ((vbKonList->vb != NULL)&&(vbKonList->vb->vb != NULL)){
			printf("%s\n", vbKonList->vb->vb);
		}
		if (vbKonList->vbNextMerge == NULL) {
			break;
		}
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


	vbStr* vbList1 = (vbStr*)malloc(sizeof(vbStr));
	if (vbList1 == NULL) {
		return -1;
	}
	char f1[] = "1.txt";
	initVbStr(f1, vbList1);

	vbStr* vbList2 = (vbStr*)malloc(sizeof(vbStr));
	if (vbList2 == NULL) {
		return -1;
	}
	char f2[] = "2.txt";
	initVbStr(f2, vbList2);


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