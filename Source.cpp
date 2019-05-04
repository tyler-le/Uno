/*
Tyler Le
CS281
Final Project - Uno
*/

#include "Game.h"
#include "Deck.h"
#include "Player.h"
#include "Global.h"




int main()
{
	
	
	Game game;
	Deck deck;
	Player player;
	DevTest devtest;
	Global global;

	//system("mode 650");
	//global.intro();
	
	game.menu(deck, player, game, devtest);
	
	return 0;
}
