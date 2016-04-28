#include "intBinTree.h"

void pause_237(bool);


int main() {
	intBinTree the_tree = intBinTree();
	// 12 23 39 46 51 68 72 84
	the_tree.addLeft(72);
	the_tree.addLeft(51);
	the_tree.addLeft(84);
	the_tree.addLeft(39);
	the_tree.addLeft(68);
	the_tree.addLeft(23);
	the_tree.addLeft(46);
	the_tree.addLeft(12);


	cout << the_tree << endl;
	//	pause_237(false);

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

