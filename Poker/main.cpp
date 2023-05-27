#include <iostream>

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

	string convertCardToString()
	{
		string name{};
		string s_suit;

		//convert value to string
		if (value == 1)
			name = "Ace";
		else if (value == 11)
			name = "King";
		else if (value == 12)
			name = "Queen";
		else if (value == 13)
			name = "Jack";

		//convert suit to string
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

		//hm value se printa kao char ili kao nista - work around
		string cardName;
		if (name != " ")
			cardName = name + " of " + s_suit;
		else
			cardName = value + " of " + s_suit;

		return cardName;
	}
};

int main()
{
	Card card{ HEARTS, 3};
	cout << card.convertCardToString() << endl;
}