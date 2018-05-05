// Player.cpp



#include <string>
#include "Player.h"

using namespace std;
Player::Player()
{
}

// New player constructor
Player::Player(string n) : name(n), score(0), inGame(false)
{
}

// Show name
string Player::Name()
{
	return name;
}

// Add to Score
void Player::AddScore(int value)
{
	score += value;
}

// Show score
int Player::Score()
{
	return score;
}

// set inGame
void Player::SetInGame()
{
	inGame = true;
}

// return inGame status
bool Player::InGame()
{
	return inGame;
}





//The aggressive player will continue if he has less than 500 points in this round or if he has at least two dice to roll
void Player::Alice(int score, void AddScore(int value), string Name) {

	if (diceCount != 3 || score < 500) {
		
	}
	else {
		
	}

}



//The standard player decides to stop if there are less than three dice left to roll
void Player::Stan(int score, void AddScore(int value), string Name) {
	if (diceCount > 2) {
		
	}
	else {
		
	}
	
}




//The timid player will only continue if he has less than 150 points in this round or if he has four or more dice to roll
void Player::Tim(int score, void AddScore(int value), string Name) {
	if (diceCount != 4 || score > 150) {
		
	}
	else {
		
	}

}