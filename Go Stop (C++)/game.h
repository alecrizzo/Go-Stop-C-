#pragma once
#include "gostop.h"
#include "dealer.h"
#include "player.h"
#include "deck.h"
#include "computer.h"

class Game 
{
public:
	Game();
	void display();
	void displayLayout();

	Player* getPlayerID(int id);			// Function to get the required playerID (human or computer)

private:
	friend class Save;

	//static Player playerType[];			// did not work for setting up computer with player
	static vector<Player*> player_type;		// does work for setting up computer with player
	static vector<string> layout_pile;
	char gameName;							// Variable for use with the function gameType() (might not need depending on implementation)

	Dealer scammer;							// card dealer 

	char gameType();						// For user to select the game type game or round
	void playRound();						// Function to start one round based on user input from gameType 
	void playMatch();						// Function to start a match based on user input from gameType 

};