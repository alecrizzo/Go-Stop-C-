#include "player.h"

/*
====================================================================
								PLAYER
====================================================================
*/

Player::Player() 
{
	player_cards.clear();
	captured_cards.clear();
	score = 0;
}

// Function to take card from the deck and add to player_cards 
template <typename T>	// Templated to work with both Deck(); and Dealer();
void Player::drawCard(T d) 
{
	player_cards.push_back(d.popDeck());
}

int Player::totalCards() 
{
	return player_cards.size();
}

void Player::takeCard(string card) // Pushes the string card into the back of the players cards vector
{
	player_cards.push_back(card);
}


void Player::pairCards(string card)	// Pushes the string card into the back of the captured cards vector (paired cards)
{
	captured_cards.push_back(card);
}

void Player::displayCards()
{
	for (int i = 0; i < player_cards.size(); i++) 
	{
		cout << player_cards[i] << ", ";
	}
}

void Player::displayCaptured()
{
	for (int i = 0; i < captured_cards.size(); i++)
	{
		cout << captured_cards[i] << ", ";
	}
}

void Player::displayScore() 
{
	cout << score;
}