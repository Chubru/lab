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
	vbStr* nextStr;
	int len;
};

struct vbStrHead {
	vbStr* firstItem;
	vbStr* lastItem;
};




vbStrHead* insertVb(vbStrHead* vbHead, char* str, int len, int startPos) {
	if (len < 0) {
		exit;
	}
	char* str_ = (char*)malloc((sizeof(char))*len + 1);
	for (int i = 0, k = startPos; i < len; i++, k++) {
		str_[i] = str[k];
	}
	str_[len] = '\0';

	vbStr* vbListNew = (vbStr*)malloc(sizeof(vbStr));
	if (vbListNew == NULL) {
		exit;
	}
	vbListNew->vb = str_;
	vbListNew->len = len;
	vbListNew->nextStr = NULL;

	if (vbHead->lastItem == NULL) {
		vbHead->lastItem = vbListNew;
		vbHead->firstItem = vbListNew;
	}
	else {
		vbHead->lastItem->nextStr = vbListNew;
		vbHead->lastItem = vbListNew;
	}

	return vbHead;
}


int initVbStr(char* fileName, vbStrHead* vbHead) {
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
	for (int i = 0; i < kol + 1; i++) {
		if (checkLetter(str[i]) == 1) {
			len++;
		}
		else {
			if (len > 0) {
				vbHead = insertVb(vbHead, str, len, i - len);
			}
			p = true;
			len = 0;
		}
	}
	free(str);
	return 0;
}



int merge(vbStrHead* vbHeadList1, vbStrHead* vbHeadList2, vbStrHead* vbHeadKonList) {
	vbStr* vbList1 = vbHeadList1->firstItem;
	vbStr* vbList2 = vbHeadList2->firstItem;

	for (;;) {
		if (comparestr(vbList1->vb, vbList2->vb) == -1) {
			vbHeadKonList = insertVb(vbHeadKonList, vbList1->vb, vbList1->len, 0);
			vbList1 = vbList1->nextStr;
		}
		else {
			vbHeadKonList = insertVb(vbHeadKonList, vbList2->vb, vbList2->len, 0);
			vbList2 = vbList2->nextStr;

		}
		if ((vbList2  == NULL) || (vbList1 == NULL)) {
			break;
		}
	}
	for (; vbList2 != NULL;) {
		vbHeadKonList = insertVb(vbHeadKonList, vbList2->vb, vbList2->len, 0);
		vbList2 = vbList2->nextStr;
	}
	for (; vbList1 != NULL;) {
		vbHeadKonList = insertVb(vbHeadKonList, vbList1->vb, vbList1->len, 0);
		vbList1 = vbList1->nextStr;
	}

	return 0;
}

int out(vbStrHead* vbHeadKonList) {
	vbStr* vbList = vbHeadKonList->firstItem;
	for (; vbList->nextStr!=NULL;) {
		printf("%s\n", vbList->vb);
		vbList = vbList->nextStr;
	}
	return 0;
}
int delVbStr(vbStr* vbList) {
	if (vbList->nextStr != NULL) {
		delVbStr(vbList->nextStr);
	}
	free(vbList->vb);
	free(vbList);
	return 0;
}
int main() {
	vbStrHead* vbHeadList1 = (vbStrHead*)malloc(sizeof(vbStrHead));
	vbHeadList1->lastItem = NULL;
	char f1[] = "1.txt";
	initVbStr(f1, vbHeadList1);

	vbStrHead* vbHeadList2 = (vbStrHead*)malloc(sizeof(vbStrHead));
	vbHeadList2->lastItem = NULL;

	char f2[] = "2.txt";
	initVbStr(f2, vbHeadList2);


	
	vbStrHead* mergeHeadList = (vbStrHead*)malloc(sizeof(vbStrHead));
	mergeHeadList->lastItem = NULL;

	merge(vbHeadList1, vbHeadList2, mergeHeadList);
	out(mergeHeadList);

	delVbStr(vbHeadList1->firstItem);
	delVbStr(vbHeadList2->firstItem);
	delVbStr(mergeHeadList->firstItem);
	free(vbHeadList1);
	free(vbHeadList2);
	free(mergeHeadList);

	return 0;
}
