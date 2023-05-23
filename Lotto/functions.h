#pragma once
#include<vector>

using namespace std;

bool isValidGuess(int number, unsigned min, unsigned max);

bool vectorContains(vector<unsigned> vector, unsigned number);

void generateLottoNumbers(unsigned rangeMin, unsigned rangeMax, vector<unsigned>& lottoNumbers);

void requestPlayerGuesses(unsigned rangeMin, unsigned rangeMax, vector<unsigned>& playerGuesses);

void checkGuesses(vector<unsigned>& playerGuesses, vector<unsigned>& lottoNumbers);
