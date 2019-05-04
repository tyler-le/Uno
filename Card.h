/*
Tyler Le
CS281
Final Project - Uno
*/
#pragma once

class Card
{
private:
	

public:
	enum Color { BLUE, GREEN, RED, YELLOW, WILD };
	Card();
	Color color;
	int value;
	Card(Color color, int value);

	~Card();
};

