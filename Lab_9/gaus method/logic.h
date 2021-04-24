
#ifndef _LOGIC_H_
#define _LOGIC_H_
#include "Rational.h"
typedef Rational detInt_t;
detInt_t** init(int size);
void del(detInt_t** matrix, int size);
detInt_t determinant(detInt_t** matrix, int size);
#endif // _LOGIC_H_