#include "Food.h"

Food::Food()
{
	GenerateFood();
}

void Food::GenerateFood()
{
	fPosition.X = (rand() % Draw::width - 3) + 3;
	fPosition.Y = (rand() % Draw::height - 3) + 3;
}

COORD Food::RealPosition()
{
	return fPosition;
}



