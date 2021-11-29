//
// Created by chubr on 27.11.2021.
//

#include "Cmatrix.h"


void Cmatrix::dfs(std::ostream& stream){
    struct point {
        int id;
        int len;
    };
    std::stack<point> stack;
    std::vector<int> way;
    stack.push({root,0});
    mark[root]=1;

    while(stack.size() != 0){
        auto [tmp, len] = stack.top();
        way.push_back(tmp);

        for (int i = 0; i < matrix[tmp].size(); ++i){

            if(mark[i] == notVisited && matrix[tmp][i] != 0 && len+matrix[tmp][i] < dc){
                for (auto id: way)
                    stream << id << " ";
                stream << i << std::endl;

                stack.push({i,len+matrix[tmp][i]});
                mark[i] = visited;
            }

        }

        if(stack.top().id == tmp) {
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
    root = atoi(str.c_str());
    if (root < 0)
        throw "invalid root";

    std::getline(inf,str);
    dc = atoi(str.c_str());
    if (dc < 0)
        throw "invalid dc";

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
