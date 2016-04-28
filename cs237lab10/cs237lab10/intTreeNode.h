#ifndef INCLUDED_intTreeNode
#define INCLUDED_intTreeNode

#include <iostream>      // For using the type ostream.
using namespace std;

class intTreeNode {

	// An object of intTreeNode contains a defined integer n 
	// and two pointers p and q to the left and right children nodes. 

private:
	int data;           // stores the data item in this node
						// denoted by n.
	intTreeNode * leftChildPtr;   // store the pointer, denoted by p,
								  // to the left child node, if any.
								  // If there  is no left child node, 
								  // this pointer has a value NULL
	intTreeNode * rightChildPtr;  // store the pointer, denoted by q, 
								  // to the right child node, if any.
								  // If there  is no right child node, 
								  // this pointer has a value NULL

public:

	// default constructor
	// Precondition: 
	// Postcondition: This object is defined with n = 0,
	//                p = NULL and q = NULL.
	intTreeNode();

	// Precondition:  num is defined.
	// Postcondition: This object is defined with n = num, 
	//                p = NULL and q = NULL.
	intTreeNode(int num);


	// Precondition: This object is defined.
	// Postcondition: Return n.
	int getData() const;   // the keyword const indicates that this
						   // member function does not modify this object.

						   // Precondition: This object is defined.
						   // Postcondition: return p.
	intTreeNode * getLeftChildPtr() const;

	// Precondition: This object is defined.
	// Postcondition: return q.
	intTreeNode * getRightChildPtr() const;


	// Precondition: This object is defined. num is defined.
	// Postcondition: n = num.
	void setData(int num);

	// Precondition: This object is defined. leftPtr is defined.
	// Postcondition: p = leftPtr.
	void setLeftPtr(intTreeNode * leftPtr);

	// Precondition: This object is defined. rightPtr is defined.
	// Postcondition: q = rightPtr.
	void setRightPtr(intTreeNode * rightPtr);

	// Precondition: stream is a defined output stream. 
	//			     nodePtr is defined and points to an intTreeNode object.
	// Postcondition: Data from the node pointed to by nodePtr is on output stream, 
	//				 and return output stream.
	friend ostream & operator<< (ostream & stream, const intTreeNode * nodePtr);


	// destructor
	// Precondition: This object is defined.
	// Postcondition: The two children objects are destroyed.
	~intTreeNode();

};

typedef intTreeNode* intTreeNodePtr;

#endif
