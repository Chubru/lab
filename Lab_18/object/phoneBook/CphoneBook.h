//
// Created by chubr on 10/27/21.
//

#ifndef LAB_18_CPHONEBOOK_H
#define LAB_18_CPHONEBOOK_H

#include <algorithm>
#include <list>
#include <iostream>
#include <string>
#include <fstream>

//#include <ranges>

#include "../person/Cperson.h"

class CphoneBook : std::list<Cperson>{
    friend std::ostream& operator << (std::ostream& out,const CphoneBook& phoneBook);
private:
    auto phoneFind(unsigned phone){
        auto it = std::find_if(begin(),end(),[& phone](Cperson p){
            return p.phone == phone;
        });
        return it;
    }
    auto nameFind(string name){
        auto it = std::find_if(begin(),end(),[& name](Cperson p){
            return p.name == name;
        });
        return it;
    }
public:
    bool addContact(std::string name,unsigned phone);

    std::string find(unsigned phone){
        return phoneFind(phone)->name;
    }

    unsigned find(const std::string& name){
        return nameFind(name)->phone;
    }

    void erase(std::string& name);
    void erase(unsigned phone);
    bool save(const std::string& filename);

    bool load(const std::string& filename);

    void saveB(std::ofstream& of);
    void loadB(std::ifstream& inf);

};
#endif //LAB_18_CPHONEBOOK_H
