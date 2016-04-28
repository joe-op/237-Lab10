#include "intBinTree.h"

void pause_237(bool);


int main() {
	intBinTree the_tree = intBinTree();
	// 12 23 39 46 51 68 72 84

	the_tree.addLeft(51);
	the_tree.addLeft(39);
	the_tree.addLeft(72);
	the_tree.addLeft(23);
	the_tree.addLeft(46);
	the_tree.addLeft(12);
	the_tree.addRight(84);
	the_tree.addRight(68);
	
	cout << "Display in order:" << endl;
	cout << the_tree << endl;

	pause_237(false);

	cout << "Use addForSearch:" << endl;
	intBinTree the_tree2 = intBinTree();
	the_tree2.addForSearch(51);
	// test if tree is valid
	cout << the_tree2.isSearchTree() << " ";
	the_tree2.addForSearch(39);
	cout << the_tree2.isSearchTree() << " ";
	the_tree2.addForSearch(72);
	cout << the_tree2.isSearchTree() << " ";
	the_tree2.addForSearch(23);
	cout << the_tree2.isSearchTree() << " ";
	the_tree2.addForSearch(46);
	cout << the_tree2.isSearchTree() << " ";
	the_tree2.addForSearch(12);
	cout << the_tree2.isSearchTree() << " ";
	the_tree2.addForSearch(84);
	cout << the_tree2.isSearchTree() << " ";
	the_tree2.addForSearch(68);
	cout << the_tree2.isSearchTree() << endl;
	
	cout << "Display in order:" << endl << the_tree2 << endl;

	cout << "Is 36 in the tree?" << endl << the_tree2.inSearchTree(36) << endl;
	cout << "Is 84 in the tree?" << endl << the_tree2.inSearchTree(84) << endl;



	cout << "Display preorder:" << endl;
	the_tree2.preOrder();
	cout << endl;
	cout << "Display postorder:" << endl;
	the_tree2.postOrder();
	cout << endl;

	pause_237(false);
	
	

	return 0;
}



void pause_237(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(200, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(200, '\n');
}

