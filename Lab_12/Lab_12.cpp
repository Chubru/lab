// Lab_12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Rational.h"
int main()
{
	try {
		Rational a;
		Rational b(3,5);
		//int fff = 5;
		Rational z = 5 + b;
		//b = (Rational)5 + a;
		//std::cin >> a >> b;
		//std::cout << a / b;
		std::cout << a / b;
	}
	catch (const char* error) {
		std::cout << error << std::endl;
	}
}
