#include <cstdio>
#include "logic.h"
#pragma warning(disable : 4996)  
int main()
{
    FILE* ptrFile = stdin; //fopen("ex.c", "rt");
    if (ptrFile == NULL) {
        return -1;
    }
    prolog();
    for (;;) {
        int dat = fgetc( ptrFile);
        if (dat < 0)
            break;
        filter1(dat);
    }
  
    epilog();
}








