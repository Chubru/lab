#pragma once
#ifndef LOGIC_H
#define LOGIC_H

struct MCB {
	int size;
	int type;
	MCB* prev;
};

const int MAX_SIZE = 1000;



void show();
void free_(char* ptr);
char* alloc_(unsigned int size);
void init();
void clean();
void print_(MCB* dat);
#endif // !LOGIC_H

