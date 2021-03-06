#include "math.h"
#include "Rational.h"

static rint_t nod(rint_t a, rint_t b) {
    while (a && b)
        if (a > b) a %= b;
        else b %= a;
    return a + b;
}
static rint_t nok (rint_t a, rint_t b) {
    return a * b / nod(a, b);
}
Rational Rational::operator + (const Rational& a) {
    Rational res(0, nok(this->m_denominator, a.m_denominator));
    res.m_numerator = this->m_numerator * res.m_denominator / this->m_denominator + a.m_numerator * res.m_denominator / a.m_denominator;
    rint_t nod_ = nod(res.m_denominator, abs(res.m_numerator));
    res.m_denominator /= nod_;
    res.m_numerator /= nod_;
    return res;
}