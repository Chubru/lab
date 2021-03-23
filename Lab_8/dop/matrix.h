#pragma once
class matrix
{
private:
	int** matrix_p;
	int m, n;
public:
	matrix();
	~matrix();
	void localExtremum(void (*callBack_p)(int, int, const char*, void*));
	
};
