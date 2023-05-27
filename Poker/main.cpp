#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

#pragma region TASKOVI
//struct Player
//Player ima cipove i 2 karte

//cipove za sad stavi kao struct koji ima samo vrijednost
// -- BACKLOG: treba im pripisati boje i svaka boja da ima svoju vrijednost

//struct karta - ima boju i broj
//boja/suit - enum - mozda ipak bolje nesto kroz kaj moze loop?
//three court cards (face cards), King, Queen and Jack
//ten numeral cards or pip cards, from one (Ace) to ten

//struct PokerDeckOfCards - spil od 52 karte
//loop kroz sve karte i svakoj postavi vrijednost (initializeDeck())
//drawRandomCard() - izvlaci 1 random kartu, ali ne smije se ponovno izvuci dok se ne resetira spil 
// -- spremaj izvucene karte u zaseban vector, ako vector vec ima kartu, loop dalje

//struct PokerGame - 8 igraca i 1 spil
// -- BACKLOG: potencijalno sadrzi i karte na stolu, kolicinu cipova, tko je na redu itd.
//play() - podjela karata (pre-flop), 5 karata na stolu, bez ulaganja

//ispis svih karata svih igraca i karata na stolu
#pragma endregion

struct Card
{
	enum Suit
	{
		CLUBS, DIAMONDS, HEARTS, SPADES
	};

	Suit suit = CLUBS;
	int value{};

	string convertFaceCardValueToString()
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

	string convertSuitToString()
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

	void printCardName()
	{
		string suit = convertSuitToString();

		if (value > 1 && value <= 10)
			cout << value << " of " << suit << endl;
		else
			cout << convertFaceCardValueToString() << " of " << suit << endl;
	}
};

struct DeckOfCards
{
	vector<Card> deck{};
	vector<Card> drawnCards{};

	void initDeck()
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

	bool isCardAlreadyDrawn(Card& randomCard)
	{
		for (int i = 0; i < drawnCards.size(); i++)
		{
			if (randomCard.suit == drawnCards[i].suit && randomCard.value == drawnCards[i].value)
				return true;
		}

		return false;
	}

	Card drawRandomCard()
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
};

struct Player 
{
	unsigned chipValue = 50;
	vector<Card> myCards{};

	void placeBet(unsigned value)
	{
		chipValue -= value;
	}

	void receiveCard(Card card)
	{
		myCards.push_back(card);
	}
};

struct PokerGame 
{
	const int numberOfPlayers = 8;
	const int numberOfCardsEachPlayer = 2;
	const int numberOfCardsOnTable = 5;

	vector<Player> players{};
	vector<Card> table{};
	DeckOfCards deck;

	void initPlayers()
	{
		for (int i = 0; i < numberOfPlayers; i++)
		{
			Player player;
			players.push_back(player);
		}
	}

	void dealCardsToPlayers()
	{
		for (int i = 0; i < numberOfPlayers; i++)
		{
			for (int y = 0; y < numberOfCardsEachPlayer; y++)
			{
				Card randomCard = deck.drawRandomCard();
				players[i].myCards.push_back(randomCard);
			}
		}
	}

	void dealCardsToTable()
	{
		for (int i = 0; i < numberOfCardsOnTable; i++)
		{
			Card randomCard = deck.drawRandomCard();
			table.push_back(randomCard);
		}
	}

	void play()
	{
		initPlayers();
		deck.initDeck();

		dealCardsToPlayers();
		dealCardsToTable();
	}

	void printSituation()
	{
		for (int i = 0; i < numberOfPlayers; i++)
		{
			cout << "\n***** Player " << (i + 1) << " *****" << endl;
			Player currentPlayer = players[i];

			for (int j = 0; j < numberOfCardsEachPlayer; j++)
			{
				Card thisCard = currentPlayer.myCards[j];
				thisCard.printCardName();
			}
		}

		cout << "\n***** Table *****" << endl;

		for (int i = 0; i < table.size(); i++)
		{
			table[i].printCardName();
		}
	}
};

int main()
{
	PokerGame game;
	game.play();

	cout << "***** POKER GAME - INITIAL SITUATION *****" << endl;
	game.printSituation();
}