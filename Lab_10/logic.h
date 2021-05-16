#ifndef _LOGIC_H_

#define _LOGIC_H_

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
    filteCurlyBraceStr filter8;
};


void filter1(char dat);
void prolog();
void epilog();
extern filterDataStrHead filterDataHead;
#endif // _LOGIC_H_