#pragma once
#include "gostop.h"
#include "deck.h"
#include "player.h"

class Dealer 
{
public:
	Dealer();

	void combineDecks(Deck d1, Deck d2);
	static string popDeck();
	void dealCards(Player* p);
	void dealLayout(vector<string> layout_pile);
	void displayStockpile();						// displays the combo_deck aka stockpile
	void displayTurn();

private:
	//friend class Deck;

	static vector<string> combo_deck;				// the combination of the 2 decks, becomes the stockpile	
	char turnVal;									// 'h' for human turn, 'c' for computer turn

	void swapTurns();

};