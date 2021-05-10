// Lab_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "circle.h"
#include "figureList.h"
#include "figure.h"

int main()
{
	try {
		std::cout << "Hello World!\n";
		circle aa(1, 2, 3, NULL);
		circle bb{ 2,3, 4,NULL };
		// bb.print();
		 //aa.printAll();

		figureList qq;
		char tt[] = "fff";
		qq.addItem(1, 5, 3, "fdf");
		qq.addItem(2, 5, 4, NULL);
		qq.addItem(3, 5, 5, NULL);
		qq.addItem(4, 2, 3, 4);
		qq.printAll();
		std::cout << "\n\n\n";
		qq.erase(4);
		qq.printAll();
		qq.findFigure(2); ///////////////////////////?????????????????????????
	}
	catch (const char* error) {
		std::cout << error << std::endl;
	}
}
