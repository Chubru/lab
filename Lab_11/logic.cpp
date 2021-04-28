#include <iostream>
#include <cstdlib>
#include "logic.h"


#pragma warning(disable : 4996) 

#define TYPE_FREE 1
#define TYPE_END  2

char* p = nullptr;

void print_(MCB* dat) {
	std::cout << "(" << dat->size - sizeof(MCB) << " " << (dat->type & TYPE_FREE ? " Free " : " not free ") << " " << (dat->type & TYPE_END ? " End " : "") << ")   ";
}

void show() {
	for (char* pp = p; pp != 0; ) {
		MCB* mcb = (MCB*)pp;
		print_(mcb);
		if (mcb->type & TYPE_END) {
			std::cout << "\n";
			return;
		}
		else {
			pp += mcb->size;
		}

	}

}

void free_(char* ptr) {
	MCB* mcb = (MCB*)(ptr - sizeof(MCB));
	mcb->type = TYPE_FREE;

	MCB* nextMcb = (MCB*)((char*)mcb + mcb->size);
	bool haveNext = false;
	if (nextMcb->type & TYPE_FREE != 0) {
		mcb->size += nextMcb->size;
		mcb->type = nextMcb->type;
		if (nextMcb->type & TYPE_END == 0) {
			MCB* next2Mcb = (MCB*)((char*)nextMcb + nextMcb->size);
			next2Mcb->prev = mcb;
			nextMcb = next2Mcb;
		}
	}


	if (mcb->prev) {
		MCB* prevMcb = mcb->prev;
		if (prevMcb->type & TYPE_FREE != 0) {
			prevMcb->size += mcb->size;
			prevMcb->type = mcb->type;
			nextMcb->prev = prevMcb;
		}

	}
}

char* alloc_(unsigned int size) {
	size += sizeof(MCB);
	for (char* pp = p; pp != 0; ) {
		MCB* mcb = (MCB*)pp;
		if (mcb->size >= size && mcb->type & TYPE_FREE) {
			MCB* newMcb = (MCB*)(pp + size);
			newMcb->type = mcb->type;
			newMcb->size = mcb->size - size;
			newMcb->prev = mcb;
			mcb->type = 0;
			mcb->size = size;

			return pp + sizeof(MCB);
		}
		else if (mcb->type & TYPE_END) {
			return NULL;
		}
		else {
			pp += mcb->size;
		}
	}
}

void init() {
	p = (char*)malloc(MAX_SIZE);
	if (p == NULL) {
		exit(1);
	}
	MCB* mcb = (MCB*)p;
	mcb->size = MAX_SIZE;
	mcb->type = TYPE_FREE | TYPE_END;
	mcb->prev = NULL;
}

void clean() {
	if (p) {
		free(p);
	}
}

