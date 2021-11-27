//
// Created by chubr on 27.11.2021.
//

#ifndef LAB20_CMATRIX_H
#define LAB20_CMATRIX_H


#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <iostream>

#define notVisited 0
#define visited 1


class Cmatrix {
    std::vector<std::vector<int>> matrix;
    std::vector<int> mark;
    int n{0},root{0};
public:
    void load(const std::string& filename);
    void dfs(std::ostream& stream);
};


#endif //LAB20_CMATRIX_H
