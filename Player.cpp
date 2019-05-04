/*
Tyler Le
CS281
Final Project - Uno
*/
#include "Player.h"
class Player;

Player::Player()
{
	//this->length = 0;
}

void Player::pushHand(Card deck)
{
	//push 1 deck object into hand

	this->hand.push_back(deck);
	
}

void Player::deleteHand(int position)
{
	for (int i = 0; i < hand.size(); i++)
	{
		if (i == position-1)
		{
			hand.erase(hand.begin()+i);
		}
	}
}

void Player::printHand(Deck deck)
{
	for (int i = 0; i < hand.size(); i++)
	{
		std::cout << i+1 << ". ";
		std::cout << "Color: ";
		deck.toString(hand[i].color);
		std::cout << " | " << "Value: ";
		deck.valueToString(hand[i].value);
		std::cout << std::endl;
		//std::cout << " | " << "Value: " << hand[i].value << std::endl;
	}
}

void Player::setHand(Deck &deck, Player& player) //used only for setting hand at beginning of game
{
	for (int i = 0; i < getHANDSIZE(); i++)
	{
		deck.dealCard(player);
	}
}

Card Player::getHandCard(Player& player, int position)
{
	return this->hand[position - 1];
	//return player.hand[position - 1];
}

int Player::getHANDSIZE()
{
	return 7; //7 cards in hand to start
}

std::string Player::getUserName()
{
	return username;
}

void Player::setUserName(std::string name)
{
	username = name;
}

bool Player::isEmpty(Player& player)
{
	if (hand.size() == 0)
	{
		return true;
	}

	return false;
}


Player::~Player()
{
	//delete hand;
}
