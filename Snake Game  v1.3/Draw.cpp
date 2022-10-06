#include "Draw.h"

const int Draw::width = 100;
const int Draw::height = 25;

void Draw::ClearScreen()
{
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}

void Draw::Visual()
{
	for (int i = 0; i < height; i++)
	{
		cout << "#";
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1)
				cout << "#";
			//snake draw and link
			else
				cout << " ";
		}
		cout << "#\n";
	}
}
