#include <iostream>
#include <string>

using namespace std;

//Prompt the user to enter a std::string and then from that string display a Letter Pyramid

void CreatePyramid(int holderStringLength, int loopCondition, string& inputString, string& holderString)
{
	int insertionIndex = holderStringLength / 2;
	string currentOutput;

	for (int i = 0; i < loopCondition; i++)
	{
		string substrFwd = inputString.substr(0, i + 1);
		string substrBack{};

		int startPos = substrFwd.length() - 2; //skip the last char

		//iterate to the start of substrFwd
		for (int j = startPos; j > -1; j--)
			substrBack.push_back(substrFwd[j]);

		//create output
		currentOutput = substrFwd + substrBack;
		int outputLength = currentOutput.length();

		//replace the middle of emptyString with output	
		holderString.replace(insertionIndex, outputLength, currentOutput);
		insertionIndex--;

		cout << holderString << endl;
	}
}

int main()
{
	string input{};

	cout << "Type in a word/phrase/sentence you want to create a pyramid from." << endl;
	getline(cin, input);
	
	cout << "\n=================================================================\n" << endl;

	//delete spaces from input
	for (auto c : input)
	{
		if (isspace(c))
			input.erase(input.find(c), 1);
	}
	
	//create an empty string and fill it with empty spaces
	string holderString;
	int holderStringLength = (input.length() * 2) - 1;

	for (size_t i = 0; i < holderStringLength; i++)
		holderString.push_back(' ');


	CreatePyramid(holderStringLength, input.size(), input, holderString);	
	
}