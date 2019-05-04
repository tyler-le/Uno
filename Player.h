/*
Tyler Le
CS281
Final Project - Uno
*/
#pragma once

#include <vector>
#include <iostream>
#include "Deck.h"
#include "Card.h"

class Deck;
class Player
{
private:
	int length;
	std::string username; //can indicate whos turn / wins
	static const int HANDSIZE = 7;
	std::vector<Card> hand;

public:
	Player();
	void pushHand(Card deck); 
	void deleteHand(int position);
	void printHand(Deck deck);
	void setHand(Deck &deck, Player& player); 
	Card getHandCard(Player& player, int position);
	int getHANDSIZE();
	std::string getUserName();
	void setUserName(std::string name);
	bool isEmpty(Player& player); //hand is empty

	~Player();
};

