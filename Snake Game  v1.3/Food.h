#pragma once
#include <cstdlib>
#include "Draw.h"

class Food 
{
private:
	COORD fPosition;
public:
	COORD fRange;
	Food();
	void FoodRange();
	void GenerateFood();
	COORD RealPosition();
};

