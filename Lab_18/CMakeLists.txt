cmake_minimum_required(VERSION 3.20)
project(lab_18)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_18 main.cpp object/person/Cperson.cpp object/person/Cperson.h object/phoneBook/CphoneBook.cpp object/phoneBook/CphoneBook.h)
