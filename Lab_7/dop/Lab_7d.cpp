// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "logic.h"


#pragma warning(disable : 4996)  
int main()
{
    char str[1000];
    char* end = NULL;
    int base;
    while (scanf("%d", &base) == 0) {
        printf("wrong\n");
        scanf("%*s");
    }
    std::cout << "str\n";
    std::cin >> str;
  //  std::cout << strtoll(str, &end, base)<<"  ";
  //  std::cout << end << "\n" << std::endl;

    std::cout << strtoll1(str, &end, base)<<"  ";
    if (end)
        std::cout << end << "\n";


        return 0;
}