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


int main()
{
	Card card{};

	int min = 1;
	int max = 52;

	card.value = generateRandomInt(min, max);
	cout << "Card value: " << card.value << endl;

	card.value = generateRandomInt(min, max);
	cout << "Card value: " << card.value << endl;

	card.value = generateRandomInt(min, max);
	cout << "Card value: " << card.value << endl;

	card.value = generateRandomInt(min, max);
	cout << "Card value: " << card.value << endl;

	card.value = generateRandomInt(min, max);
	cout << "Card value: " << card.value << endl;

	card.value = generateRandomInt(min, max);
	cout << "Card value: " << card.value << endl;

	card.value = generateRandomInt(min, max);
	cout << "Card value: " << card.value << endl;

	card.value = generateRandomInt(min, max);
	cout << "Card value: " << card.value << endl;
}