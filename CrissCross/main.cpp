#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	functions functions;

	char grid[3][3];
	char currentPlayer = 'x';

	int row = 0;
	int column = 0;

	bool shouldPlay = true;

	while (shouldPlay)
		functions.handleGameplay(grid, currentPlayer, row, column, shouldPlay);
}