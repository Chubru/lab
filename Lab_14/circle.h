#pragma once
#include "figure.h"
#include <iostream>
class circle :
    public figure
{
private:
    unsigned int r{ 0 };
    int x, y;
    const char* text{nullptr};
public:
    void print() {
        std::cout << "x = " << x << " y = " << y << " r = " << r;
        if (text != nullptr) {
            std::cout << " text - " << text << "\n";
        }
        else {
            std::cout << "\n";
        }
    }
    
    circle(int x_,int y_,int R, const  char* textPtr) 
        //: text (textPtr),  r(R)
    {
        x = x_;
        y = y_;
        r = R;
        text = textPtr;
    }
    void printxy();
};

