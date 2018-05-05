#pragma once

#include <vector>
#include <array>
#include "Player.h"

class messages
{
private:
	
public:
	messages();
	~messages();
	void CongChamp(Player& player);
	void MatchPoints(Player& player);
	void ShowKeep(array<int, 6>& keptDice);
	void ShowRolled(vector<int>& dicePool);
};

