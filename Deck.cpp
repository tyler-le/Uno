/*
Tyler Le
CS281
Final Project - Uno
*/
#include "Deck.h"



Deck::Deck()
{
	deck = new Card[MAXSIZE];
	length = 0;
}

void Deck::createDeck()
{
	//UNO has 4 zero cards
	int num = 0;

	for (int col = 0; col <= 3; col++)
	{
		deck[length].value = num; //sets each to zero
		deck[length].color = static_cast<Card::Color>(col); //sets each card to a color, iterates through enum
		length++;
	}

	//card value 1-9 , draw-two (10), skip (11), reverse (12)
	for (num = 1; num <= 12; num++)
	{
		for (int x = 0; x < 2; x++)
		{
			for (int col = 0; col <= 3; col++)
			{
				deck[length].value = num;
				deck[length].color = static_cast<Card::Color>(col);
				length++;
			}
		}
	}

	//wild(13) and draw four(14)
	for (num = 13; num <= 14; num++)
	{
		for (int x = 0; x < 4; x++)
		{
			deck[length].value = num;
			deck[length].color = Card::Color::WILD;
			length++;
		}
	}
	
}


void Deck::shuffle() //fisher-yates algorithm
{
	srand(time(NULL));
	for (int i = length - 1; i > 0; i--)
	{
		int j = (rand() % (i + 1));
		std::swap(deck[j], deck[i]);
	}
		
}

void Deck::printDeck()
{	
	for (int i = 0; i < length; i++)
	{
		std::cout << "Length: " << i << std::endl;
		std::cout << "Value: " << deck[i].value << std::endl;
		std::cout << "Color: ";
		toString(deck[i].color);
	}
}

void Deck::pop()
{
	if (isEmpty() == false)
	{
		length--;
	}
}

int Deck::top()
{
	if (isEmpty() == false)
	{
		return length - 1;
	}
	return 0;
}



bool Deck::isEmpty()
{
	if (length == 0)
	{
		return true;
	}

	return false;
}

bool Deck::isFull()
{
	if (length >= MAXSIZE)
	{
		return true;
	}
	return false;
}


void Deck::toString(Card::Color color)
{
	switch (color)
	{
	case Card::Color::BLUE:
		std::cout << "Blue";
		break;

	case Card::Color::GREEN:
		std::cout << "Green";
		break;

	case Card::Color::RED:
		std::cout << "Red";
		break;

	case Card::Color::YELLOW:
		std::cout << "Yellow";
		break;

	case Card::Color::WILD:
		std::cout << "Wild";
		break;
	}
	return;
}

void Deck::valueToString(int value)
{
	
		switch (value)
		{
		case 10:
			std::cout << "Draw Two";
				break;

		case 12:
			std::cout << "Reverse";
				break;

		case 11:
			std::cout << "Skip";
			break;

		case 13:
			std::cout << "Wild";
			break;

		case 14:
			std::cout << "Wild Draw Four";
			break;

		default:
			std::cout << value;
			break;
		}
	
	return;
}


void Deck::dealCard(Player &player) 
{
	player.pushHand(deck[top()]);
	pop();
	return;
}

Card Deck::getCard()
{
	return deck[length-1];
}


Deck::~Deck()
{
}
