#include <iostream>
#include <vector>
#include "functions.h"

using namespace std;

int main()
{
	vector<unsigned> playerGuesses;
	vector<unsigned> lottoNumbers = {0, 0, 0, 0, 0, 0};
	
	unsigned rangeMin = 1;
	unsigned rangeMax = 45;

	requestPlayerGuesses(rangeMin, rangeMax, playerGuesses);

	generateLottoNumbers(rangeMin, rangeMax, lottoNumbers);

	checkGuesses(playerGuesses, lottoNumbers);
}
