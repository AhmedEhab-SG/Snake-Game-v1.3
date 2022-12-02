#pragma once

#include <iostream>
#include <Windows.h>
#include "Food.h"
#include "Snake.h"
#include <conio.h>
#include "StartGame.h"
#include <thread>
//#include "BigFood.h"
using namespace std;

class Draw
{
private:

public:
	static const int width, height;
	static bool GameOver;
	static int score;
	void ClearScreen();
	void Visual();
	void Controls();
	void GenerateNewFood();
	void GenerateNewBigFood();
	bool GameController();
	void ShowScore();

};


