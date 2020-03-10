#include "dealer.h"

/*
====================================================================
								DEALER
====================================================================
*/

vector<string> Dealer::combo_deck;

Dealer::Dealer()
{
	turnVal = ' ';
	combo_deck.clear();
}

// Function Definition for dealing cards to players
void Dealer::dealCards(Player* p) 
{
	if (combo_deck.size() > 0) 
	{
		p->takeCard(popDeck());
	}
	else
	{
		cout << "\nOut of Cards\n";
	}
}

// Function to return a string card from the deck and delete it (does it from the end not the front) || Mirror function to popDeck() --> Deck
string Dealer::popDeck()
{
	if (combo_deck.size() != 0) 
	{
		string card;
		card = combo_deck.back();
		combo_deck.pop_back();
		return card;
	}
	else return "error"; //need to change this so players aren't dealt errors

}

// Function for swapping member turnVal to alternate between human player and computer player
void Dealer::swapTurns() 
{
	if (turnVal == 'h')
	{
		turnVal = 'c';
	}
	else if(turnVal == 'c')
	{
		turnVal = 'h';
	}
	else 
	{
		cout << "ERROR: Fatal Error in swapping Turn Values - Class Dealer\n";
	}
}

// Takes two Deck(); Objects, shuffles the cards and puts them all into the deck member combo_deck
// which will be used as the stockpile after dealing cards
void Dealer::combineDecks(Deck d1, Deck d2) 
{
	d1.shuffleDeck();
	d2.shuffleDeck();

	//changing this to be a variable rather than a call in for() should work better
	// but the program is crashing, there is another problem elsewhere.

	for (int i = 0; i < d1.sizeOfDeck(); i++) 
	{
		combo_deck.push_back(d1.popDeck());
		combo_deck.push_back(d2.popDeck());
	}

}

// Push.back()s 8 cards to a string vector, ONLY TO BE USED ON layout_pile vector at start of a round
void Dealer::dealLayout(vector<string> layout_pile)
{
	for (int i = 0; i < 8; i++) 
	{
		layout_pile.push_back(popDeck());
	}
}

void Dealer::displayStockpile() 
{
	for (int i = 0; i < combo_deck.size(); i++)
	{
		cout << combo_deck[i] << ", ";
	}
}

void Dealer::displayTurn() 
{
	cout << turnVal;
}