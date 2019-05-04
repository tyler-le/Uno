/*
Tyler Le
CS281
Final Project - Uno
*/
#pragma once
#include "Game.h"
#include "Windows.h"
#include <iostream>

class Global
{
public:
	Global();

	void pressToGoBack(Game game, Deck deck, Player player, DevTest devtest);
	void clearScreen();
	void intro();

	~Global();
};

