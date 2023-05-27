#include <iostream>
#include <vector>
#include <random>
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

void DeckOfCards::initDeck()
{
	for (int i = 0; i < 13; i++)
	{
		int value = i + 1;
		Card newClubsCard{ Card::Suit::CLUBS, value };
		Card newDiamondsCard{ Card::Suit::DIAMONDS, value };
		Card newHeartsCard{ Card::Suit::HEARTS, value };
		Card newSpadesCard{ Card::Suit::SPADES, value };

		deck.push_back(newClubsCard);
		deck.push_back(newDiamondsCard);
		deck.push_back(newHeartsCard);
		deck.push_back(newSpadesCard);
	}
}

bool DeckOfCards::isCardAlreadyDrawn(Card& randomCard)
{
	for (int i = 0; i < drawnCards.size(); i++)
	{
		if (randomCard.suit == drawnCards[i].suit && randomCard.value == drawnCards[i].value)
			return true;
	}

	return false;
}

Card DeckOfCards::drawRandomCard()
{
	random_device randDev;
	mt19937 generator(randDev());

	int min = 0;
	int max = deck.size() - 1;
	uniform_int_distribution<int> distribution(min, max);

	int randomIndex = distribution(generator);
	Card randomCard = deck.at(randomIndex);

	drawnCards.push_back(randomCard);
	deck.erase(deck.begin() + randomIndex);

	return randomCard;
}