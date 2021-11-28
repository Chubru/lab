#include <iostream>
#include <string>
#include "object/phoneBook/CphoneBook.h"
#include "object/person/Cperson.h"


#include <stdlib.h>
#include <fstream>


int main() {
    CphoneBook phoneBook;
    phoneBook.addContact("sdsd",666);
    phoneBook.addContact("rrr",777);

   // phoneBook.save("a.txt");
   // phoneBook.load("a.txt");
    std::ofstream myfile;
    myfile.open("silly.dat", std::ios::binary | std::ios::out);

    phoneBook.saveB(myfile);
    //phoneBook.erase(777);



    std::cout<<phoneBook;

    myfile.close();
    CphoneBook test_;
    std::ifstream file_;
    file_.open("silly.dat", std::ios::in | std::ios::binary);
    test_.loadB(file_);
    std::cout<<test_;


    //phoneBook.addContact("gggg",888);
    //string hh="ggggeee";
    //std::cout<<phoneBook;
    //phoneBook.erase(hh);
    //std::cout<<phoneBook;
    //phoneBook.save("a.txt");
    //phoneBook.load("a.txt");
    //std::cout<<phoneBook;
    //Cperson test("asasa",3801434);
   // std::cout<<std::endl<<std::endl<<test<<std::endl;
   // std::ofstream myfile;
   // myfile.open("silly.dat", std::ios::binary | std::ios::out);
   // test.save(myfile);
   // myfile.close();

   // Cperson test_("dds");
   // std::ifstream file;
   // file.open("silly.dat", std::ios::in | std::ios::binary);
   // test_.load(file);
  //  std::cout<<test_;
    return 0;
}
