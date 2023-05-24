#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

bool isValidGuess(int number, unsigned min, unsigned max)
{
	return number >= min && number <= max;
}

bool vectorContains(vector<unsigned> vector, unsigned number)
{
	auto result = find(vector.begin(), vector.end(), number);
	return  result != vector.end();
}

void requestPlayerGuesses(unsigned rangeMin, unsigned rangeMax, vector<unsigned>& playerGuesses)
{
	int lottoSize = 6;

	cout << "Guess 6 numbers " << rangeMin << "-" << rangeMax << "!" << endl;

	for (int i = 0; i < lottoSize; i++)
	{
		cout << "Number " << (i + 1) << ": ";

		//int playerGuess = i + 1;
		int playerGuess = 0;
		cin >> playerGuess;

		while (!isValidGuess(playerGuess, rangeMin, rangeMax))
		{
			cout << "Your guess must be between " << rangeMin << " and " << rangeMax << ". Guess again : ";
			cin >> playerGuess;
		}

		playerGuesses.push_back(playerGuess);
	}
}

void generateLottoNumbers(unsigned rangeMin, unsigned rangeMax, vector<unsigned>& lottoNumbers)
{
	random_device randDev;
	mt19937 generator(randDev());

	uniform_int_distribution<unsigned> distribution(rangeMin, rangeMax);

	cout << "\nAnd here are the lotto numbers!" << endl;

	for (int i = 0; i < lottoNumbers.size(); i++)
	{
		int randomNumber = 0;

		do
		{
			randomNumber = distribution(generator);

		} while (vectorContains(lottoNumbers, randomNumber));

		lottoNumbers.at(i) = randomNumber;

		cout << "Number " << (i + 1) << ": " << lottoNumbers.at(i) << endl;
	}
}

void checkGuesses(vector<unsigned>& playerGuesses, vector<unsigned>& lottoNumbers)
{
	vector<unsigned> guessedNumbers;

	for (int i = 0; i < playerGuesses.size(); i++)
	{
		if (vectorContains(lottoNumbers, playerGuesses.at(i)))
			guessedNumbers.push_back(playerGuesses.at(i));
	}

	cout << "\n******************************************" << endl;
	cout << "\nYou guessed " << guessedNumbers.size() << " number(s):" << endl;

	if (guessedNumbers.size() > 0)
	{
		for (int i = 0; i < guessedNumbers.size(); i++)
			cout << guessedNumbers.at(i) << endl;
	}
}