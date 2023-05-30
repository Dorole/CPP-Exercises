#include <iostream>
#include <cstring> 
#include "digitCalculator.h"

using namespace std;

int main()
{
	// ***************** VARIABLES *****************

	char incompleteCreditCardNumber[] = "453952452495308";
	int incompleteNumberArrayLength = 15;

	int completeNumberArray[16];
	int calculation[16]; // used for calculations on the completeNumberArrays
	int sum = 0;
	int lastDigit = 0;

	int sizeOfCompleteNumberArray = 16;


	cout << "***************** LUHN CHECK DIGIT CALCULATOR *****************\n" << endl;

	askForCustomNumber(incompleteCreditCardNumber);

	determineCardType(incompleteCreditCardNumber);

	fillCompleteNumberArray(incompleteNumberArrayLength, completeNumberArray, incompleteCreditCardNumber, calculation);

	performCalculations(incompleteNumberArrayLength, calculation, sum);

	calculateLastDigit(lastDigit, sum);

	displayFinalCompleteNumber(completeNumberArray, lastDigit, sizeOfCompleteNumberArray);

	cout << endl;
}