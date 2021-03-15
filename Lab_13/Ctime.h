#pragma once
#include <iostream>
class Ctime
{
private:
	int m_time;
public:
	Ctime(int sec, int min = 0, int hour = 0) { m_time = sec + min * 60 + hour * 3600; }
	Ctime& operator=(const Ctime& a) = default;
	Ctime operator + (const Ctime& a) { Ctime tmp(a.m_time + this->m_time); return tmp; }
	Ctime operator - (const Ctime& a) { Ctime tmp((-a.m_time) + this->m_time); return tmp; }


	friend bool operator > (const Ctime& d1, const Ctime& d2) { return d1.m_time > d2.m_time; }
	friend bool operator < (const Ctime& d1, const Ctime& d2) { return d1.m_time < d2.m_time; }
	friend bool operator >= (const Ctime& d1, const Ctime& d2) { return d1.m_time >= d2.m_time; }
	friend bool operator <= (const Ctime& d1, const Ctime& d2) { return d1.m_time <= d2.m_time; }

	friend bool operator == (const Ctime& d1, const Ctime& d2) { return d1.m_time == d2.m_time; }
	bool operator != (const Ctime& d2) { return m_time != d2.m_time; }

	Ctime& operator++() { ++m_time; return *this; }
	Ctime& operator++(int) { m_time++; return *this; }

	Ctime& operator--() { --m_time; return *this; }
	Ctime& operator--(int) { m_time--; return *this; }

	Ctime operator +(const int a) { return Ctime(a+m_time); }
	Ctime& operator +=(const int a) { m_time += a; return *this; }

	int getSec() const{ return m_time % 60; }
	int getMin() const { return (m_time / 60)%60; }
	int getHour() const { return m_time / 3600; }

	friend std::istream& operator >> (std::istream& out,  Ctime& tm);
	friend std::ostream& operator << (std::ostream& in, const Ctime& tm);
};


