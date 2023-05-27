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

struct Chip 
{
	unsigned value{};
};

enum Suit
{
	CLUBS, DIAMONDS, HEARTS, SPADES 
};

struct Card
{
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
			Card newClubsCard{ CLUBS, value };
			Card newDiamondsCard{ DIAMONDS, value };
			Card newHeartsCard{ HEARTS, value };
			Card newSpadesCard{ SPADES, value };

			deck.push_back(newClubsCard);
			deck.push_back(newDiamondsCard);
			deck.push_back(newHeartsCard);
			deck.push_back(newSpadesCard);
		}
	}

	//bool isCardAlreadyDrawn(Card& randomCard)
	//{
	//	for (int i = 0; i < drawnCards.size(); i++)
	//	{
	//		if (randomCard.suit == drawnCards[i].suit && randomCard.value == drawnCards[i].value)
	//			return true;
	//	}

	//	return false;
	//}

	Card drawRandomCard()
	{
		random_device randDev;
		mt19937 generator(randDev());

		int min = 0;
		int max = deck.size();
		uniform_int_distribution<int> distribution(min, max);

		/*int randomIndex{};
		Card randomCard{};*/

		//do
		//{
		//	randomIndex = distribution(generator);
		//	randomCard = deck.at(randomIndex);

		//} while (isCardAlreadyDrawn(randomCard));

		int randomIndex = distribution(generator);
		Card randomCard = deck.at(randomIndex);;

		drawnCards.push_back(randomCard);
		deck.erase(deck.begin() + randomIndex);
				
		return randomCard;
	}

};


int main()
{
	Card card{ HEARTS, 3 };
	DeckOfCards deck;

	card.printCardName();
	deck.initDeck();
	cout << deck.deck.size() << endl;

	for (int i = 0; i < 5; i++)
	{
		Card newCard = deck.drawRandomCard();
		cout << "New card: ";
		newCard.printCardName();
		cout << "Deck size: " << deck.deck.size() << endl;
		cout << "Drawn cards: " << deck.drawnCards.size() << endl;
	}
}