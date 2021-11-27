#include <iostream>
#include <string>
#include "Cvector.h"

struct Spoint{
    int x;
    int y;
};

Cvector<Spoint> genPointList (){
    Cvector<Spoint> pl;
    pl.pushBack(Spoint{3,5});
    pl.pushBack(Spoint{4,6});
    return pl;
}
int main() {
    try {
        //Cvector<std::string>dat;
        //dat.pushBack("qqqq");
        //std::cout<<dat[0];
        Cvector<Cvector <int>>dat;
        //dat[-1]=0;
        for (int ii=0; ii<15;++ii){
            Cvector <int> d;
            for (int i = 0; i < 12; i++) {
                d.pushBack(i+ii);
            }
            dat.pushBack(d);
        }
        for (int ii=0; ii<15;++ii){
            for (int i = 0; i < 12; i++) {
                std::cout<<dat[ii][i]<<" ";
            }
            std::cout<<std::endl;
        }
        //dat.erase(-1);


        Cvector<Spoint> pointList;
        Spoint p={1,2};
        pointList.pushBack(p);
        auto [x,y]=pointList[0];
        std::cout<<"x="<<x<<"y:"<<y;

        pointList = genPointList();
        Spoint pnt = pointList[0];
        std::cout<<"x="<<pnt.x<<"y:"<<pnt.y;



        Cvector<int>dat1;
        for(int i = 0;i < 10;i++){
            dat1.pushBack(i);
        }
        for(int i = 0;i < 10;i++){
            std::cout<<dat1[i]<<std::endl;
        }

    }
    catch (...){
        std::cout<<"invalid index";
    }
    return 0;
}
