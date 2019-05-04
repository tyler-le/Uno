/*
Tyler Le
CS281
Final Project - Uno
*/
#include "Game.h"
class DevTest;

bool reverseCard = false;
bool skipCard = false;

Game::Game()
{
	Deck deck;
}

void Game::createPlayerVector(Deck &deck)
{
	
	std::string userName;
	std::cout << "Please enter the amount of players: ";
	std::cin >> amountOfPlayers;

	if (amountOfPlayers < 2 || amountOfPlayers>10)
	{
		if (amountOfPlayers < 2)
		{
			std::cout << "Sorry! Not enough players." << std::endl;
		}

		if (amountOfPlayers > 10)
		{
			std::cout << "Sorry! Too many players." << std::endl;
		}
	}

	else
	{
		std::cout << "Please enter the names of each player." << std::endl;
		std::cin.ignore();

		for (int i = 0; i < amountOfPlayers; i++)
		{
			Player* player = new Player;
			playerVector.push_back(player);
		
			std::cout << "Player " << i+1 << ": ";

			std::getline(std::cin, userName);

			playerVector[i]->setUserName(userName);
			playerVector[i]->setHand(deck, *player);
			player->printHand(deck);
		}
	}

	system("PAUSE");
	system("CLS");

return;
}

void Game::menu(Deck& deck, Player& player, Game game, DevTest devtest)
{
	int choice;

	std::cout << "UNO" << std::endl;
	std::cout << "1. Play Game" << std::endl;
	std::cout << "2. Read Rules" << std::endl;
	std::cout << "3. Developer Testing" << std::endl;
	std::cout << "4. Quit" << std::endl;

	do
	{
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cout << "Play Game" << std::endl;
			break;

		case 2:
			std::cout << "Read Rules" << std::endl;
			break;

		case 3:
			std::cout << "Developer Testing" << std::endl;
			devtest.testMenu(deck, player, game);
			break;

		case 4:
			exit(0);
			break;

		default:
			std::cout << "Invalid choice. Please choose again." << std::endl;
		}
		//clear screen
	} while (choice < 1 || choice >4);
}

void Game::iterateTurn(Player& player, Deck& deck)
{
	while (win(player) == false)
	{
		for (int playerIndex = 0; playerIndex < playerVector.size(); playerIndex++)
		{
			if (skipCard == true)
			{
				playerIndex--;
				playerIndex = skip(player, deck, playerIndex);
			}

			if (reverseCard == true)
			{
				
			}

			skipCard = false;
			//reverseCard = false;
			//change i here if skipping
			drawOrPlay(player, deck, playerIndex);

		}
	}
}


void Game::drawOrPlay(Player& player, Deck& deck, int playerIndex)
{
	int option, chooseOrDraw;
	bool proceed = false;
	
	do
	{
		
		if (deck.isEmpty() == true)
		{
			//inplay to deck
			for (int i = 0; i < (inPlay.size() - 1); i++)
			{
			
				//inPlay[i] = *deck.; need to create pushCard for deck
				
			}
		}

		std::cout << "It is currently " << playerVector[playerIndex]->getUserName() << "'s" << " turn." << std::endl << std::endl;
		std::cout << "The card you must match is: " << std::endl;

		//present card
		deck.toString(inPlay.front().color);
		std::cout << " ";
		deck.valueToString(inPlay.front().value);
		std::cout << std::endl << std::endl;


		std::cout << "[1] Draw Card " << std::endl;
		std::cout << "[2] Play Card" << std::endl;
		std::cout << "Pick an option. " << std::endl;
		std::cin >> option;

		switch (option)
		{
		case 1:

			std::cout << "You have taken:" << std::endl;
			std::cout << "Color: ";
			deck.toString(deck.getCard().color);
			std::cout << " | " << "Value: ";
			deck.valueToString(deck.getCard().value);

			deck.dealCard(*playerVector[playerIndex]);
			std::cout << std::endl;
			proceed = false;

			break;

		case 2:
			std::cout << "Please choose a card or press 0 to draw a card. " << std::endl;
			playerVector[playerIndex]->printHand(deck);
			std::cin >> chooseOrDraw;

			if (chooseOrDraw == 0)
			{
				//draw card
				std::cout << "You have taken:" << std::endl;
				std::cout << "Color: ";
				deck.toString(deck.getCard().color);
				std::cout << " | " << "Value: ";
				deck.valueToString(deck.getCard().value);

				deck.dealCard(*playerVector[playerIndex]);
				std::cout << std::endl;
				proceed = false;
			}

			else
			{
				//choose
				//validate
				proceed = chooseCard(player, deck, chooseOrDraw, playerIndex);
			}

			break;
		}

		system("PAUSE");
		system("CLS");

	} while (proceed == false);
}

bool Game::chooseCard(Player& player, Deck& deck, int chooseOrDraw, int playerIndex)
{
	bool specialCard = false;
	

	//find card
	playerVector[playerIndex]->getHandCard(player, chooseOrDraw);

	//validate
	if (validate(player, playerIndex, chooseOrDraw) == true)
	{

		//checks if special card
		{
			if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value >= 10 && playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value <= 14)
			{
				specialCard = true;
			}
		}


		//delete from hand, insert to inPlay
		if (specialCard == true)
		{
			ifSpecialCard(player, deck, chooseOrDraw, playerIndex);
		}

		else
		{
			inPlay.insert(inPlay.begin(), playerVector[playerIndex]->getHandCard(player, chooseOrDraw));
		}

			playerVector[playerIndex]->deleteHand(chooseOrDraw);
		
		return true;
	}

	else
	{
		std::cout << "You cannot play this card!" << std::endl;
	}

	return false;
}


bool Game::validate(Player& player, int playerIndex, int chooseOrDraw)
{
	if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == inPlay.front().value || playerVector[playerIndex]->getHandCard(player, chooseOrDraw).color == inPlay.front().color)
	{
		return true;
	}

	if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 13 || playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 14)
	{
		return true;
	}


	else
	{
		return false;
	}
}


bool Game::win(Player& player)
{

	if (player.isEmpty(player) == true)
	{
		//you win
		std::cout << "You win" << std::endl;
	}

	return false;
}

void Game::playGame(Player& player, Game game, Deck& deck)
{
	//cout intro();
	deck.createDeck();
	deck.shuffle();

	createPlayerVector(deck);

	//start off game by placing a single card down
	inPlay.push_back(deck.getCard());
	deck.pop();

	//remove choose card from hand
	//pop off deck to start game (starting card)
	while (win(player) == false)
	{
		iterateTurn(player, deck);
	}

}

void Game::ifSpecialCard(Player& player, Deck& deck, int chooseOrDraw, int &playerIndex)
{
	if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 13)
	{
		//wild - change color
		int choice;

		std::cout << "What color would you like to choose?" << std::endl;
		std::cout << "[1] BLUE" << std::endl;
		std::cout << "[2] GREEN" << std::endl;
		std::cout << "[3] RED" << std::endl;
		std::cout << "[4] YELLOW" << std::endl;

		std::cin >> choice;

		//change color
		inPlay.insert(inPlay.begin(), playerVector[playerIndex]->getHandCard(player, chooseOrDraw));
		inPlay.front().color = static_cast<Card::Color>(choice - 1);
	}

	

	else if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 10) //draw2
	{
		drawTwo(player, deck, chooseOrDraw, playerIndex);
	}

	else if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 11) //skip
	{
		//i want to set this playerIndex to "i" in iterateTurns
		playerIndex = skip(player, deck, playerIndex); //(playerIndex + 2) % playerVector.size();
		skipCard = true;
	}

	else if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 12) //reverse
	{
		reverseCard = true;
		//reverse(player, deck, chooseOrDraw, playerIndex);
	}

	else if (playerVector[playerIndex]->getHandCard(player, chooseOrDraw).value == 14) //draw4
	{
		wildDrawFour(player, deck, chooseOrDraw, playerIndex);
	}
}

void Game::reverse(Player& player, Deck& deck, int chooseOrDrawint, int playerIndex)
{
	for ((playerVector.size()-1); int i = 0; i--)
	{
		drawOrPlay(player, deck, i);
		win(player);
	}
}

int Game::skip(Player& player, Deck& deck, int &playerIndex)
{
	//skip
	playerIndex = (playerIndex + 2) % playerVector.size();
	return playerIndex;
}

void Game::drawTwo(Player& player, Deck& deck, int chooseOrDraw, int playerIndex)
{
	if (playerIndex != (playerVector.size() - 1))
	{
		for (int i = 0; i < 2; i++)
		{
			deck.dealCard(*playerVector[playerIndex + 1]);
		}

		std::cout << playerVector[playerIndex + 1]->getUserName() << " has received two cards." << std::endl;
	}



	else if (playerIndex == (playerVector.size() - 1))
	{
		//at end of vector
		for (int i = 0; i < 2; i++)
		{
			deck.dealCard(*playerVector[0]);
		}
		std::cout << playerVector[0]->getUserName() << " has received two cards." << std::endl;
	}
}

void Game::wildDrawFour(Player& player, Deck& deck, int chooseOrDraw, int playerIndex)
{
	//wild draw4

	//prompt for color change
	int choice;

	std::cout << "What color would you like to choose?" << std::endl;
	std::cout << "[1] BLUE" << std::endl;
	std::cout << "[2] GREEN" << std::endl;
	std::cout << "[3] RED" << std::endl;
	std::cout << "[4] YELLOW" << std::endl;

	std::cin >> choice;

	//change color
	inPlay.insert(inPlay.begin(), playerVector[playerIndex]->getHandCard(player, chooseOrDraw));
	inPlay.front().color = static_cast<Card::Color>(choice - 1);

	if (playerIndex != (playerVector.size() - 1))
	{
		for (int i = 0; i < 4; i++)
		{
			deck.dealCard(*playerVector[playerIndex + 1]);
		}

		std::cout << playerVector[playerIndex + 1]->getUserName() << " has received four cards." << std::endl;
	}

	else if (playerIndex == (playerVector.size() - 1))
	{
		//at end of vector
		for (int i = 0; i < 4; i++)
		{
			deck.dealCard(*playerVector[0]);
		}

		std::cout << playerVector[0]->getUserName() << " has received four cards." << std::endl;
	}
}


Game::~Game()
{

}
