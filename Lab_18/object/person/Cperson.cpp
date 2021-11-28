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

void Cperson::save(std::ofstream& of)
{
    of.write((char*)&phone, sizeof(unsigned));
    unsigned lenName = name.size();
    of.write((char*)&lenName, sizeof(unsigned));
    of.write((char*)name.c_str(), name.size());
}

void Cperson::load(std::ifstream& inf){
    inf.read((char*)&phone,sizeof(unsigned));
    unsigned lenName=0;
    inf.read((char*)&lenName, sizeof(unsigned));
    name.resize(lenName );
    inf.read((char*)name.data(),lenName);
}