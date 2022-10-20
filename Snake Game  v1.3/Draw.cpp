#include "Draw.h"


const int Draw::width = 100;
const int Draw::height = 25;
int Draw::score;
bool Draw::GameOver = false;

Snake snake({ Draw::width / 2 , Draw::height / 2 }, 1); // snake initiliaztion to constractor
Food food; // parameterless constructor

void Draw::ClearScreen()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}

void Draw::Visual()
{
	COORD SnakePosition = snake.RealPosition(); // carries real position and drawing
	COORD FoodPosition = food.RealPosition();	// ~ ~ ~
	vector<COORD> snakeBody = snake.returnBody();// bodyparts 
	cout << "Score: " << score << "\n\n";
	for (int i = 0; i < height; i++)
	{
		cout << "|";
		for (int j = 0; j < width - 2; j++)
		{
			if (i == 0 || i == height - 1)
				cout << "-";
			else if (i == SnakePosition.Y && j + 1 == SnakePosition.X)
				cout << "0";
			else if (i == FoodPosition.Y && j + 1 == FoodPosition.X)
				cout << "\u2022";
			else
			{
				bool checkBody = false;
				for (int k = 0; k < snakeBody.size() - 1; k++)
				{
					if (i == snakeBody[k].Y && j + 1 == snakeBody[k].X)
					{
						cout << 'o';
						checkBody = true;
						break;
					}
				}
				if (!checkBody) cout << ' ';
			}
		}
		cout << "|\n";
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
		score++;
	}
}

bool Draw::GameController()
{
	if (snake.SnakeCollided()) GameOver = true;
	return GameOver;
}

void Draw::ShowScore()
{
	cout << "\n\n\nGame Over your Score is: " << score << "\n\n\n";

}
