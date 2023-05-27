#include <iostream>
#include <random>
#include "Player.h"

using namespace std;

void Player::placeBet(unsigned value)
{
	chipValue -= value;
}

void Player::receiveCard(Card card)
{
	myCards.push_back(card);
}