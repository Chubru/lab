
#include <iostream>
#include <cstdlib>
#include "logic.h"
#pragma warning(disable : 4996) 




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
