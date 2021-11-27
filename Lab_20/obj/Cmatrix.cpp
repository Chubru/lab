//
// Created by chubr on 27.11.2021.
//

#include "Cmatrix.h"


void Cmatrix::dfs(std::ostream& stream){
    std::stack<int> stack;
    std::vector<int> way;
    stack.push(root);
    mark[root]=1;

    while(stack.size()!=0){
        int tmp = stack.top();
        way.push_back(tmp);

        for (int i = 0; i < matrix[tmp].size(); ++i){

            if(mark[i] == 0 && matrix[tmp][i] != notVisited){
                for(auto id:way)
                    stream << id << " ";
                stream<<i<<std::endl;
            }
            if(mark[i] == 0 && matrix[tmp][i] != notVisited ){
                stack.push(i);
                mark[i] = visited;
            }

        }

        if(stack.top() == tmp) {
            stack.pop();
            way.pop_back();
        }
    }
}


void Cmatrix::load(const std::string& filename){
    std::ifstream inf(filename);
    if (!inf)
        throw "invalid fileName";

    std::string str;
    std::getline(inf,str);
    root=atoi(str.c_str());
    if (root < 0)
        throw "invalid root";

    while(std::getline(inf,str)){
        std::stringstream buf(str);
        std::vector<int> tmp;

        while(buf.rdbuf()->in_avail() != 0){
            int len;
            buf >> len;
            tmp.push_back(len);
        }

        matrix.push_back(tmp);
        tmp.clear();
    }

    for(int i = 0;i <= matrix.size();i++){
        mark.push_back(0);
    }

    return;

}
