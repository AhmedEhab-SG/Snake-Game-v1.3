#include "BigFood.h"


BigFood::BigFood()
{
	GenerateBigFood();
}

void BigFood::GenerateBigFood()
{
	for (int i =0; i < 20; i++ )
	{
		FoodRange();
		Bfposition.X = 3 + rand() % fRange.X;
		Bfposition.Y = 3 + rand() % fRange.Y;

	}
}

COORD BigFood::RealPosition()
{
	return Bfposition;
}

