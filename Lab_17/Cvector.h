//
// Created by chubr on 9/16/21.
//

#ifndef LAB_17_CVECTOR_H
#define LAB_17_CVECTOR_H


typedef long long size_t_;
template <typename T>


class Cvector {
private:
    T* ptr;
    size_t_ size=0;
    size_t_ usage=0;
    size_t_ incr=-1;
public:
    Cvector(){size=10; ptr = new T[size]; return;}
    Cvector(int size_){size=size_; ptr = new T[size]; return;}
    Cvector(int size_,int incr_){size=size_; incr=incr_; ptr = new T[size]; return;}

    void pushBack(T dat){
        if(usage<size){
            ptr[usage]=dat;
            usage++;
        }
        else{
            if(incr!=-1) {
                T* tmpPtr = new T[size+incr];
                for(int i=0;i<size;i++){
                    tmpPtr[i]=ptr[i];
                }
                delete[] ptr;
                ptr=tmpPtr;
                size = size + incr;
            }
            else{
                T* tmpPtr = new T[size*2];
                for(int i=0;i<size;i++){
                    tmpPtr[i]=ptr[i];
                }
                delete[] ptr;
                ptr=tmpPtr;
                size = size * 2;
            }
        }
    }

    T& operator [](size_t_ index){
        if( index > usage || index < 0 ){
            throw "invalid index";
        }
        return ptr[index];
    }
    T& at(size_t_ index){
        if( index > usage || index < 0 ){
            throw "invalid index";
        }
        return ptr[index];
    }

    void insert(size_t_ i, const T& value){
        if( i > usage || i < 0 ){
            throw "invalid index";
        }
        if(usage<size-1) {
            T *tmpPtr = new T[size + incr];
            for (int i = 0; i < size; i++) {
                tmpPtr[i] = ptr[i];
            }
            delete[] ptr;
            ptr = tmpPtr;
            size = size + incr;
        }
        for(size_t_ i=usage-1;i>=i;i++){
            ptr[i+1]=ptr[i];
        }
        ptr[i]=value;
    }

    void erase(size_t_ id){
        if( id > usage || id < 0 ){
            throw "invalid index";
        }

        for(size_t_ i=id;i<size;i++){
            ptr[i]=ptr[i+1];
        }
        ptr[id]=0;
        usage--;
    }

};


#endif //LAB_17_CVECTOR_H
