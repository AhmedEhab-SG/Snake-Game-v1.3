#pragma once
#include <cstdlib>
#include "Draw.h"

class Food
{
private:
	COORD fPosition;
public:
	Food();
	void GenerateFood();
	COORD RealPosition();
};

