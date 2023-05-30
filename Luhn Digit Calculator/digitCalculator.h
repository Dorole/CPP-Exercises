#pragma once

void askForCustomNumber(char  incompleteCreditCardNumber[16]);

void determineCardType(char incompleteCreditCardNumber[16]);

void fillCompleteNumberArray(int incompleteNumberArrayLength, int  completeNumberArray[16], char  incompleteCreditCardNumber[16], int  calculation[16]);

void performCalculations(int incompleteNumberArrayLength, int  calculation[16], int& sum);

void calculateLastDigit(int& lastDigit, int sum);

void displayFinalCompleteNumber(int  completeNumberArray[16], int lastDigit, int sizeOfCompleteNumberArray);


