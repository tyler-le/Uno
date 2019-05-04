/*
Tyler Le
CS281
Final Project - Uno
*/
#include "DevTest.h"


DevTest::DevTest()
{
}

void DevTest::printDeck(Deck &deck)
{
	deck.printDeck();
}

void DevTest::testMenu(Deck& deck, Player& player, Game game)
{
	int choice;

	std::cout << "Which option would you like to test?" << std::endl << std::endl;
	std::cout << "1. Create shuffled deck" << std::endl;
	std::cout << "2. Push Hand" << std::endl;
	std::cout << "3. Options 1 and 3 together" << std::endl;
	std::cout << "4. Create Player Array" << std::endl;
	std::cout << "5. Test Draw2 and Draw4" << std::endl;
	std::cout << "6. Test Intro" << std::endl;
	std::cout << "7. Play" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		deck.createDeck();
		deck.shuffle();
		printDeck(deck);
		break;

	case 2:
		deck.dealCard(player);
		player.printHand(deck);
		
		break;

	case 3:
		deck.createDeck();
		deck.shuffle();
		printDeck(deck);
		std::cout << "/////////HAND////////" << std::endl;
		deck.dealCard(player);
		player.printHand(deck);
		std::cout << "/////////HAND////////" << std::endl;
		printDeck(deck);
		break;

	case 4:
		deck.createDeck();
		deck.shuffle();
		game.createPlayerVector(deck);
		player.printHand(deck);
		break;

	case 5:
		deck.createDeck();
		deck.shuffle();
		game.createPlayerVector(deck);
		//game.drawTwo(deck, 2, 2);
		break;
	case 6:
	
		break;

	case 7:
		game.playGame(player, game, deck);
		break;
	default:
		std::cout << "Invalid Input" << std::endl;
	}

}


DevTest::~DevTest()
{
}
