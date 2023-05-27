#include <iostream>
#include <vector>
#include "PokerGame.h"

using namespace std;

void PokerGame::initPlayers()
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		Player player;
		players.push_back(player);
	}
}

void PokerGame::dealCardsToPlayers()
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		for (int y = 0; y < numberOfCardsEachPlayer; y++)
		{
			Card randomCard = deck.drawRandomCard();
			players[i].Player::myCards.push_back(randomCard);
		}
	}
}

void PokerGame::dealCardsToTable()
{
	for (int i = 0; i < numberOfCardsOnTable; i++)
	{
		Card randomCard = deck.drawRandomCard();
		table.push_back(randomCard);
	}
}

void PokerGame::play()
{
	initPlayers();
	deck.initDeck();

	dealCardsToPlayers();
	dealCardsToTable();
}

void PokerGame::printSituation()
{
	for (int i = 0; i < numberOfPlayers; i++)
	{
		cout << "\n***** Player " << (i + 1) << " *****" << endl;
		Player currentPlayer = players[i];

		for (int j = 0; j < numberOfCardsEachPlayer; j++)
		{
			Card thisCard = currentPlayer.Player::myCards[j];
			thisCard.printCardName();
		}
	}

	cout << "\n***** Table *****" << endl;

	for (int i = 0; i < table.size(); i++)
	{
		table[i].printCardName();
	}
}