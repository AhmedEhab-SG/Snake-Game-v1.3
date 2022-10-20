#include "Snake.h"

Snake::Snake(COORD snakePos, int snakeVel) :
	position(snakePos),
	velocity(snakeVel),
	length(3),
	direction('n')
{
	body.push_back(position);
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

	if (position.X > Draw::width - 2) (position.X) = 0;
	else if (position.X < 1) position.X = Draw::width - 2;		// snake moving from side to side in X - axis

	if (position.Y > Draw::height - 2) (position.Y) = 0;			// snake moving from side to side in Y - axis
	else if (position.Y < 1) position.Y = Draw::height - 2;

	body.push_back(position);
	if (body.size() > length) body.erase(body.begin());
}

vector<COORD> Snake::returnBody()
{
	return body;
}
COORD Snake::RealPosition() 
{
	return position;
}

bool Snake::FoodEaten(COORD FoodPosition)
{
	return (FoodPosition.X == position.X && FoodPosition.Y == position.Y);
}

void Snake::Grow()
{
	length++;
}

bool Snake::SnakeCollided()
{
	/*if (position.X < 1 || position.X > Draw::width - 2 ||
		position.Y < 1 || position.Y > Draw::height - 2) return true;*/
	for (int i = 0; i < length - 3; i++)
	{
		if (position.X == body[i].X && position.Y == body[i].Y) return true;
	}
	 return false;
}






