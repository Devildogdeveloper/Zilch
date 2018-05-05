#pragma once

#include <vector>
#include <array>
#include "Player.h"

class diceRoll
{
private:

	array<int, 6> DiceCounter(vector<int>& dicePool);

	void DiceRoll(vector<int>& dicePool);
	void ShowRolled(vector<int>& dicePool);

public:
	
	
};

