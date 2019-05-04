/*
Tyler Le
CS281
Final Project - Uno
*/
#pragma once
#include "Game.h"

class Game;
class Player;
class Deck;
class Global;
class DevTest
{
public:
	DevTest();
	void printDeck(Deck &deck);
	void testMenu(Deck& deck, Player& player, Game game);
	~DevTest();
};

