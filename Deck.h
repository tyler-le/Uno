/*
Tyler Le
CS281
Final Project - Uno
*/
#pragma once
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <ctime>

class Player;
class Deck 
{
private:
	
	static const int MAXSIZE = 108; //108 cards in UNO
	int length;

public:
	Deck();
	
	void createDeck();
	void shuffle();
	void printDeck();
	//void push();
	void pop();
	int top();

	bool isEmpty();
	bool isFull();
	void toString(Card::Color color); //converts enum to string.
	void valueToString(int value);
	void dealCard(Player &player);
	Card getCard();
	Card* deck;

	~Deck();
};