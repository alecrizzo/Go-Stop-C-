#include "save.h"

Save::Save() 
{

};

void Save::writeSave() 
{
	// cout as temp, change syntax to write to a file
	cout << "Round: " << endl << endl;	// needs round #
	cout << "Computer: " << endl;
	cout << "\tScore: " << endl;		// needs score #
	cout << "\tHand: " << endl;		// needs computers hand vector
	cout << "\tCapture Pile: " << endl;

	cout << "Human: " << endl;
	cout << "\tScore: " << endl;		// needs score #
	cout << "\tHand: " << endl;		// needs humans hand vector
	cout << "\tCapture Pile: " << endl << endl;

	cout << "Layout: " << endl << endl;		// needs layout vector
	cout << "Stock Pile: " << endl << endl;	// 
	cout << "Next Player: " << endl; //
}