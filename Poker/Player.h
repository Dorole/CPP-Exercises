#pragma once
#include <vector>
#include "Card.h"

using namespace std;

struct Player
{
	unsigned chipValue = 50;
	vector<Card> myCards{};

	void placeBet(unsigned value);
	void receiveCard(Card card);
};