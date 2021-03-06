#include "logic.h"



static char digitsh[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static char digitss[] = "0123456789abcdefghijklmnopqrstuvwxyz";



int char2int(char ch) {
    int i = 0;
    for (; i < 36; ++i) {
        if (ch == digitsh[i] || ch == digitss[i])
            return i;
    }
    return -1;
}

long long int strtoll1(char* str, char** endptr, int base){
    if (base == 0) {

    }
    bool minus = false;
    if (*str == '-') {
        minus = true;
        str++;
    }   
    long long result = 0;                                      
    for (;;) {
        int dig = char2int(*str);
        if (dig >= base) {
            *endptr = str;
            break;
        }
        str++;
        if (dig < 0) {
            break;
        }
        result *= base;
        result += dig;
    }
    if (minus) {
        result = -result;
    }
    return result;
}

