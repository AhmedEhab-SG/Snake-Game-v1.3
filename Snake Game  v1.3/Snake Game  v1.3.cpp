#include <iostream>
#include <ctime>
#include "Draw.h"
#include "Snake.h"
#include "Food.h"
using namespace std;


int main()
{
	srand((time(NULL)));
	while (!Draw::GameOver)
	{
		Draw dTest;
		dTest.ClearScreen();
		dTest.Visual();
		dTest.Controls();
		dTest.GenerateNewFood();
		dTest.GameController();
	}
};