#include "intTreeNode.h"


intTreeNode::intTreeNode() {
	data = 0;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}


intTreeNode::intTreeNode(int num) {
	data = num;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}



int intTreeNode::getData() const {
	return (data);
}


intTreeNode * intTreeNode::getLeftChildPtr() const {
	return leftChildPtr;
}


intTreeNode * intTreeNode::getRightChildPtr() const {
	return rightChildPtr;
}


void intTreeNode::setData(int num) {
	data = num;
}


void intTreeNode::setLeftPtr(intTreeNode * leftPtr) {
	leftChildPtr = leftPtr;
}


void intTreeNode::setRightPtr(intTreeNode * rightPtr) {
	rightChildPtr = rightPtr;
}


ostream & operator<< (ostream & stream, const intTreeNode * nodePtr) {
	stream << nodePtr->data;
	return stream;
}



intTreeNode::~intTreeNode() {
	//	cout << "intTreeNode destructor" << endl;
	delete leftChildPtr;
	leftChildPtr = NULL;
	delete rightChildPtr;
	rightChildPtr = NULL;
}
