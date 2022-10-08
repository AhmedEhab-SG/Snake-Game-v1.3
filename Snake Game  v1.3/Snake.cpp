#include "Snake.h"

Snake::Snake(COORD snakePos, int snakeVel) :
	position(snakePos),
	velocity(snakeVel),
	length(1),
	direction('n')
{

}

void Snake::ChangeDirections(char snakeDirec)
{
	direction = snakeDirec;
}

void Snake::SnakeMovement()
{
	switch (direction)
	{
		case 'u': position.Y -= velocity; break;
		case 'd': position.Y += velocity; break;
		case 'l': position.X -= velocity; break;
		case 'r': position.X += velocity; break;
	}

}

COORD Snake::RealPosition() 
{
	return position;
}

bool Snake::FoodEaten(COORD FoodPosition)
{
	if (FoodPosition.X == position.X && FoodPosition.Y == position.Y)
		return true;
	else return false;

}

void Snake::Grow()
{
	length++;
}

bool Snake::SnakeCollided()
{
	if (position.X < 1 || position.X > Draw::width - 2 || position.Y < 1 || position.Y > Draw::height - 2)
		return true;
	else return false; 
}




