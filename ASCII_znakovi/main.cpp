#include <iostream>

using namespace std;

int main()
{
	const unsigned int asciiTableLength = 256;

	for (int i = 0; i < asciiTableLength; i++)
	{
		if (i >= 0 && i < 33)
			cout << i << ": " << "(no displayable character)" << endl;
		else
			cout << i << ": " << static_cast<char>(i) << endl;

	}
}