#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class Snake
{
private:
	COORD position;
	int velocity;
	int length;
	char direction;

public:
	Snake(COORD snakePos, int snakeVel);
	void ChangeDirections(char snakeDirec);
	void SnakeMovement();
	COORD AcctPosition();
};
