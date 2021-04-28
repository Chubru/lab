#include <iostream>
#include <cstdlib>

#pragma warning(disable : 4996) 
const int MAX_SIZE = 1000;
#define TYPE_FREE 1
#define TYPE_END  2


struct MCB {
	int size;
	int type;
	MCB* prev;
	MCB* next;
};
char* p = nullptr;

void print_(MCB* dat) {
	std::cout << "(" << dat->size - sizeof(MCB) << " " << (dat->type & TYPE_FREE ? " Free " : " bysy ") << " " << (dat->type & TYPE_END ? " End " : "") << ")   ";
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

	if (mcb->next->type & TYPE_FREE != 0) {
		mcb->size += mcb->next->size;
		mcb->type = mcb->next->type;
		if (mcb->next->next != NULL) {
			mcb->next->next->prev = mcb;
		}
		mcb->next = mcb->next->next;
	}

	if (mcb->prev != NULL) {
		if (mcb->prev->type & TYPE_FREE != 0) {
			mcb->prev->size += mcb->size;
			mcb->prev->type = mcb->type;
			if(mcb->next!=NULL)
				mcb->next->prev = mcb->prev;
			mcb->prev->next = mcb->next;
		}
	}
}

char* alloc_(unsigned int size) {
	size += sizeof(MCB);	
	for (MCB* mcb = (MCB*)p;p;mcb=mcb->next) {
		if (mcb->size >= size && mcb->type & TYPE_FREE) {
			MCB* newMcb = (MCB*)((char*)mcb + size);
			newMcb->type = mcb->type;
			mcb->type = 0;
			newMcb->next = mcb->next;
			mcb->next = newMcb;
			newMcb->size = mcb->size - size;
			mcb->size = size;
			newMcb->prev = mcb;		
			return (char*)mcb + sizeof(MCB);
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
	mcb->next = NULL;
}

void clean() {
	if (p) {
		free(p);
	}
}

int main()
{
	init();
	show();
	char* a = alloc_(10);
	show();
	char* b = alloc_(100);
	show();
	free_(a);
	show();
	char* c = alloc_(20);
	show();
	free_(b);
	show();
	free_(c);
	show();
	clean();
	return 0;
}