//
// Created by chubr on 10/27/21.
//

#include "CphoneBook.h"



std::ostream& operator << (std::ostream& out,const CphoneBook& phoneBook){
    for(auto p : phoneBook) {
        out<<p<< std::endl;
    }
    return out;
}


bool CphoneBook::load(const std::string& filename){
    std::ifstream inf(filename);
    if (!inf)
        return false;
    clear();
    std::string tmp;
    while(std::getline(inf,tmp)){
        push_back(Cperson(tmp));
    }
    return true;
}

bool CphoneBook::save(const std::string& filename) {
    std::ofstream outf(filename);
    if (!outf)
        return false;
    outf << *this;
    return true;
}

void CphoneBook::erase(unsigned phone){
    auto it = phoneFind(phone);
    if(it!=end())
        std::list<Cperson>::erase(it);
    return ;
}

void CphoneBook::erase(std::string& name){
    auto it = nameFind(name);
    if(it!=end())
        std::list<Cperson>::erase(it);
    return ;
}

bool CphoneBook::addContact(std::string name,unsigned phone){
    auto it = nameFind(name);
    if(it == end()) {
        insert(end(), Cperson(name, phone));
        return true;
    }
    else{
        return false;
    }
}


void CphoneBook::saveB(std::ofstream& of){
    unsigned len = size();
    of.write((char*)&len, sizeof(unsigned));
    for(auto tmp:*this){
        tmp.save(of);
    }
}

void CphoneBook::loadB(std::ifstream& inf){
    unsigned count = 0;
    inf.read((char*)&count,sizeof(unsigned));
    for(int i = 0; i < count; i++){
        Cperson tmp ;
        tmp.load(inf);
        insert(end(), tmp);
    }
}
