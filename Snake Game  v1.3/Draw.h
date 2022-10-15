#pragma once
#include <iostream>
#include <Windows.h>
#include "Snake.h"
#include <conio.h>
#include "Food.h"
#include "StartGame.h"
//#define width 100
//#define height 25
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
	bool GameController();

};


