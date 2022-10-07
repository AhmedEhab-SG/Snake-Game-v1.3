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


