// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Ctime.h"


int main()
{
    try {
		Ctime aa(1, 2, 3);
		aa++;
		++aa;
		aa = aa + 1;
		aa += 2;

	}
	catch (const char* error) {
		std::cout << error << std::endl;
	}
}
