#include <iostream>
#include <algorithm>

using namespace std;

bool canDivideByThree(int number)
{
	return number % 3 == 0;
}

bool canDivideByFive(int number)
{
	return number % 5 == 0;
}

bool checkForReplay()
{
	string input;

	cout << "\nIgrati opet? (DA/NE)" << endl;
	cin >> input;

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	while (input != "da" && input != "ne")
	{
		cout << "\nNe razumijem. Igrati opet? (DA/NE)" << endl;
		cin >> input;
	}

	return (input == "da");
}

void getUserInput(int& numberToCheck)
{
	cout << "Broj: ";
	cin >> numberToCheck;
}

void checkNumber()
{
	bool playAgain = true;

	do
	{
		int numberToCheck = 1;
		cout << "\n***************************************" << endl;

		while (!canDivideByThree(numberToCheck) && !canDivideByFive(numberToCheck))
		{
			getUserInput(numberToCheck);

			if (canDivideByThree(numberToCheck) && canDivideByFive(numberToCheck))
			{
				cout << "FizzBuzz!" << endl;

				if (!checkForReplay())
					playAgain = false;
			}
			else if (canDivideByThree(numberToCheck))
			{
				cout << "Fizz" << endl;

				if (!checkForReplay())
					playAgain = false;
			}
			else if (canDivideByFive(numberToCheck))
			{
				cout << "Buzz" << endl;

				if (!checkForReplay())
					playAgain = false;
			}
			else
			{
				continue;
			}
		}

	} while (playAgain);
}