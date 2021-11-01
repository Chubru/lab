//
// Created by chubr on 10/27/21.
//

#ifndef LAB_18_CPERSON_H
#define LAB_18_CPERSON_H

#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using string = std::string;

class Cperson {
    friend class CphoneBook;
    string name;
    unsigned phone;
public:
    Cperson(string name_,unsigned phone_) : name(name_) , phone(phone_){};
    Cperson(string str);
    string getName(){return name;}
    unsigned getPhone(){return phone;}
    friend std::ostream& operator << (std::ostream& out,const Cperson& person);
};


#endif //LAB_18_CPERSON_H
