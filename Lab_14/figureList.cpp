#include "figureList.h"



void figureList::erase(int id) {
	if (id < 0) {
		throw "[erase] invalid id.";
		return;
	}
	Node* tmpItem = firstItem;
	Node* lastItem = nullptr;
	for (int i = 0; i < id && tmpItem != nullptr; i++) {
		lastItem = tmpItem;
		tmpItem = tmpItem->getNextNode();
	}
	if (tmpItem == nullptr) {
		return;
	}
	if (lastItem == nullptr) {
		firstItem = tmpItem->getNextNode();
		delete tmpItem;
		return;
	}
	lastItem->setNextNode(tmpItem->getNextNode());
	delete tmpItem;
}
figureList::~figureList() {
	Node* tmpItem = firstItem;
	for (; tmpItem != nullptr;) {
		Node* tmpItem_ = tmpItem;
		tmpItem = tmpItem->getNextNode();
		delete tmpItem_;
	}
}
void figureList::addItem(int x, int y, int R, const char* textPtr) {
	if (firstItem == nullptr) {
		//firstItem = new circle ( R, textPtr );
		//firstItem = new circle { R, textPtr };
		firstItem = new Node(x, y, R, textPtr);
	}
	else {
		Node* tmpItem = new Node(x, y, R, textPtr);
		tmpItem->setNextNode(firstItem);
		firstItem = tmpItem;
	}

}
void figureList::addItem(int x1, int y1, int x2, int y2) {
	if (firstItem == nullptr) {
		firstItem = new Node(x1, y1, x2, y2);
	}
	else {
		Node* tmpItem = new Node(x1, y1, x2, y2);
		tmpItem->setNextNode(firstItem);
		firstItem = tmpItem;
	}
}
void figureList::printAll() {
	Node* tmpItem = firstItem;
	if (firstItem->getNextNode() == nullptr) {
		std::cout << "list is empty" ;
	}
	for (int i=0; tmpItem != nullptr;i++) {
		std::cout << "id " << i << " ";
		tmpItem->getFigure()->print();
		tmpItem = tmpItem->getNextNode();

	}
}
void figureList::printxy() {
	Node* tmpItem = firstItem;
	for (; tmpItem != nullptr;) {
		tmpItem->getFigure()->printxy();
		tmpItem = tmpItem->getNextNode();

	}
}
void figureList::findFigure(int id) {
	if (id < 0) {
		throw "[findFigure] invalid id.";
		return;
	}
	Node* tmpItem = firstItem;
	for (unsigned int i = 0; i < id && tmpItem->getNextNode() != nullptr; i++) {
		tmpItem = tmpItem->getNextNode();
	}
	tmpItem->getFigure()->print();
}