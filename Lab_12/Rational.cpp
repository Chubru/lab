#include "math.h"
#include "Rational.h"
#include <iostream>

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

Rational Rational::operator * (const Rational& a) {
    Rational res(this->m_numerator * a.m_numerator, this->m_denominator * a.m_denominator);
    rint_t nod_ = nod(res.m_denominator, abs(res.m_numerator));
    res.m_denominator /= nod_;
    res.m_numerator /= nod_;
    return res;
}

Rational Rational::operator / (const Rational& a) {
    if (a.m_numerator == 0) {
        throw "Devide by zero";
    }
    Rational res(this->m_numerator * a.m_denominator, this->m_denominator * a.m_numerator);
    rint_t nod_ = nod(res.m_denominator, abs(res.m_numerator));
    res.m_denominator /= nod_;
    res.m_numerator /= nod_;
    return res;
}


Rational::Rational(rint_t numerator, rint_t denumerator) {
    if (denumerator == 0) {
        throw "denumerator is zero";
    }
    if (denumerator < 0) {
        denumerator = -denumerator;
        numerator = -numerator;
    }
    m_numerator = numerator; m_denominator = denumerator; 
}

std::ostream& operator << (std::ostream& out,const Rational& r) {
    out << r.getNumerator() << "/" << r.getDenominator();
    return out;
}

std::istream& operator >> (std::istream& in, Rational& r) {
    rint_t num, deNom;
    in >> num >> deNom;
    r = Rational(num, deNom);
    return in;
}

