#pragma once
#include "gostop.h"

// Class for Deck
class Deck {
private:
	static vector<string> card_deck;	// Standard deck of 52 cards

public:
	Deck();		// Constructor for Deck. Sets up all 52 cards in order

	static int sizeOfDeck();
	static void loadDeck(string card);
	static void popDeck();		// gets card off top of deck
	static void shuffleDeck();	// shuffles deck
};
