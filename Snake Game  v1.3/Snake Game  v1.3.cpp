#include <iostream>
#include "Draw.h"
#include "Snake.h"
using namespace std;

int main()
{
	while (true)
	{
		Draw dTest;
		dTest.ClearScreen();
		dTest.Visual();
		dTest.Controls();
	}
};