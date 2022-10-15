#include "StartGame.h"
#include "Draw.h"

StartGame::StartGame()
{
	logo = R"===(
 .d8888b.                    888                     .d8888b.                                  
d88P  Y88b                   888                    d88P  Y88b                                 
Y88b.                        888                    888    888                                 
 "Y888b.   88888b.   8888b.  888  888  .d88b.       888         8888b.  88888b.d88b.   .d88b.  
    "Y88b. 888 "88b     "88b 888 .88P d8P  Y8b      888  88888     "88b 888 "888 "88b d8P  Y8b 
      "888 888  888 .d888888 888888K  88888888      888    888 .d888888 888  888  888 88888888 
Y88b  d88P 888  888 888  888 888 "88b Y8b.          Y88b  d88P 888  888 888  888  888 Y8b.     
 "Y8888P"  888  888 "Y888888 888  888  "Y8888        "Y8888P88 "Y888888 888  888  888  "Y8888  
    )===";
    cout << logo;
	cout << "\n\n\t\t\t\tPress Y and Enter to start the game: ";
	cin >> input;
	if (input == 'y' || input == 'Y')
	{
		Draw::GameOver = false;
	}
	else
	{
		Draw::GameOver = true;
	}
	system("CLS");
	cout << "Error";
}

void StartGame::ShowScore()
{
	cout << "Game Over your Score is: " << Draw::score;

}
