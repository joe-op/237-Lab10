#include "intBinTree.h"     

using namespace std;


intBinTree::intBinTree() {
	root = NULL;
	numItems = 0;
}


intBinTree::intBinTree(const intBinTree & T) {
	if (T.root == NULL)
	{
		root = NULL;
		numItems = 0;
	}
	else
	{
		root = copyTree(T.root);
		numItems = T.numItems;
	}
}

intTreeNode* intBinTree::copyTree(intTreeNode* other)
{
	//if node is empty (at bottom of binary tree)
	/*
	This creates a shallow copy which in turn causes a problem
	with the deconstructor, could not work out how to create a
	deep copy.
	*/
	if (other == NULL)
	{
		return NULL;
	}

	intTreeNode* newNode = new intTreeNode(other->getData());


	newNode->setLeftPtr(copyTree(other->getLeftChildPtr()));
	newNode->setRightPtr(copyTree(other->getRightChildPtr()));

	return newNode;
}

intBinTree & intBinTree::operator= (const intBinTree & T) {
	
	if (T.root == this->root)
		return *this;

	if (root != NULL)
		delete root;

	root = copyTree(T.root);
	numItems = T.numItems;

	return *this;
}


intBinTree::~intBinTree() {
	delete root;  // will recursively call the intTreeNode destructor
	root = NULL;
}


int intBinTree::getSize() const {
	return numItems;
}


int intBinTree::getRoot() const {
	return root->getData();
	// Since the pre condition requires the tree object to have at least
	// one element, root-> will not give us a "de-referencing a null
	// pointer (dangling pointer)" error.
}


void intBinTree::addLeft(int num) {

	intTreeNodePtr nodeToAddPtr = new intTreeNode(num);
	intTreeNodePtr currentPtr = root;
	if (root == NULL)
		root = nodeToAddPtr;
	else
	{
		while (currentPtr->getLeftChildPtr() != NULL 
			&& currentPtr->getRightChildPtr() != NULL)
		{
			currentPtr = currentPtr->getLeftChildPtr();
		}
		if (currentPtr->getLeftChildPtr() == NULL)
			currentPtr->setLeftPtr(nodeToAddPtr);
		else
		{
			currentPtr->setRightPtr(nodeToAddPtr);
		}
	}
	numItems++;
}


void intBinTree::addRight(int num) {

	intTreeNodePtr nodeToAddPtr = new intTreeNode(num);
	intTreeNodePtr currentPtr = root;
	if (root == NULL)
		root = nodeToAddPtr;
	else
	{
		while (currentPtr->getLeftChildPtr() != NULL
			&& currentPtr->getRightChildPtr() != NULL)
		{
			currentPtr = currentPtr->getRightChildPtr();
		}
		if (currentPtr->getRightChildPtr() == NULL)
			currentPtr->setRightPtr(nodeToAddPtr);
		else
		{
			currentPtr->setLeftPtr(nodeToAddPtr);
		}
	}
	numItems++;
}


void intBinTree::deleteLeft() {

	intTreeNodePtr currentPtr = root;
	intTreeNodePtr currentParentPtr = NULL;
	while (currentPtr->getLeftChildPtr() != NULL)
	{
		currentParentPtr = currentPtr;
		currentPtr = currentPtr->getLeftChildPtr();

	}
	if (currentPtr == root)
	{
		intTreeNodePtr temp = currentPtr;
		root = temp->getRightChildPtr();
		delete temp;
	}
	else
	{
		if (currentPtr->getRightChildPtr() == NULL)
		{
			currentParentPtr->setLeftPtr(NULL);
			delete currentPtr;
		}
		else
		{
			currentParentPtr->setLeftPtr(currentPtr->getRightChildPtr());
			delete currentPtr;
		}
	}
	numItems--;
}


void intBinTree::deleteRight() {

	intTreeNodePtr currentPtr = root;
	intTreeNodePtr currentParentPtr = NULL;
	while (currentPtr->getRightChildPtr() != NULL)
	{
		currentParentPtr = currentPtr;
		currentPtr = currentPtr->getRightChildPtr();

	}
	if (currentPtr == root)
	{
		intTreeNodePtr temp = currentPtr;
		root = temp->getLeftChildPtr();
		delete temp;
	}
	else
	{
		if (currentPtr->getLeftChildPtr() == NULL)
		{
			currentParentPtr->setRightPtr(NULL);
			delete currentPtr;
		}
		else
		{
			currentParentPtr->setRightPtr(currentPtr->getLeftChildPtr());
			delete currentPtr;
		}
	}
	numItems--;
}

bool intBinTree::isSearchTree()
{
	return isBST(root);
}

bool intBinTree::isBST(intTreeNode* root)
{
	if(root == NULL) {
		return true;
	} else if(isSubTreeLess(root->getLeftChildPtr(), root->getData()) &&
		 isSubTreeGreater(root->getRightChildPtr(), root->getData())) {
		return isBST(root->getLeftChildPtr()) && isBST(root->getRightChildPtr());
	} else {
		return false;
	}		
}

bool intBinTree::isSubTreeLess(intTreeNode* root, int value)
{
	if(root == NULL) {
		return true;
	} else if(root->getData() < value) {
		return isSubTreeLess(root->getLeftChildPtr(), value) &&
			isSubTreeLess(root->getRightChildPtr(), value);
	} else {
		return false;
	}           
}
bool intBinTree::isSubTreeGreater(intTreeNode* root, int value)
{
	if(root == NULL) {
		return true;
	} else if(root->getData() >= value) {
		return isSubTreeGreater(root->getLeftChildPtr(), value) &&
			isSubTreeGreater(root->getRightChildPtr(), value);
	} else {
		return false;
	}
}


void intBinTree::addForSearch(int item)
{
	root = addBST(root, item);
}

intTreeNode*  intBinTree::addBST(intTreeNode* root, int item)
{
	if(root == NULL) {
		//throw runtime_error("Cannot add to empty node.");
	} else if(item < root->getData()) {
		if(root->getLeftChildPtr() == NULL) {
			root->setLeftPtr(new intTreeNode(item));
		} else {
			addBST(root->getLeftChildPtr(), item);
		}
	} else {
		if(root->getRightChildPtr() == NULL) {
			root->setRightPtr(new intTreeNode(item));
		}	else {
			addBST(root->getRightChildPtr(), item);
		}
	}		
}


bool intBinTree::inSearchTree(int target)
{
	return inBST(root, target);
}

bool intBinTree::inBST(intTreeNode* root, int item)
{
	if(root == NULL) {
		return false;
	}	else if(root->getData() == item) {
		return true;
	} else if(root->getData() > item) {
		return inBST(root->getLeftChildPtr(), item);
	} else {
		return inBST(root->getRightChildPtr(), item);
	}
}


void intBinTree::preOrder()
{
	preOrderTraversal(root);
}

void intBinTree::preOrderTraversal(intTreeNode * current)
{
	//TODO
}

void intBinTree::postOrder()
{
	postOrderTraversal(root);
}

void intBinTree::postOrderTraversal(intTreeNode * current)
{
	//TODO
}
void intBinTree::inOrderTraversal(ostream & stream, intTreeNode * current) {
	if (current != NULL) {
		inOrderTraversal(stream, current->getLeftChildPtr());
		stream << current->getData() << " ";
		inOrderTraversal(stream, current->getRightChildPtr());
	}

}


ostream & operator<< (ostream & stream, const intBinTree & T) {
	intTreeNode * current = T.root;
	intBinTree temp = intBinTree();
	temp.inOrderTraversal(stream, current);
	return stream;
}


