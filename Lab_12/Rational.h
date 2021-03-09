
#pragma once
#include <iostream>

typedef int rint_t;

class Rational
{
private:
	rint_t m_numerator;
	rint_t m_denominator;
public:
	Rational(rint_t numerator = 0, rint_t denumerator = 1);
	Rational operator + (const Rational& a);
	Rational operator - ()const { return Rational(-m_numerator, m_denominator); }
	Rational operator - (const Rational& a) { return *this + (-a); }

	Rational operator * (const Rational& a);
	Rational operator / (const Rational& a);

	Rational& operator += (const Rational& a) { *this = *this + a; return *this; };
	Rational& operator -= (const Rational& a) { *this = *this - a; return *this; };
	Rational& operator *= (const Rational& a) { *this = *this * a; return *this; };
	Rational& operator /= (const Rational& a) { *this = *this / a; return *this; };

	rint_t getNumerator() const { return m_numerator; }
	rint_t getDenominator() const { return m_denominator; }

	//void out();
};
Rational operator + (const rint_t a,const Rational& b) {
	Rational z = Rational(a) + b;
	return z;
}

std::ostream& operator << (std::ostream& out, const Rational& r);
std::istream& operator >> (std::istream& out, Rational& r);


