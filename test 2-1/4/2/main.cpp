#include <iostream>
#include <vector>


std::vector <int> storage;

void f(int initialNumber,int len,int count,int n = 0){
    for(int i = 0;i < count;i++){
        storage.push_back(initialNumber+i);
        if(n < len){
            f(initialNumber,len,count,n+1);
        }
        else{
            bool flag=false;
            for(int i=1;i<storage.size()-1;i++){
                if(storage[i-1]<storage[i] && storage[i]<storage[i+1]) {
                    flag = true;
                    break;
                }
            }
            if(flag == false) {
                for (int i = 0; i < storage.size(); i++) {
                    std::cout << storage[i];
                }
                std::cout << std::endl;
            }
        }
        storage.pop_back();
    }
}

int main() {
    f(4,4,4);
    return 0;
}
