#include <iostream>
#include <vector>
#include <string>

using namespace std;


//Convert char to a value between 0 and 25
int ConvertCharToInt(char c)
{
	if (isalpha(c) && islower(c))
		return c - 'a';
	else
		return -1;
}

char ConvertIntToChar(int i)
{
	if (i >= 0 && i < 26)
		return static_cast<char>(i + 'a');
	else
		return '?';

}

string PerformCaesarCipher(string s, int key, bool encrypt)
{
	vector<unsigned> charValues;
	charValues.reserve(1000);

	for (char c: s)
	{
		if (isalpha(c))
			charValues.push_back(ConvertCharToInt(c));
		else if (isspace(c))
			charValues.push_back(c);
		else
			continue;
	}

	vector<int> encryptedValues;
	encryptedValues.reserve(charValues.size());

	int shiftedValue = 0;
	int operationKey = encrypt ? key : -key;
	
	for (int i = 0; i < charValues.size(); i++)
	{
		if (charValues[i] == ' ')
			shiftedValue = ' ';
		else
			shiftedValue = (charValues[i] + operationKey + 26) % 26;	

		encryptedValues.push_back(shiftedValue);
	}

	string encryptedString;

	for (auto value: encryptedValues)
	{
		char c;
		
		if (value == ' ')
			c = ' ';
		else
			c = ConvertIntToChar(value);

		encryptedString.push_back(c);
	}

	return encryptedString;
}

void Run()
{
	cout << "Enter E if you want to encrypt, D if you want to decrypt." << endl;

	string input;
	bool isChoiceValid = false;
	bool shouldEncrypt = false;

	do
	{
		cin >> input;

		if (input.size() > 1 || (toupper(input[0]) != 'E' && toupper(input[0]) != 'D'))
			cout << "Invalid input. Try again." << endl;
		else
		{
			if (toupper(input[0]) == 'E')
				shouldEncrypt = true;

			isChoiceValid = true;
		}

	} while (!isChoiceValid);

	string encryptionInstructionText = "\nEnter the text you would like to encrypt. ";
	string decryptionInstructionText = "\nEnter the text you would like to decrypt. ";

	shouldEncrypt ? cout << encryptionInstructionText : cout << decryptionInstructionText;

	cout << "Note: Use lowercase letters only." << endl;

	string text;
	cin.ignore();
	getline(cin, text);

	string encryptionInstructionKey = "\nEnter the encryption key (negative number = left shift; positive number = right shift).";
	string decryptionInstructionKey = "\nEnter the decryption key (should be the same key you used when encrypting).";

	shouldEncrypt ? cout << encryptionInstructionKey : cout << decryptionInstructionKey;
	cout << endl;

	int key;
	cin >> key;

	string result = PerformCaesarCipher(text, key, shouldEncrypt);

	string encryptionResult = "\nEncrypted text: " + result;
	string decryptionResult = "\nDecrypted text: " + result;

	shouldEncrypt ? cout << encryptionResult : cout << decryptionResult;
	cout << endl;
}

int main()
{
	Run();
}