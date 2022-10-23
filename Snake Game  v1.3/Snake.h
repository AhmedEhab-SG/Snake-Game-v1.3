#pragma once
#include <ctime>
#include "Draw.h"
#include <vector>
using namespace std;

class Snake
{
private:
	COORD position;
	int velocity;
	int length;
	char direction;
	vector<COORD>body;
public:
	Snake(COORD snakewPos, int snakeVel);
	void ChangeDirections(char snakeDirec);
	void SnakeMovement();
	COORD RealPosition();
	vector<COORD> returnBody();
	bool FoodEaten(COORD FoodPosition);
	void Grow();
	void BigGrow();
	bool SnakeCollided();
};
