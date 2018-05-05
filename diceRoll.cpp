#include "diceRoll.h"

#include <random>

#include <vector>
#include <iostream>
#include <array>



// A method to roll all the dice in a provided pool
void diceRoll::DiceRoll(vector<int>& dicePool)
{
	random_device rng;

	for (unsigned int i = 0; i < dicePool.size(); i++)
	{
		dicePool[i] = rng() % 6 + 1; // Creates a random number from 1 to 6
	}
}

void diceRoll::ShowRolled(vector<int>& dicePool)
{
	cout << "**************" << endl;
	cout << "* Dice Rolls *" << endl;
	cout << "**************" << endl;

	for (unsigned int i = 0; i < dicePool.size(); i++)
	{
		cout << "| Die " << (i + 1) << ": [" << dicePool[i] << "] |" << endl;
	}

	cout << "**************" << endl << endl;
}

// Counts different dice values in a roll
array<int, 6> diceRoll::DiceCounter(vector<int>& dicePool)
{
	// Create new array and set all values to 0
	array<int, 6> counter = { 0 };

	// Count each die for it's value and add that to the counter array
	for (unsigned int i = 0; i < dicePool.size(); i++)
	{
		counter[dicePool[i] - 1]++;
	}

	return counter;
}