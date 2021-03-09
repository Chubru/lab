// Lab_12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Rational.h"
int main()
{
	try {
		Rational a,b;
		std::cin >> a >> b;
		std::cout << a / b;


	}
	catch (const char* error) {
		std::cout << error << std::endl;
	}
}
