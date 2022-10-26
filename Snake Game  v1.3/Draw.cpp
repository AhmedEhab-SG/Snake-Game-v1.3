#include "Draw.h"
#include "BigFood.h"


const int Draw::width = 100;
const int Draw::height = 25;
int Draw::score;
bool Draw::GameOver = false;

Snake snake({ Draw::width / 2 , Draw::height / 2 }, 1); // snake initiliaztion to constractor
Food food; // parameterless constructor
BigFood bigFood; 

void Draw::ClearScreen()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}

void Draw::Visual()
{
	COORD SnakePosition = snake.RealPosition(); // carries real position and drawing
	COORD FoodPosition = food.RealPosition();	// ~ ~ ~
	COORD BigFoodPosition = bigFood.RealPosition();
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
			else if (i == BigFoodPosition.Y && j + 1 == BigFoodPosition.X)
				cout << "@";
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
					if (FoodPosition.X == SnakePosition.X && FoodPosition.Y == SnakePosition.Y		//for not printing food inside the snake
						|| snakeBody[k].Y == FoodPosition.Y && snakeBody[k].X == FoodPosition.X)
					{
						food.GenerateFood();
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

void Draw::GenerateNewBigFood()
{
	if (snake.FoodEaten(bigFood.RealPosition()))
	{
		bigFood.GenerateBigFood();
		snake.BigGrow();
		score += 5;
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
