#pragma once
#include "gostop.h"
#include "player.h"

// Class for the computer player implementation
// Computer is to be an inhereted class of player so that they could be used 
// as if there was no such thing as a computer, and it was a human v human game.

class Computer : public Player 
{
public:
	Computer();
private:
	vector <string> player_cards;
	vector <string> captured_cards;

};
