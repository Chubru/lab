// vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#pragma warning(disable : 4996)  
#define STEP 10000000
struct vbStr {
	int* dat;
	size_t size; 
	size_t capacity; 
};


void init(vbStr* head,int count) {
	if (count < STEP) {
		count = STEP;
	}
	head->dat = (int*)calloc(count, sizeof(int));
	head->size = 0;
	head->capacity = count;
	return;
}


void destroy(vbStr* head) {

	if (head->dat == NULL) {
		return;
	}
	free(head->dat);
	return;
}
//////////////////////////////////////////////////////////////////////////////////////

int push_back(vbStr* head, int value) {
	if (head->size > head->capacity) {
		head->dat = (int*)realloc(head->dat, (head->capacity + STEP)*sizeof(int));
		head->capacity += STEP;
		if (head->dat == NULL) {
			exit;
		}
	}
	head->dat[head->size]=value;
	head->size++;
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////

void print_(vbStr* head, int id) {
	if (id < 0 || id>head->size) {
		return;
	}
	printf("%d\n", head->dat[id]);
	return;

}
//////////////////////////////////////////////////////////////////////////////////////

void insert(vbStr* head, int id,int value) {
	if (id < 0 || id>head->size) {
		return;
	}
	if (head->size > head->capacity) {
		head->dat = (int*)realloc(head->dat, (head->capacity + STEP) * sizeof(int));
		head->capacity += STEP;
		if (head->dat == NULL) {
			exit;
		}
	}

	for (int i = head->size; i >= id;i--) {
		head->dat[i+1] = head->dat[i];
	}
	head->dat[id] = value;
	head->size++;
	return;

}

//////////////////////////////////////////////////////////////////////////////////////


void erase(vbStr* head, int id) {
	if (id < 0 || id>head->size) {
		return;
	}
	
	for (int i = id; i < head->size; i++) {
		head->dat[i] = head->dat[i + 1];
	}
	for (int i = 0; i < 100; i++) {
		print_(head, i);
	}
	head->size--;
	return;
}


//////////////////////////////////////////////////////////////////////////////////////

int main()
{
	vbStr* head = (vbStr*)malloc(sizeof(vbStr));
	init(head, 0);
	for (int i = 0; i < 100; i++) {
		push_back(head, i);
	}
	//insert(head, 0, 100);
	erase(head, 3);
	for (int i = 0; i < 100; i++) {
		print_(head, i);
	}
	destroy(head);
	return 0;
}


