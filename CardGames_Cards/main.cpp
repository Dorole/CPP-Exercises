#include <iostream>
#include <random>

using namespace std;

struct Card 
{
	int value{};
};

int generateRandomInt(int min, int max)
{
	random_device randDev;
	mt19937 generator(randDev());

	uniform_int_distribution<int> distribution(min, max);

	return distribution(generator);
}

Card generateRandomCard(int min, int max)
{
	Card newCard{};
	newCard.value = generateRandomInt(min, max);

	return newCard;
}


int main()
{
	Card card{};

	int min = 1;
	int max = 52;

	for (int i = 0; i < 10; i++)
	{
		card = generateRandomCard(min, max);
		cout << "Card value: " << card.value << endl;
	}
}