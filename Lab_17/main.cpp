#include <iostream>
#include <string>
#include "Cvector.h"

int main() {
   // std::cout << "Hello, World!" << std::endl;
    //Cvector<std::string>dat;
    //dat.pushBack("qqqq");
    //std::cout<<dat[0];
    Cvector<int>dat;
    for(int i=0;i<INT32_MAX;i++){
        dat.pushBack(i);
    }
    return 0;
}
