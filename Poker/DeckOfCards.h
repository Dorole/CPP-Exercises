#pragma once

using namespace std;

struct DeckOfCards
{
	vector<Card> deck{};
	vector<Card> drawnCards{};

	void initDeck();
	bool isCardAlreadyDrawn(Card& randomCard);
	Card drawRandomCard();
};
