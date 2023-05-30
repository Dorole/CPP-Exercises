#include <iostream>
#include <cstring>
#include "digitCalculator.h"

using namespace std;

void askForCustomNumber(char incompleteCreditCardNumber[16])
{
	string validInput("yYnN");
	string input;

	cout << "Would you like to check with your own credit card number? (Y/N) " << endl;
	cin >> input;

	while (input.size() != 1 || validInput.find(input) == string::npos)
	{
		cout << "Invalid input. Please enter Y or N.\n" << endl;
		cin >> input;
	}

	if (input == "y" || input == "Y")
	{
		do
		{
			cout << "Please enter 15 digits." << endl;
			cin >> input;

		} while (input.size() != 15);

		for (int i = 0; i < input.size(); i++)
		{
			incompleteCreditCardNumber[i] = input[i];
		}

		cout << "Alright. This is the number we will use: " << incompleteCreditCardNumber << endl;
	}
	else
	{
		cout << "Alright. We will use the default number: " << incompleteCreditCardNumber << endl;
	}
}

void determineCardType(char incompleteCreditCardNumber[16])
{
	char iin = incompleteCreditCardNumber[0];
	string cardType;

	if (iin == '4')
		cardType = "VISA";
	else if (iin == '2' || iin == '5')
		cardType = "Mastercard";
	else if (iin == '3' && (incompleteCreditCardNumber[1] == '4' || incompleteCreditCardNumber[1] == '7'))
		cardType = "American Express";
	else if (iin == '3')
		cardType = "Diners";
	else if (iin == '6')
		cardType = "Discover";
	else
		cardType = "Type unknown";

	cout << "Card type: " << cardType << endl;

}

void fillCompleteNumberArray(int incompleteNumberArrayLength, int  completeNumberArray[16], char  incompleteCreditCardNumber[16], int  calculation[16])
{
	for (int i = 0; i < incompleteNumberArrayLength; i++)
	{
		completeNumberArray[i] = incompleteCreditCardNumber[i] - '0';
		calculation[i] = completeNumberArray[i];

	}
}

void performCalculations(int incompleteNumberArrayLength, int  calculation[16], int& sum)
{
	for (int i = 0; i < incompleteNumberArrayLength; i++)
	{
		if (i % 2 == 0)
		{
			calculation[i] *= 2;

			if (calculation[i] >= 10)
				calculation[i] -= 9;
		}

		sum += calculation[i];
	}
}

void calculateLastDigit(int& lastDigit, int sum)
{
	lastDigit = 10 - (sum % 10);

	if (sum % 10 == 0)
		lastDigit = 0;

	cout << "Last digit: " << lastDigit << endl;
}

void displayFinalCompleteNumber(int  completeNumberArray[16], int lastDigit, int sizeOfCompleteNumberArray)
{
	completeNumberArray[15] = lastDigit;

	cout << "Final credit card number: ";

	for (int i = 0; i < sizeOfCompleteNumberArray; i++)
	{
		cout << completeNumberArray[i];
	}
}
