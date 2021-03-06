#pragma once

typedef int rint_t;

class Rational
{
private:
	rint_t m_numerator;
	rint_t m_denominator;
public:
	Rational(rint_t numerator = 0, rint_t denumerator = 1) { m_numerator = numerator; m_denominator = denumerator; }
	Rational operator + ( const Rational& a);
	Rational operator - ()const { return Rational(-m_numerator, m_denominator); }
	Rational operator - (const Rational& a) { return *this + (-a); }
};

