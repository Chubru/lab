//
// Created by chubr on 10/27/21.
//

#include "Cperson.h"
std::ostream& operator << (std::ostream& out,const Cperson& person){
    out<<""<<person.name<<":"<<person.phone;
    return out;
}

Cperson::Cperson(string str){
    auto it = std::find(str.begin(),str.end(),':');
    name = std::string (str.begin(),it);
    char* x=NULL;
    phone = std::strtoul(string(it,str.end()).c_str(), &x, 10);
}