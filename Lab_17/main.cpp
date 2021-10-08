#include <iostream>
#include <string>
#include "Cvector.h"

struct Spoint{
    int x;
    int y;
};

int main() {
    try {
        //Cvector<std::string>dat;
        //dat.pushBack("qqqq");
        //std::cout<<dat[0];
        Cvector<int> dat;
        //dat[-1]=0;
        for (int i = 0; i < 100; i++) {
            dat.pushBack(i);
        }
        //dat.erase(-1);


        Cvector<Spoint> pointList;
        Spoint p={1,2};
        pointList.pushBack(p);
        auto [x,y]=pointList[0];
        std::cout<<"x="<<x<<"y:"<<y;
    }
    catch (...){
        std::cout<<"invalid index";
    }
    return 0;
}
