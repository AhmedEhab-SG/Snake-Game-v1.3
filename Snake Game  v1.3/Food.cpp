#include "Food.h"

Food::Food()
{
	GenerateFood();
}

void Food::GenerateFood()
{
	fPosition.X = (rand() % Draw::width - 3) + 1;
	fPosition.Y = (rand() % Draw::height - 3) + 1;
}

COORD Food::RealPosition()
{
	return fPosition;
}



