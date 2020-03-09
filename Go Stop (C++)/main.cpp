// Alec Rizzo - arizzo3@ramapo.edu
// Main source file for C++ program to play the game Go Stop against a computer player

#include <iostream>
#include "deck.h"

using namespace std;

int main() {
	Deck obj;
	obj.shuffleDeck();

	system("PAUSE");
	return 0;
}