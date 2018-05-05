#include "Player.h"
#include "Game.h"
#include "MenuOptions.h"
#include "messages.h"

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <array>



// Congratulate the Champion
void messages::CongChamp(Player& player)
{
	system("cls");

	cout << "Hey Hey Hey!" << endl;
	cout << "=================" << endl;
	cout << player.Name() << " just kicked your butt! " << "They got" << player.Score() << "points!" << endl;
	cout << "They were probably cheating though" << endl;

	system("pause");
}


// Alert the players the final round has begun
void messages::MatchPoints(Player& player)
{
	system("cls");
	cout << "**********************************************************************" << endl;
	cout << "*ITS THE FINAL ZILCH ROUNDDDDDDD (in the tune of terrible 80's music)*" << endl;
	cout << "**********************************************************************" << endl;
	cout << player.Name() << " is beating everyone with " << player.Score() << "!" << endl;


	system("pause");
}

// Display dice kept this round
void messages::ShowKeep(array<int, 6>& keep)
{
	cout << "**************" << endl;
	cout << "* Kept Dice  *" << endl;
	cout << "**************" << endl;

	for (unsigned int i = 0; i < keep.size(); i++)
	{
		cout << "[" << (i + 1) << "]: " << keep[i];

		if (i != keep.size() - 1)
		{
			cout << ", ";
		}
	}

	cout << endl << endl;
}

// Display current dice pool values
void messages::ShowRolled(vector<int>& dicePool)
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