#include <cstdio>
#include <time.h>
#include "logic.h"



#pragma warning(disable : 4996)  

filterDataStrHead filterDataHead;


void out(char ch) {
    printf("%c", ch);
}
void filter8(char dat, filteCurlyBraceStr& filterStr) {
    if (dat == '\n') {
        filterStr.count++;
    }
    else {
        filterStr.count = 0;
    }
    if (filterStr.count <= 1) {
        out(dat);
    }
}
void filter7(char dat) {
    filter8(dat, filterDataHead.filter8);
    if (dat == ')') {
        filter8(';', filterDataHead.filter8);
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
                filter6(dat, filterDataHead.filter6);
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



void filter1(char dat) {
    const char* s1 = "/*";
    const char* s2 = "*/";
    filterDataStr& filterStr = filterDataHead.filter1;
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
            filter2(dat, filterDataHead.filter2);
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


void prolog() {
    long t = time(NULL);
    char str[1000];
    sprintf(str, "#ifndef _LOGIC_%08X__H\n#define _LOGIC_%08X__H\n", t, t);
    for (int i = 0; str[i] != '\0'; i++) {
        out(str[i]);
    }
}
void epilog() {
    char str[] = "\n#endif\n";
    for (int i = 0; str[i] != '\0'; i++) {
        out(str[i]);
    }
}