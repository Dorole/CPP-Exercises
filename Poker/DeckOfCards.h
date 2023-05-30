#pragma once
#include <vector>
#include "Card.h"

using namespace std;

struct DeckOfCards
{
	vector<Card> deck{};
	vector<Card> drawnCards{};

	void initDeck();
	bool isCardAlreadyDrawn(Card& randomCard);
	Card drawRandomCard();
};
