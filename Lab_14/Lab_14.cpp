// Lab_14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "circle.h"
#include "segment.h"
#include "figureList.h"
#include "figure.h"
#pragma warning(disable : 4996)		


void mainSelectionMenu(figureList& figure) {
	int pos = 0;
	for (;;) {
		system("cls");
		std::cout << "1 - add circle" << std::endl;
		std::cout << "2 - add segment" << std::endl;
		std::cout << "3 - delete element" << std::endl;
		std::cout << "4 - print" << std::endl;

		int characterCode = fgetc(stdin);
		switch (characterCode)
		{
		case '1':
		{
			int  x{-1}, y{ -1 }, r{ -1 };
			while (x < 0) {
				std::cout << "enter x" << std::endl;
				std::cin >> x;
			}
			while (y < 0) {
				std::cout << "enter y" << std::endl;
				std::cin >> y;
			}
			while (r < 0) {
				std::cout << "enter r" << std::endl;
				std::cin >> r;
			}
			figure.addItem(x, y, r, "");
			break;

		}
		case '2':
		{
			int  x1{ -1 }, y1{ -1 }, x2{ -1 }, y2{ -1 };
			while (x1 < 0) {
				std::cout << "enter x1" << std::endl;
				std::cin >> x1;
			}
			while (y1 < 0) {
				std::cout << "enter y1" << std::endl;
				std::cin >> y1;
			}
			while (x2 < 0) {
				std::cout << "enter x2" << std::endl;
				std::cin >> x2;
			}
			while (y2 < 0) {
				std::cout << "enter y2" << std::endl;
				std::cin >> y2;
			}
			figure.addItem(x1, y1, x2, y2);
			break;
		}
		case '3':
		{
			figure.printAll();
			std::cout << std::endl << std::endl << "enter id";
			int id{ -1 };
			while (id < 0) {
				std::cout << "enter id" << std::endl;
				std::cin >> id;
			}
			figure.erase(id);
		}
			break;
		case '4':
		{
			system("cls");
			figure.printxy();
			scanf("%*c%*c");
			break;
		}

		default:
			break;
		}

	}
}


int main()
{

	try {
		//circle aa(100, 20, 30, NULL);
		//aa.printxy();
		//circle bb{ 2,3, 4,NULL };
		// bb.print();
		 //aa.printAll();

		figureList qq;
		//char tt[] = "fff";
		mainSelectionMenu(qq);
		qq.addItem(1, 5, 30, "fdf");
		qq.addItem(2, 50, 40, "fsf");
		qq.addItem(3, 100, 50, NULL);
		qq.addItem(4, 2, 300, 400);
		qq.printxy();
		//std::cout << "\n\n\n";
		qq.erase(2);
		//std::cout << "\n\n\n";

		//qq.findFigure(2); 
		//segment seg(1, 1, 1000, 700);
		//seg.printxy();
		
	}
	catch (const char* error) {
		std::cout << error << std::endl;
	}
}
