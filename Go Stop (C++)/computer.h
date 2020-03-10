#pragma once
#include "gostop.h"
#include "player.h"

// Class for the computer player 
class Computer : public Player 
{
private:
	vector <string> player_cards;
	vector <string> captured_cards;

public:
	Computer();
};
