
#include <iostream>
#include <fstream>
#include <cstdio>

#pragma warning(disable : 4996)  
struct filterDataStr
{
    int idStart{ 0 };
    int idEnd{ 0 };
    bool lock{ false };
};

struct filteCurlyBraceStr {
    int count{ 0 };
};
struct filterDataStrHead {
    filterDataStr filter1;
    filterDataStr filter2;
    filterDataStr filter3;
    filteCurlyBraceStr filter4;
    filterDataStr filter5;
    filterDataStr filter6;
};

filterDataStrHead filterDataHead;


void out(char ch) {
    printf("%c", ch);
}

void filter7(char dat) {
    out(dat);
    if (dat == ')') {
        out(';');
    }
    
}

void filter6(char dat, filterDataStr& filterStr) {
    const char* s1 = "enum";
    const char* s2 = "\n";

    if (filterStr.lock == false) {
        if (s1[filterStr.idStart] == dat) {
            filterStr.idStart++;
            if (s1[filterStr.idStart] == '\0') {
                filterStr.lock = true;
                filterStr.idStart = 0;
            }
        }
        else {
            for (int i = 0; i < filterStr.idStart; i++) {
                filter7(s1[i]);
            }
            filterStr.idStart = 0;
            filter7(dat);
        }
    }
    else {
        if (s2[filterStr.idEnd] == dat) {
            filterStr.idEnd++;
            if (s2[filterStr.idEnd] == '\0') {
                filterStr.lock = false;
                filterStr.idEnd = 0;
            }
        }
        else {
            filterStr.idEnd = 0;
        }
    }

}
void filter5(char dat, filterDataStr& filterStr) {
    const char* s1 = "struct";
    const char* s2 = ";";

    if (filterStr.lock == false) {
        if (s1[filterStr.idStart] == dat) {
            filterStr.idStart++;
            if (s1[filterStr.idStart] == '\0') {
                filterStr.lock = true;
                filterStr.idStart = 0;
            }
        }
        else {
            for (int i = 0; i < filterStr.idStart; i++) {
                filter6(s1[i], filterDataHead.filter6);
            }
            filterStr.idStart = 0;
            filter6(dat, filterDataHead.filter6);
        }
    }
    else {
        if (s2[filterStr.idEnd] == dat) {
            filterStr.idEnd++;
            if (s2[filterStr.idEnd] == '\0') {
                filterStr.lock = false;
                filterStr.idEnd = 0;
            }
        }
        else {
            filterStr.idEnd = 0;
        }
    }

}

void filter4(char dat, filteCurlyBraceStr& filterStr) {
    if (dat == '{') {
        filterStr.count++;
    }
    else {
        if (dat == '}') {
            filterStr.count--;
        }
        else {
            if (filterStr.count == 0) {
                filter5(dat, filterDataHead.filter5);
            }
        }
    }
}

void filter3(char dat, filterDataStr& filterStr) {
    const char* s1 = "//";
    const char* s2 = "\n";

    if (filterStr.lock == false) {
        if (s1[filterStr.idStart] == dat) {
            filterStr.idStart++;
            if (s1[filterStr.idStart] == '\0') {
                filterStr.lock = true;
                filterStr.idStart = 0;
            }
        }
        else {
            for (int i = 0; i < filterStr.idStart; i++) {
                filter4(s1[i], filterDataHead.filter4);
            }
            filterStr.idStart = 0;
            filter4(dat, filterDataHead.filter4);
        }
    }
    else {
        if (s2[filterStr.idEnd] == dat) {
            filterStr.idEnd++;
            if (s2[filterStr.idEnd] == '\0') {
                filterStr.lock = false;
                filterStr.idEnd = 0;
            }
        }
        else {
            filterStr.idEnd = 0;
        }
    }

}

void filter2(char dat, filterDataStr& filterStr) {
    const char* s1 = "#";
    const char* s2 = "\n";

    if (filterStr.lock == false) {
        if (s1[filterStr.idStart] == dat) {
            filterStr.idStart++;
            if (s1[filterStr.idStart] == '\0') {
                filterStr.lock = true;
                filterStr.idStart = 0;
            }
        }
        else {
            for (int i = 0; i < filterStr.idStart; i++) {
                filter3(s1[i], filterDataHead.filter3);
            }
            filterStr.idStart = 0;
            filter3(dat, filterDataHead.filter3);
        }
    }
    else {
        if (s2[filterStr.idEnd] == dat) {
            filterStr.idEnd++;
            if (s2[filterStr.idEnd] == '\0') {
                filterStr.lock = false;
                filterStr.idEnd = 0;
            }
        }
        else {
            filterStr.idEnd = 0;
        }
    }

}



void filter1(char dat, filterDataStr& filterStr) {
    const char* s1 = "/*";
    const char* s2 = "*/";

    if (filterStr.lock == false) {
        if (s1[filterStr.idStart] == dat) {
            filterStr.idStart++;
            if (s1[filterStr.idStart] == '\0') {
                filterStr.lock = true;
                filterStr.idStart = 0;
            }
        }
        else {
            for (int i = 0; i < filterStr.idStart; i++) {
                filter2(s1[i], filterDataHead.filter2);
            }
            filterStr.idStart = 0;
            filter2(dat,filterDataHead.filter2);
        }
    }
    else {
        if (s2[filterStr.idEnd] == dat) {
            filterStr.idEnd++;
            if (s2[filterStr.idEnd] == '\0') {
                filterStr.lock = false;
                filterStr.idEnd = 0;
            }
        }
        else {
            filterStr.idEnd = 0;
        }
    }

}


int main()
{

    
    FILE* ptrFile = fopen("ex.c", "rt");
    if (ptrFile == NULL) {
        exit(-1);
    }
    for (;;) {
        int dat = fgetc( ptrFile);
        if (dat < 0)
            break;
        filter1(dat,filterDataHead.filter1);
    }
    filter1('\n', filterDataHead.filter1);
}





























//const char* s = filterDataHead.filter1.locked ? s2 : s1;

//if (dat == s[filterDataHead.filter1.index]) {
//    // founding
//    if (s[++filterDataHead.filter1.index] == '\0') {
//        filterDataHead.filter1.locked = !filterDataHead.filter1.locked;
//        filterDataHead.filter1.index = 0;
//    }
//    return;
//}
//else {
//    if (!filterDataHead.filter1.locked) {
//        for (int i = 0; i < filterDataHead.filter1.index; i++)
//            out(s[i]);
//        filterDataHead.filter1.index = 0;
//        out(dat);
//    }
//}