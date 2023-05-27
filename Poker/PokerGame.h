#pragma once
#include <vector>
#include "Player.h"
#include "Card.h"
#include "DeckOfCards.h"

using namespace std;

struct PokerGame
{
	const int numberOfPlayers = 8;
	const int numberOfCardsEachPlayer = 2;
	const int numberOfCardsOnTable = 5;

	vector<Player> players{};
	vector<Card> table{};
	DeckOfCards deck;

	void initPlayers();
	void dealCardsToPlayers();
	void dealCardsToTable();
	void play();
	void printSituation();
};