#pragma once
#include <vector>
#include <array>
#include "Player.h"

class Game
{
private:	
	// Inputs
	void ClearInput();
	int GetInput();
	
	// Setup
	void PromptNumPlayers();
	void SetupPlayerNames(vector<Player>& players);	
	void SetupComputerPlayers(vector<Player>& computers);

	
	// Play
	void CongChamp(Player& player);
	void MatchPoints(Player& player);
	void ShowKeep(array<int, 6>& keptDice);
	void ShowRolled(vector<int>& dicePool);
	
	bool CheckForWin(int score);
	
	Player GetChampion(vector<Player> players);

	// Private Loops
	// Turn loop
	int Turn(Player& player)
	{
		vector<int> dicePool(6); // New dice pool of 6 dice
		array<int, 6> keptDice = { 0 }; // Set all kept dice values to 0
		array<int, 6> diceCount = { 0 }; // Variable to count die values
		int turnScore = 0; // Running score for this turn
		bool zilched = false; // Determines if player has zilched
		bool canPass = player.InGame(); // Determines if player can pass their turn
		bool canReroll = false; // Determines if player can reroll the dice
		bool hasPassed = false; // Determines when the player has passed their turn

		unsigned int selection = 1;

		while (!hasPassed)
		{
			// if player has set aside all dice
			if (dicePool.size() == 0)
			{
				// populate dicePool back to 6 dice
				for (int i = 0; i < 6; i++)
				{
					dicePool.push_back(1);
				}
			}

			diceRoll(dicePool);
			canReroll = false;
			canPass = false;

			// Allow player to set aside the rolled dice until they pass or reroll
			do
			{
				system("cls");
				cout << player.Name() << " is rolling" << endl;
				cout << player.Name() << "'s Score: " << player.Score() << endl;
				cout << "Turn Score: " << turnScore << endl << endl;

				ShowRolled(dicePool);
				ShowKeep(keptDice);

				diceCount = DiceCounter(dicePool);

				// If the player has no scoring dice and they can't reroll
				if (!ScoringDice(diceCount) && !canReroll)
				{
					zilched = true; // The player has zilched
					selection = 0; // Automatically select to end their turn
					continue;
				}

				cout << "Enter the die # you wish to keep. Triple values will automatically be kept." << endl;
				cout << "Enter 9 to reroll dice or 0 to end your turn." << endl;
				cout << "Selection: ";

				// If the dice pool is empty, automatically reroll to generate 6 new dice, otherwise get the player's selection
				selection = dicePool.size() == 0 ? 9 : GetInput();

				if (IsValid(selection, dicePool))
				{
					// Add the dice value to turn score
					turnScore += Score(dicePool, selection, diceCount, keptDice);

					canReroll = true; // Player has kept a die and can now reroll the dice

									  // If the player is in the game or they have over 1000 points, the player can end their turn
					canPass = (player.InGame() || turnScore >= 1000) ? true : false;

				}
				// check if the player has selected a valid move, ending turn or rerolling dice
				else if ((selection == 0 && !canPass) || (selection == 9 && !canReroll))
				{
					string msg;

					system("cls");
					cout << "*****************" << endl;
					cout << "*     NOPE!     *" << endl;
					cout << "*****************" << endl;

					msg = selection == 0 ? player.Name() + ", you're not done yet! you gotta roll again!" : player.Name() + " is trying to break the rules!";

					cout << msg << endl << endl;

					selection = 7;

					system("pause");
				}
			} while (selection > 0 && selection != 9);

			// Player selected to end their turn, then they have passed. Otherwise they're rolling dice
			hasPassed = selection == 0 ? true : false;
		}

		system("cls");
		cout << "------------------" << endl;
		cout << player.Name() << "'s turn is over!" << endl;
		cout << "------------------" << endl;

		if (zilched)
		{
			cout << "You ain't got nothing but a zilch " << player.Name() << "!" << endl;
		}
		else
		{
			cout << "Hey " << player.Name() << "!" << " You got " << turnScore << " points from this turn" << "!" << endl;
		}

		system("pause");

		// return 0 if player zilched or turnScore
		return turnScore = zilched ? 0 : turnScore;
	}
	Player Play();

public:
	void MainGameLoop();
};