#pragma once
#include "gostop.h"
#include "deck.h"

// Class for a player (needs to be used with inheritance for the computer)
class Player 
{
public:
	Player();

	template <typename T>
	void drawCard(T d);
	void takeCard(string card);
	void pairCards(string card);
	int totalCards();
	void displayCards();
	void displayCaptured();
	void displayScore();

private:
	vector <string> player_cards;
	vector <string> captured_cards;
	int score;

};