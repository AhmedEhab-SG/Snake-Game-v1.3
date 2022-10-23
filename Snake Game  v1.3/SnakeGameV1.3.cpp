#include "Draw.h"
#include "Snake.h"
#include "Food.h"
#include "StartGame.h"


int main()
{
	srand(time(NULL));
	StartGame();
	Draw drawOpj;
	Draw::score = 0;
	while (!Draw::GameOver)
	{
		drawOpj.ClearScreen();
		drawOpj.Visual();
		drawOpj.Controls();
		drawOpj.GenerateNewFood();
		drawOpj.GenerateNewBigFood();
		drawOpj.GameController();
	}
	drawOpj.ShowScore();
};