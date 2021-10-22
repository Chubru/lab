#include <algorithm>
#include <iostream>
#include <vector>



std::vector <int> storage;


void f(int numberItems, int k,int n = 0){
    if(k>numberItems)
        return;

    if(n == k){
        for(int i = 0;i < storage.size();i++){
            std::cout<<storage[i];
        }
        std::cout<<std::endl;
    }
    else{
        for(int i = 0;i < numberItems;i++){
            if(std::find(storage.begin(),storage.end(),i) != storage.end())
                continue;
            storage.push_back(i);
            f(numberItems,k,n+1);
            storage.pop_back();
        }
    }
}

int main() {
    f(3,2);
    return 0;
}
