/*
Tyler Le
CS281
Final Project - Uno
*/
#pragma once
#include "Player.h"
#include "DevTest.h"
#include <algorithm>

class Player;
class DevTest;
class Deck;
class Global;
#include <string>
#include <vector>


class Game
{
private:
	int amountOfPlayers;
	std::vector<Player*> playerVector;
	std::vector<Card> inPlay; //cards in play

public:
	Game();
	void createPlayerVector(Deck& deck);
	void menu(Deck &deck, Player &player, Game game, DevTest devtest);
	void iterateTurn(Player& player, Deck& deck);
	void drawOrPlay(Player& player, Deck& deck, int i);
	bool chooseCard(Player& player, Deck& deck, int chooseOrDraw, int playerIndex);
	bool validate(Player& player, int playerIndex, int chooseOrDraw);
	bool win(Player& player);
	void playGame(Player& player, Game game, Deck& deck);

	void ifSpecialCard(Player& player, Deck& deck, int chooseOrDrawint,int &playerIndex);
	void reverse(Player& player, Deck& deck, int chooseOrDrawint, int playerIndex);
	int skip(Player& player, Deck& deck, int &playerIndex);//fix
	void drawTwo(Player& player, Deck& deck, int chooseOrDraw, int playerIndex); //implement modulus
	void wild();
	void wildDrawFour(Player& player, Deck& deck, int chooseOrDraw, int playerIndex);//implement modulus
	
	~Game();
};

