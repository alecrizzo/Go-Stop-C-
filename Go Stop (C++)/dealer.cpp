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

// Function to get a card from the deck and delete it (does it from the end not the front) || Mirror function to popDeck() --> Deck
string Dealer::popDeck()
{
	string last;
	last = combo_deck.back();
	combo_deck.pop_back();
	return last;
}

// Function Definition for swapping turn between human player and computer player
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

void Dealer::combineDecks(Deck d1, Deck d2) 
{
	string temp1;
	string temp2;

	d1.shuffleDeck();
	d2.shuffleDeck();

	for (int i = 0; i < d1.sizeOfDeck(); i++) 
	{
		combo_deck.push_back(d1.popDeck());
		combo_deck.push_back(d2.popDeck());
	}

}

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