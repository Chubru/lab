#include <iostream>
#include <fstream>
#include "obj/Cmatrix.h"
int main() {
   Cmatrix matrix;
   matrix.load("../1.txt");
    //std::ofstream fout;
    //fout.open("file.txt");
    // matrix.dfs(fout);
   matrix.dfs(std::cout);
   return 0;
}
