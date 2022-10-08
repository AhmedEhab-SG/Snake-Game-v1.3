#include "Draw.h"

const int Draw::width = 100;
const int Draw::height = 25;
bool Draw::GameOver = false;
void Draw::ClearScreen()
{
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}
Snake snake({ Draw::width / 2 , Draw::height / 2 } ,1 ); // snake initiliaztion to constractor
Food food; // parameterless constructor
void Draw::Visual()
{
	COORD SnakePosition = snake.RealPosition(); // carries real position and drawing
	COORD FoodPosition = food.RealPosition();	// ~ ~ ~
	for (int i = 0; i < height; i++)
	{
		cout << "#";
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1)
				cout << "#";
			else if (i == SnakePosition.Y && j == SnakePosition.X)
				cout << "0";
			else if (i == FoodPosition.Y && j == FoodPosition.X)
				cout << "@";
			else
				cout << " ";
		}
		cout << "#\n";
	}

}

void Draw::Controls()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w': snake.ChangeDirections('u');
		case 72: snake.ChangeDirections('u');
			break;
		case 's': snake.ChangeDirections('d'); 
		case 80: snake.ChangeDirections('d');
			break;
		case 'a': snake.ChangeDirections('l'); 
		case 75: snake.ChangeDirections('l');
			break;
		case 'd': snake.ChangeDirections('r'); 
		case 77: snake.ChangeDirections('r');
			break;
		}
	}
	snake.SnakeMovement(); 
}

void Draw::GenerateNewFood()
{
	if (snake.FoodEaten(food.RealPosition()))
	{
		food.GenerateFood();
		snake.Grow();
	}
}

bool Draw::GameController()
{
	if (snake.SnakeCollided()) GameOver = true;
	return GameOver;
}


