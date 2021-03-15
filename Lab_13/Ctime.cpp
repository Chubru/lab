#include "Ctime.h"


Ctime operator += (const int a, const Ctime& b) {
	Ctime z = Ctime(a) + b;
	return z;
}
std::ostream& operator << (std::ostream& out, const Ctime& tm) {
	
	out << tm.getHour() << ":"<<tm.getMin()<<":"<<tm.getSec();
	return out;
}

std::istream& operator >> (std::istream& in, Ctime& tm) {
	int tmp = 0;
	in >> tm.m_time;
	in >> tmp;
	tm.m_time = tm.m_time * 60 + tmp;
	in >> tmp;
	tm.m_time = tm.m_time * 60 + tmp;
	return in;
}
