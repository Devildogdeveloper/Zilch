#pragma once

#include <vector>
#include <array>
#include "Player.h"
#include "diceRoll.h"
#include "scoreDice.h"

class scoreDice
{
public:
	bool CheckForWin(int score);
	void MatchPoints(Player& player);

private:
	
	
	bool IsValid(unsigned int& selection, vector<int>& dicePool);
	bool ScoringDice(array<int, 6>& diceCount);
	int Score(vector<int>& dicePool, int die, array<int, 6>& diceCount, array<int, 6>& keptDice);
	bool straight();
	bool fullHouse();
	bool fourOfAKind();
	bool fiveOfAKind();
	bool sixOfAKind();
};

