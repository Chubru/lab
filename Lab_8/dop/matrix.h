#pragma once
class matrix
{
private:
	int** matrix_p;
	int m, n;
public:
	matrix();
	~matrix();
	void localExtremum();
	
};
void callBack(int x, int y, const char* massages, void* pt);
