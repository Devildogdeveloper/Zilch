#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <array>

#include "Player.h"
#include "Game.h"
#include "MenuOptions.h"
#include "scoreDice.h"





// Check if a player is winning limit
bool scoreDice::CheckForWin(int score)
{
	bool isWinning = score >= 5000 ? true : false;

	return isWinning;
}

// Check if the dice roll has any scoring dice
bool scoreDice::ScoringDice(array<int, 6>& diceCount)
{
	// If there is a 1 or a 5, return true
	if (diceCount[0] >= 1 || diceCount[4] >= 1)
	{
		return true;
	}

	// If no 1 or 5, check for any triples
	for (unsigned int i = 1; i < diceCount.size(); i++)
	{
		if (i == 4) {
			i = 5;
		}

		if (diceCount[i] >= 3) {
			return true;
		}
	}


	// No scoring dice
	return false;
}

// Checks if the selection is a valid die in the dice pool
bool scoreDice::IsValid(unsigned int& selection, vector<int>& dicePool)
{
	if (selection > 0 && selection <= dicePool.size())
	{
		return true;
	}

	return false;
}

// Scores and removes the dice selected by the player
int scoreDice::Score(vector<int>& dicePool, int die, array<int, 6>& dieCount, array<int, 6>& keptDice)
{
	die -= 1;	
	int score = 0;
	int dieValue = dicePool[die];

	// If there are 3 or more dice with the selected value, set aside 3 of the dice
	if (dieCount[dieValue - 1] >= 3)
	{
		int i = 0;
		while (i < 3)
		{
			for (unsigned int k = 0; k < dicePool.size(); k++)
			{
				if (dicePool[k] == dieValue)
				{					
					dicePool.erase(dicePool.begin() + k); // Remove the selected die from the dicepool
					keptDice[dieValue - 1]++; // Increment the dice kept for this turn
					i++;
				}
			}
		}

		// if 3 1's were kept, the score is 1000, otherwise is 100x the die value
		score = dieValue == 1 ? 1000 : dieValue * 100;
	}
	else if (dieValue == 1 || dieValue == 5){			
		dicePool.erase(dicePool.begin() + die);	// Remove selected die from the dicepool
		keptDice[dieValue - 1]++; // Incredment the dice kept for this turn

		// If die is 1, score is 100, otherwise it's 50
		score = dieValue == 1 ? 100 : 50;
	}
	//check for straight
	else if (dieValue == 1 && dieValue == 2 && dieValue == 2 && dieValue == 2 && dieValue == 2) {
		dicePool.erase(dicePool.begin() + die);
		kept[dieValue - 1]++;

		score = dieValue == 1 ? 100 : 50;
	}  else if (straight() == true) {
		score += 1500;
		cout << "\nYou got a straight" << endl;
		cout << "You scored " << score << endl;
	}

	else if (sixOfAKind() == true) {
		score += 3000;
		cout << "\nYou got six of a kind" << endl;
		cout << "You scored " << score << endl;
	}

	else if (fiveOfAKind() == true) {
		score += 2000;
		cout << "\nYou got five of a kind" << endl;
		cout << "You scored " << score << endl;
	}
	
	
	
	
	


	return score;
}
/*
bool scoreDice::straight() {
	for (int i = 0; i < 5; i++) {
		if (DicePool.diceValue[i] + 1 != DicePool.diceValue[i + 1])
			return false;
	}
	diceRoll -= 6;
	return true;
}

bool scoreDice::fullHouse() {
	for () {

	} 

	return true;
}


bool scoreDice::fourOfAKind() {
	for (int i = 0; i < 3; i++) {
		if (diceRoll[i] == rolls[i + 3])
			return true;
	}

	dieValue -= 4;
	return false;
}


bool scoreDice::fiveOfAKind() {
	for (int i = 0; i < 4; i++) {
		if (diceRolls[i] == diceRolls[i + 1] && diceRolls[i + 1] == diceRolls[i + 2]) {
			return true;
		}
	}
	dieValue -= 5;
	return false;
}


bool scoreDice::sixOfAKind() {

	for (int i = 0; i < 5; i++) {
		if (diceRolls[i] != dicRolls[i + 1])
			return false;
	}

	dieValue -= 6;
	return true;
}
*/