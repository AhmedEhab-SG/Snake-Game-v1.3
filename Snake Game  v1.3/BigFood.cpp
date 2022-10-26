#include "BigFood.h"


BigFood::BigFood()
{
	GenerateBigFood();
}

void BigFood::GenerateBigFood()
{
	FoodRange();
	Bfposition.X = 3 + rand() % fRange.X;
	Bfposition.Y = 3 + rand() % fRange.Y;

}

COORD BigFood::RealPosition()
{
	return Bfposition;
}

