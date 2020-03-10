#include "game.h"

/*
====================================================================
							Game
====================================================================
*/

vector<string> Game::layout_pile;
vector<Player*> Game::player_type;

// Clears and prepares values for game, then asks the game type and begins in the corresponding mode.
Game::Game() 
{
	player_type.clear();
	player_type.push_back(new Player());
	player_type.push_back(new Computer());

	layout_pile.clear();

	
	gameName = gameType();
	if (gameName == 'r') { playRound(); }
	else if (gameName == 'm') { playMatch(); }
	else { cout << "ERROR: Fatal Error in Game Type Selection - Class Game\n"; }
}

void Game::display() 
{
	// need to change formatting to be appropriate for gameplay (this is serialization format)
	cout << "====================================================================\n";
	cout << "Round: " << endl << endl;			// needs round #
	cout << "Computer: " << endl;
		cout << "\tScore: ";// needs score #
		player_type[1]->displayScore();
		cout << endl;
		cout << "\tHand: ";
		player_type[1]->displayCards();				// needs computers hand vector
		cout << endl;
		cout << "\tCapture Pile: " << endl;
		player_type[1]->displayCaptured();
		cout << endl << endl;

		cout << "Human: " << endl;
		cout << "\tScore: "; 			// needs score #
		player_type[0]->displayScore();
		cout << endl;
		cout << "\tHand: ";
		player_type[0]->displayCards();				// needs humans hand vector
		cout  << endl;
		cout << "\tCapture Pile: " << endl;
		player_type[0]->displayCaptured();
		cout << endl << endl;

		cout << "Layout: ";		//issues with layout and stockpile
		displayLayout();
		cout << endl << endl;

		cout << "Stock Pile: ";	// needs combo_deck vector from Dealer
		scammer.displayStockpile();
		cout << endl << endl;
		cout << "Next Player: "; 
		scammer.displayTurn();
		cout << endl;

	cout << "====================================================================\n";
}

char Game::gameType() 
{
	char userSelection = ' ';

	cout << "Select the type of game you would like to play.\n";
	while (!(userSelection == 'r' || userSelection == 'm'))
	{
		cout << "Input 'r' for a single round or 'm' for a match: ";
		cin >> userSelection;
		cout << endl;
	}
	
	return userSelection;
}

Player* Game::getPlayerID(int id) 
{ 
	return player_type[id]; 
}

void Game::playMatch() 
{
	char choice = ' ';
	do {
		playRound();
		cout << "\nWould you like to play another round?\n";
		cout << "Input 'y' for yes or 'n' for no: ";
		cin >> choice;
	} while (!( choice == 'n'));
	
}

void Game::displayLayout() 
{
	for(int i = 0; i < layout_pile.size(); i++)
	{
		cout << layout_pile[i] << ", ";
	}
}

// Still needs the interaction/turn taking and decision making.
// Currently just setsup and displays data
void Game::playRound() 
{
	Deck d1;
	Deck d2;

	scammer.combineDecks(d1, d2);

	for (int i = 0; i < 10; i++) 
	{
		scammer.dealCards(player_type[0]);
		scammer.dealCards(player_type[1]);
	}

	scammer.dealLayout(layout_pile);

	// somehow layout is not showing up and stockpile is only 8 cards long
	// they might be switched up

	display();
}
