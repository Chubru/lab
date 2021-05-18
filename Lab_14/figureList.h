#pragma once
#include "figure.h"
#include "circle.h"
#include "Node.h"
class figureList
{
private:
	Node* firstItem{nullptr};
public:
	~figureList();
	void addItem(int x, int y, int R, const char* textPtr);
	void addItem(int x1, int y1, int x2, int y2);
	void printAll();
	void printxy();

	void findFigure(int id);

	void erase(int id);

};