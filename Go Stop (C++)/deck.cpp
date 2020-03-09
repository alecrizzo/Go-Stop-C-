#include "deck.h"

/*
====================================================================
								DECK
====================================================================
*/

vector<string> Deck::card_deck;

// Constructor to setup deck of 52 cards in order
Deck::Deck() {	
	string card[] = { "1C", "2C", "3C", "4C", "5C", "6C", "7C", "8C", "9C", "XC", "JC", "QC", "KC",	// Clubs
	"1D", "2D", "3D", "4D", "5D", "6D", "7D", "8D", "9D", "XD", "JD", "QD", "KD",					// Diamonds
	"1H", "2H", "3H", "4H", "5H", "6H", "7H", "8H", "9H", "XH", "JH", "QH", "KH",					// Hearts
	"1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S", "XS", "JS", "QS", "KS"					// Spades
	};
	card_deck.clear();
	card_deck.insert(card_deck.end(), begin(card), end(card));
}


// Function to create a deck from a loaded save file
void Deck::loadDeck(string card) {	//corresponding function needs to remember to card_deck.clear()

}

void Deck::popDeck() {

}

// Function to shuffle all the values in the Deck "randomly"
void Deck::shuffleDeck() {	// Learned how to do this here https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector

	auto random = default_random_engine{};
	shuffle(begin(card_deck), end(card_deck), random);

	for (int i = 0; i < card_deck.size(); i++) {
		cout << card_deck[i] << endl;
	}
}

// Function returns amount of cards in card_deck as an integer
int Deck::sizeOfDeck() {
	return card_deck.size();
}