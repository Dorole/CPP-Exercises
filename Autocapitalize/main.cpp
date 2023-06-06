#include <iostream>

using namespace std;

// capitalize first letter in a sentence
string SimpleCapitalize(string text)
{
	bool capitalize = true;

	for (size_t i = 0; i < text.size(); i++)
	{

		if (capitalize && isalpha(text[i]))
		{
			text[i] = toupper(text[i]);
			capitalize = false;
		}
		else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
			capitalize = true;
	}

	return text;
}

// capitalize first letter in a sentence, turn the rest to lower, 
// unless the word starts with a capital letter
string NotSimpleCapitalize(string text)
{
	bool capitalize = true;
	bool isNewWord = true;

	for (size_t i = 0; i < text.size(); i++)
	{

		if (capitalize && isalpha(text[i]))
		{
			text[i] = toupper(text[i]);
			capitalize = false;
		}
		else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
		{
			capitalize = true;
		}
		else if (isNewWord && isalpha(text[i]))
		{
			isNewWord = false;
		}
		else if (isspace(text[i]) && isupper(text[i + 1]))
		{
			isNewWord = true;
		}
		else
		{
			text[i] = tolower(text[i]);
		}

	}

	return text;

}


int main()
{
	string stringOne = "jeez, Doc, a DeLorean! what the hell did you do to it? \ngrab the camera and start taping, Marty. i'll explain as we go.";
	string stringTwo = "what'd I tell you? eighty-eight miles per hour! temporal displacement occured at exactly 1:02 am and zero seconds. \nChrist Almighty! you disintegrated Einstein!";
	string stringThree = "caLm doWn, Marty. i didn'T disiNteGratE anyThing. thE moLecuLaR struCTURE of bOTh EinStein and tHe car aRe comPletelY iNtAcT.";

	cout << NotSimpleCapitalize(stringThree) << endl;
}