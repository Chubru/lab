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
    size_t_ size{10};
    size_t_ usage{0};
public:
    Cvector(){ptr = new T[size]; return;}

    Cvector(Cvector& v): size (v.szie), usage(v.usage){
        ptr = new T[size];
        for (int i=0; i < usage; i++) ptr[i] = v.ptr[i];
    }

    Cvector(Cvector&& v): ptr(v.ptr), size (v.size), usage(v.usage){
        v.size=10;
        v.usage = 0;
        v.ptr = new T[size];
    }

    Cvector& operator=(Cvector&& v){
        delete[] ptr;
        ptr=v.ptr;
        size=v.size;
        usage=v.usage;

        v.size=10;
        v.usage = 0;
        v.ptr = nullptr;
        return *this;
    }

    Cvector<T>& operator= (const Cvector<T>& v){
        delete[] ptr;
        size=v.size;
        ptr = new T[size];
        usage = v.usage;
        for (int i=0; i< usage; i++) ptr[i] = v.ptr[i];
        return *this;
    }
    ~Cvector(){delete[] ptr;}

    void pushBack(const T& dat){
        if(usage + 1 >= size){
                T* tmpPtr = new T[size*2];
                for(int i = 0;i < size ; i++){
                    tmpPtr[i] = ptr[i];
                }
                delete[] ptr;
                ptr = tmpPtr;
                size = size * 2;
        }
        ptr[usage] = dat;
        usage++;

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
        if(usage == size){
            T* tmpPtr = new T[size*2];
            for(int i=0;i < size;i++){
                tmpPtr[i]=ptr[i];
            }
            delete[] ptr;
            ptr=tmpPtr;
            size = size * 2;
            }
        for(int j = i;j <= usage ;j++){
            ptr[j+1]=ptr[j];
        }
        ptr[i]=value;
        usage++;

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

    bool operator == (const Cvector<T>& v){
        if( usage != v.usage)
            return false;

        for(int i=0;i < size;i++){
            if( ptr[i] != v.ptr[i])
                return false;
        }
        return true;
    }


};


#endif //LAB_17_CVECTOR_H