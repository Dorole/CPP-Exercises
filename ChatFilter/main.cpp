#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string CensorText(string originalString, string wordToCensor, char replacementChar)
{
	string copyInLower = originalString;

	transform(copyInLower.begin(), copyInLower.end(), copyInLower.begin(), ::tolower);

	auto substringPos = copyInLower.find(wordToCensor);

	if (substringPos == string::npos)
	{
		return originalString;
	}

	while (substringPos != string::npos)
	{
		originalString.replace(substringPos, wordToCensor.length(), wordToCensor.length(), replacementChar);
		copyInLower.replace(substringPos, wordToCensor.length(), wordToCensor.length(), replacementChar);

		substringPos = copyInLower.find(wordToCensor, substringPos + 1);
	}

	return originalString;

}

int main()
{
	string input_noCensor = "He's back, He-Who-Must-Not-Be-Named is back!";
	string input_oneCensor = "He's back, the one who's back is Voldemort!";
	string input_twoCensor = "Voldemort is back, VoLdEmOrT is back!";

	const string toCensor = "voldemort";
	char replacementChar = '*';

	//NO WORD TO CENSOR
	cout << "Original string: " << input_noCensor << endl;
	string censoredString = CensorText(input_noCensor, toCensor, replacementChar);
	cout << "Censored string: " << censoredString << endl;
	
	cout << "==================================" << endl;

	//WORD TO CENSOR APPEARS ONCE AT THE END
	cout << "Original string: " << input_oneCensor << endl;
	censoredString = CensorText(input_oneCensor, toCensor, replacementChar);
	cout << "Censored string: " << censoredString << endl;

	cout << "==================================" << endl;

	//WORD TO CENSOR APPEARS TWICE
	cout << "Original string: " << input_twoCensor << endl;
	censoredString = CensorText(input_twoCensor, toCensor, replacementChar);
	cout << "Censored string: " << censoredString << endl;
}