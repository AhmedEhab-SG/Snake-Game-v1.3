#pragma once
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include "Draw.h"
using namespace std;


class Food
{
private:
	COORD fPosition;
public:
	Food();
	void GenerateFood();
	COORD RealPosition();
};

