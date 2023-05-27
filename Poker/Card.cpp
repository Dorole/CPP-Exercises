#include <iostream>
#include "Card.h"

using namespace std;

string Card::convertFaceCardValueToString()
{
	string name;

	if (value == 1)
		name = "Ace";
	else if (value == 11)
		name = "King";
	else if (value == 12)
		name = "Queen";
	else if (value == 13)
		name = "Jack";

	return name;

}

string Card::convertSuitToString()
{
	string s_suit;

	switch (suit)
	{
	case CLUBS:
		s_suit = "Clubs";
		break;
	case DIAMONDS:
		s_suit = "Diamonds";
		break;
	case HEARTS:
		s_suit = "Hearts";
		break;
	case SPADES:
		s_suit = "Spades";
		break;
	default:
		break;
	}

	return s_suit;
}

void Card::printCardName()
{
	string suit = convertSuitToString();

	if (value > 1 && value <= 10)
		cout << value << " of " << suit << endl;
	else
		cout << convertFaceCardValueToString() << " of " << suit << endl;
}
