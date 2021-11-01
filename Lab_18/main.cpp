#include <iostream>
#include <string>
#include "object/phoneBook/CphoneBook.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;
    CphoneBook phoneBook;
    //phoneBook.addContact("sdsd",666);
    //phoneBook.addContact("rrr",777);
    //phoneBook.addContact("gggg",888);
    //string hh="ggggeee";
    //std::cout<<phoneBook;
    //phoneBook.erase(hh);
    //std::cout<<phoneBook;
    //phoneBook.save("a.txt");
    phoneBook.load("a.txt");
    std::cout<<phoneBook;
    return 0;
}
