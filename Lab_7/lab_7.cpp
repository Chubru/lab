﻿// lab_7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "logic.h"


int main()
{
	char str[20]="";
	long dat = input();
	//ltoao2(dat, &str[0]);
	ltoao3(dat, &str[0]);
	output(str);
	return 0;
}

