#pragma once
#include "gostop.h"
#include "deck.h"

// Class for Deck
class Deck 
{
public:
	Deck();										// Sets up all 52 cards in order "1C" - "KS"

	static int sizeOfDeck();
	static void loadDeck(string card);
	static string popDeck();					// gets card off top of deck and removes it
	static void shuffleDeck();					// shuffles deck
	static void printDeck();

private:
	static vector<string> card_deck;			// Standard deck of 52 cards

};
