#include <iostream>
#include <vector>


std::vector <int> storage;

void f(int dat, int depth, int n = 0){
    if(dat==0)
        return;

    static int originalValue;
    if(n==0)
        originalValue=dat;
    for(int i=0;i<dat;i++){
        storage.push_back(dat-i);
        if(n < depth){
            int sum = 0;
            for(int j = 0;j < storage.size();j++){
                sum += storage[j];
            }
            if(originalValue == sum && n != 0){
                for(int j = 0;j < storage.size();j++){
                    std::cout<<storage[j]<<" ";
                }
                std::cout<<std::endl;
            }
        }
        f(dat-1, depth, n + 1);
        storage.pop_back();
    }

}

int main() {
    f(3,2);
    return 0;
}
