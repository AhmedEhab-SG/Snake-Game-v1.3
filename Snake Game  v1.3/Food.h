#pragma once
#include <cstdlib>
#include "Draw.h"

class Food
{
private:
	COORD fPosition;
	COORD fRange;
public:
	Food();
	void GenerateFood();
	COORD RealPosition();
};

