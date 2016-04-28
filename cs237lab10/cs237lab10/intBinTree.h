#ifndef INCLUDED_intBinTree
#define INCLUDED_intBinTree

#include <iostream>      // For using the type ostream.
#include "intTreeNode.h"     // For using the intTreeNode class here.

using namespace std;

class intBinTree {

	// An object of intBinTree contains a defined pointer r
	// that points to the root node (type intTreeNode) of a 
	// binary tree if any. n is defined and contains the 
	// number of intTreeNode objects in this binary tree object. 

private:
	intTreeNode * root;        // stores the pointer, denoted by r, to the root node
							   // in the binary tree.
	int numItems;              // stores the number, denoted by n, of items in the
							   // binary tree.

	// Precondition: stream is a defined output stream.
	//				 current is a defined pointer, possibly NULL, to an intTreeNode object.				 
	// Postcondition: stream contains the elements in the left subtree of current
	//				  followed by the element at current, 
	//				  followed by the elements in the right subtree of current.
	void inOrderTraversal(ostream & stream, intTreeNode * current);

	intTreeNode* copyTree(intTreeNode* other);  //for Tree deep copy

	bool isBST(intTreeNode* root); // helper for isSearchTree function

	bool isSubTreeLess(intTreeNode* root, int value); //helper for isBST

	bool isSubTreeGreater(intTreeNode* root, int value); //helper for isBST

	intTreeNode*  addBST(intTreeNode* root, int item); //helper for addForSearch function

	bool inBST(intTreeNode* root, int item); //helper for inSearchTree function

	void preOrderTraversal(intTreeNode * current); //helper for preOrder

	void postOrderTraversal(intTreeNode * current); //helper for postOrder

public:

	// default constructor
	// Precondition 
	// Postcondition: This object is defined with r = NULL and n = 0.
	intBinTree();


	// copy constructor
	// Precondition: T is defined.
	// Postcondition: This object is defined and is a deep copy of T.
	//				  Thus, r = T.r, with all the intTreeNodes in this object being 
	//                physically distinct from the intTreeNodes of T.
	//				  n = T.n
	//			      Note here that T is being passed by reference to avoid the
	//                shallow copy of the actual parameter being passed as T.
	//                We indicate that T does not change with the keyword const.
	intBinTree(const intBinTree & T);

	// Preconcition: T is defined.
	// Postcondition: This object is defined and is a deep copy of T.
	//			      Thus, r = T.r, with all the intTreeNodes in r being 
	//                physically distinct from the intTreeNodes of T.
	//                n = T.n
	//                Note here that T is being passed by reference to avoid the
	//                shallow copy of the actual parameter being passed as T.
	//                We indicate that T does not change with the keyword const.
	intBinTree & operator= (const intBinTree & T);


	// destructor
	// Precondition: This object is defined.
	// Postcondition: This object has no elements. r = NULL and n = 0.
	//                All space allocated for this object is deallocated.
	~intBinTree();


	// Precondition: This object is defined.
	// Postcondition: Return n.
	int getSize() const;

	// Precondtion: This object is defined and n > 0.
	// Postcondition: Return the integer stored at the root of the tree.
	int getRoot() const;

	// Precondition: num is defined. This object is defined and has n nodes.
	// Postcondition: n = n + 1. 
	//				  An intTreeNode object t that contains the integer data num is created.
	//                If this tree object is empty, then the new node t is made the
	//                root of the tree.
	//                Otherwise: 
	//                Let x be the first leftmost descendent (this could be the
	//                root) of this intBinTree object that does not have two children.
	//                If x does not have a left child, then t is added as the left child of x;
	//                otherwise, t is added as the right child of x.
	void addLeft(int num);

	// Precondition: num is defined. This object is defined and has n nodes.
	// Postcondition: n = n + 1. 
	//				  An intTreeNode object t contains the integer data num is created.
	//                If this tree object is empty, then the new node is made the
	//                root of the tree.
	//				  Otherwise: 
	//				  Let x be the first rightmost descendent (this could be the
	//                root) of this intBinTree object that does not have both children.
	//				  If x does not have  a right child, then t is added as the right child of x;        
	//				  otherwise, t is added as the left child of x.
	void addRight(int num);

	// Precondition: This object is defined. n > 0.
	// Postconcition: n = n - 1.
	//                Let x be the leftmost descendent of this intBinTree object.
	//                If x is the root of this intBinTree object, then the right
	//                child of x (possibly NULL) is made the root of this object.
	//                If x is not the root of this object:
	//                Suppose x does not have a right child. Then the node x is deleted.
	//                Suppose x has a right child, say y, and the parent of x is p.
	//                Then node x is deleted and y is made the left child of p.
	void deleteLeft();

	// Precondition: This object is defined. n > 0.
	// Postcondition: n = n -1.
	//				  Let x be the rightmost descendent of this intBinTree object.
	//                If x is the root of this intBinTree object, then the left
	//                child of x (possibly NULL) is made the root of this object.
	//                If x is not the root of this object:
	//                Suppose x does not have a left child. Then the node x is deleted.
	//                Suppose x has a left child, say y, and the parent of x is p.
	//                Then node x is deleted and y is made the right child of p.
	void deleteRight();

	// Returns whether this binary tree is a binary search tree
	bool isSearchTree();

	// Add num to this binary search tree 
	// The tree with additional element should retain binary search tree property
	void addForSearch(int item);

	// Returns whether target is in this binary search tree
	bool inSearchTree(int target);

	// Print this binary tree to the console using pre-order traversal
	void preOrder();

	// Print this binary tree to the console using post-order traversal
	void postOrder();

	// Precondition: T is defined.
	// Postcondition: stream contains the contents of the nodes of this
	//			      intBinTree object as visited in the inorder traversal of the object.
	friend ostream & operator<< (ostream & stream, const intBinTree & T);

};
#endif
