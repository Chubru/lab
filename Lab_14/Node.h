#include "figure.h"
#include "circle.h"
#include "segment.h"

#pragma once
class Node
{
private:
	figure* ptr{ nullptr };
	Node* nextNode{nullptr};
public:
	Node(int x, int y,int R, const  char* textPtr) {
		ptr = new circle(x,y,R, textPtr);
	}
	Node(int x1, int y1, int x2, int y2) {
		ptr = new segment(x1, y1, x2, y2);
	}
	~Node() {
		delete ptr;
	}
	void setNextNode(Node* nextPtr) {
		nextNode = nextPtr;
	}
	void setFigure(figure* ptr_) {
		ptr = ptr_;
	}
	figure* getFigure() {
		return ptr;
	}
	Node* getNextNode() {
		return nextNode;
	}

};

