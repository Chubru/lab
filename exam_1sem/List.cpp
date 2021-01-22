// List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#pragma warning(disable : 4996)  

struct vbStr {
	int dat;
	vbStr* nextStr;
	vbStr* previousStr;
};

struct vbStrHead {
	vbStr* firstItem;
	vbStr* lastItem;
};

//////////////////////////////////////////////////////////////////////////////10.1
void destroyVbStr(vbStr* item) {
	if (item != NULL) {
		destroyVbStr(item->nextStr);
		free(item);
	}
	return;
}
void destroy(vbStrHead* head) {
	destroyVbStr(head->firstItem);
	free(head);
	return;
}

vbStrHead* init() {
	vbStrHead* head = (vbStrHead*)malloc(sizeof(vbStrHead));
	if (head == NULL) {
		exit;
	}
	head->firstItem = NULL;
	head->lastItem = NULL;
	return head;
}
//////////////////////////////////////////////////////////////////////////////10.2

void push_back(vbStrHead* head ,int value) {
	vbStr* str = (vbStr*)malloc(sizeof(vbStr));
	if (str == NULL) {
		exit;
	}

	str->previousStr = NULL;
	str->nextStr = NULL;
	str->dat = value;

	if (head->firstItem == NULL) {
		head->firstItem = str;
	}
	if (head->lastItem != NULL) {
		str->previousStr = head->lastItem;
		head->lastItem->nextStr = str;
		head->lastItem = str;
	}
	head->lastItem = str;
	return;
}


//////////////////////////////////////////////////////////////////////////////10.3

int set(vbStrHead* head, int value,int id) {
	vbStr* str=head->firstItem;
	for (int i = 1; i < id; i++) {
		if (str->nextStr == NULL) {
			return -1;
		}
		str = str->nextStr;
	}
	str->dat = value;
	return 0;
}

int insert(vbStrHead* head, int value, int id) {
	vbStr* str = head->firstItem;
	for (int i = 1; i < id; i++) {
		if (str->nextStr == NULL) {
			return -1;
		}
		str = str->nextStr;
	}
	
	vbStr* strN = (vbStr*)malloc(sizeof(vbStr));
	if (strN == NULL) {
		exit;
	}

	strN->dat = value;
	strN->nextStr = str;
	strN->previousStr = str->previousStr;


	str->previousStr = strN;

	strN->previousStr->nextStr = strN;
	
	return 0;
}
//////////////////////////////////////////////////////////////////////////////10.4
int get(vbStrHead* head, int id) {
	vbStr* str = head->firstItem;
	for (int i = 1; i < id; i++) {
		if (str->nextStr == NULL) {
			return -1;
		}
		str = str->nextStr;
	}
	return str->dat;
}

int erase(vbStrHead* head, int value, int id) {
	vbStr* str = head->firstItem;
	for (int i = 1; i < id; i++) {
		if (str->nextStr == NULL) {
			return -1;
		}
		str = str->nextStr;
	}


	str->nextStr->previousStr = str->previousStr;
	str->previousStr->nextStr = str->nextStr;
	free(str);
	return 0;
}
//////////////////////////////////////////////////////////////////////////////10.5
int main()
{
	vbStrHead* head = init();
	push_back(head, 55);
	push_back(head, 66);
	push_back(head, 77);
	int dat=get(head, 5);
	set(head, 33, 6);
	insert(head, 22, 6);
	destroy(head);
	return 0;
}
