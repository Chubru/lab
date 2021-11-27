#include <iostream>
#include <string>
#include "object/phoneBook/CphoneBook.h"

int main() {
    CphoneBook phoneBook;
    phoneBook.addContact("sdsd",666);
    phoneBook.addContact("rrr",777);

    phoneBook.save("a.txt");
    phoneBook.load("a.txt");

    phoneBook.erase(777);

    std::cout<<phoneBook;

    //phoneBook.addContact("gggg",888);
    //string hh="ggggeee";
    //std::cout<<phoneBook;
    //phoneBook.erase(hh);
    //std::cout<<phoneBook;
    //phoneBook.save("a.txt");
    //phoneBook.load("a.txt");
    //std::cout<<phoneBook;
    return 0;
}
