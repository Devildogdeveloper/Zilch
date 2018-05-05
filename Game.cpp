

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <array>

#include "Player.h"
#include "Game.h"
#include "MenuOptions.h"
#include "messages.h"
#include "diceRoll.h"
#include "scoreDice.h"


using namespace std;

#pragma region Inputs
// Clears the input stream when invalid characters are used
void Game::ClearInput()
{
	// if an invalid number is detected, clear the input stream
	cin.clear();

	// remove characters from the input stream until a newline or EOF is met			
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Returns an Integer for player input
int Game::GetInput()
{
	unsigned int sel;

	// keep repeating until a valid number is stored in sel
	while (!(cin >> sel))
	{
		ClearInput();

		cout << "Invalid selection. Try again: ";
	}

	ClearInput();

	return sel;
}
#pragma endregion

#pragma region Messages



#pragma endregion

#pragma region Setup
// Prompt the user for the Number of Players
void Game::PromptNumPlayers()
{
	system("cls");
	
	cout << "NEW GAME" << endl;
	cout << "------------------------------" << endl;
	cout << "How many players are there? Please enter a number from 1-4: ";
}

// Setup player names
void Game::SetupPlayerNames(vector<Player>& players)
{
	system("cls");
	cout << "WHO WILL BE THE CHAMPION?" << endl;
	cout << "------------------------------" << endl;
	
	// Get the name for each player in the players vector
	for (unsigned int i = 0; i < players.size(); i++)
	{
		string name;
		
		cout << "What is your name Champion? " << (i + 1) << ": ";
		
		cin >> name;

		ClearInput();

		// create a new player object in the player vector using the name provided
		players[i] = Player(name);	
	}
	
}


void Game::SetupComputerPlayers(vector<Player>& computers) {
	for (unsigned int i = 0; i < computers.size(); i++) {
		string name;

		cout << "How many computers do you want to play with (alice, Stan, Tim)? " << (i + 1) << ": ";

		cin >> name;

		ClearInput();
	}
}
#pragma endregion

#pragma region Play




// Get the name of the player with the highest score
Player Game::GetChampion(vector<Player> players)
{
	Player Champion = players[0];

	for (unsigned int i = 1; i < players.size(); i++)
	{
		if (players[i].Score() > players[i - 1].Score())
		{
			Champion = players[i];
		}
	}

	return Champion;
}
#pragma endregion

#pragma region Private Loops
// Primary Game Loop
Player Game::Play()
{
	Player Champion; // While this string is empty, the game will continue to loop
	int numOfPlayers = 0; // Int to hold the number of players
	int playerTurn = 0; // Int that keeps track of which players turn it is, based on vector index
	int firstToWin = -1; // Int to mark the first players turn that has hit 10k
	int turnScore = 0; // The value the player has scored this turn

	PromptNumPlayers();

	// Loop until players is at least 2
	while (!(numOfPlayers > 1))
	{
		numOfPlayers = GetInput();

		if (numOfPlayers < 2)
		{
			cout << "Invalid number of players. Must be more than 1." << endl;
			cout << "Try again: ";
		}
	}

	vector<Player> players(numOfPlayers); // generate a vector to hold Player objects based on number of players

	SetupPlayerNames(players);

	//WelcomePlayers(players);

	// Continue looping until a Champion is declared
	while (Champion.Name() == "") 
	{
		// Return to first players turn if necessary
		if (playerTurn == players.size())
		{
			playerTurn = 0;
		}

		// The game is over if all players have had a turn after a player reaches 10k
		if (firstToWin >= 0 && playerTurn == firstToWin)
		{
			Champion = GetChampion(players);
			continue;
		}

		// Run a turn for a player and put their score into the turnScore variable
		turnScore = Turn(players[playerTurn]);

		// If the player has not entered the game and they score more than the meld points
		if (!players[playerTurn].InGame() && turnScore >= 1000)
		{
			players[playerTurn].SetInGame(); // put player in the game
		}

		// add turnscore to players score
		if (turnScore > 0)
		{
			players[playerTurn].AddScore(turnScore);
		}

		// Check if players score is over winning threshold
		if (firstToWin == -1 && CheckForWin(players[playerTurn].Score()))
		{
			MatchPoints(players[playerTurn]);

			firstToWin = playerTurn;
		}

		playerTurn++; // Send to next players turn
	}

	return Champion;
}

#pragma endregion

void Game::MainGameLoop()
{
	bool quit = false;
	unsigned int selection;
	Player Champion;

	while (!quit)
	{
		MenuOptions::ShowMenu();
		selection = GetInput();

		switch (selection)
		{
		case 1:	// New Game
			Champion = Play();
			CongChamp(Champion);
			break;
		case 2:	// Quit
			quit = true;
			break;
		default: // Anything else
			break;
		}		
	}	
}