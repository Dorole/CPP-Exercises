#pragma once

using namespace std;

struct Card
{
	enum Suit
	{
		CLUBS, DIAMONDS, HEARTS, SPADES
	};

	Suit suit = CLUBS;
	int value{};

	string convertFaceCardValueToString();
	string convertSuitToString();
	void printCardName();
};