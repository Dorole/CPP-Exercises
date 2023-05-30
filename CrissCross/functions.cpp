#include <iostream>
#include <cstring>
#include <algorithm>
#include "functions.h"

using namespace std;

void functions::drawGrid(char  grid[3][3])
{
	cout
		<< endl
		<< "  1 2 3" << endl
		<< "1 " << grid[0][0] << "|" << grid[0][1] << "|" << grid[0][2] << endl
		<< "  -+-+-" << endl
		<< "2 " << grid[1][0] << "|" << grid[1][1] << "|" << grid[1][2] << endl
		<< "  -+-+-" << endl
		<< "3 " << grid[2][0] << "|" << grid[2][1] << "|" << grid[2][2] << endl;
}

void functions::initializeGrid(char  grid[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			grid[i][j] = '.';
		}
	}
}

bool functions::isFieldAvailable(char  grid[3][3], int& row, int& column)
{
	if (row == 0 && column == 0)
		return false;

	if (grid[row - 1][column - 1] != '.')
	{
		cout << "!!! The chosen field is not empty !!!" << endl;
		return false;
	}

	return true;
}

bool functions::gameOver(char  grid[3][3], char currentPlayer)
{
	//provjeri redove
	for (int i = 0; i < 3; i++)
	{
		if (grid[i][0] != ' ' && grid[i][0] == currentPlayer && (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]))
		{
			cout << "\n********** The winner is " << currentPlayer << "! **********" << endl;
			return true;
		}
	}

	//provjeri stupce
	for (int j = 0; j < 3; j++)
	{
		if (grid[0][j] != ' ' && grid[0][j] == currentPlayer && (grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]))
		{
			cout << "\n********** The winner is " << currentPlayer << "! **********" << endl;
			return true;
		}
	}

	//provjeri dijagonale
	if (grid[1][1] != ' ' && grid[1][1] == currentPlayer &&
		((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) ||
			(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])))
	{
		cout << "\n********** The winner is " << currentPlayer << "! **********" << endl;
		return true;
	}

	//provjeri ima li jos slobodnih polja
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (grid[i][j] == '.')
				return false;
		}
	}

	//sva polja su puna, ali nema pobjednika
	cout << "\n********** Wow, you're equally good! **********" << endl;
	return true;
}

void functions::playerMove(char currentPlayer, int& row, int& column)
{
	row = 0;
	column = 0;

	cout << "\n********** Player " << currentPlayer << ", make your move (row column)! **********" << endl;

	while (row < 1 || row > 3)
	{
		cout << "Row: ";
		cin >> row;

		if (row < 1 || row > 3)
			cout << "!!! That row doesn't exist. The number should be between 1 and 3 !!!" << endl;
	}

	while (column < 1 || column > 3)
	{
		cout << "Column: ";
		cin >> column;

		if (column < 1 || column > 3)
			cout << "!!! That column doesn't exist. The number should be between 1 and 3 !!! " << endl;
	}
}

void functions::switchPlayer(char& currentPlayer)
{
	if (currentPlayer == 'x')
		currentPlayer = 'o';
	else
		currentPlayer = 'x';
}

void functions::setCleanBoard(char  grid[3][3], int& row, int& column)
{
	row = 0;
	column = 0;

	initializeGrid(grid);
	drawGrid(grid);

	cout << endl;
}

bool functions::checkForReplay()
{
	string input;

	cout << "Play again? (YES/NO) " << endl;
	cin >> input;

	transform(input.begin(), input.end(), input.begin(), ::tolower);

	while (input != "yes" && input != "no")
	{
		cout << "I don't understand. Play again? (YES/NO)" << endl;
		cin >> input;
	}

	return (input == "yes");
}

void functions::handleGameplay(char  grid[3][3], char& currentPlayer, int& row, int& column, bool& shouldPlay)
{
	setCleanBoard(grid, row, column);

	while (!gameOver(grid, currentPlayer))
	{
		do
		{
			playerMove(currentPlayer, row, column);

		} while (!isFieldAvailable(grid, row, column));

		grid[row - 1][column - 1] = currentPlayer;

		drawGrid(grid);

		if (gameOver(grid, currentPlayer))
		{
			shouldPlay = checkForReplay();
			break;
		}
		else
			switchPlayer(currentPlayer);
	}
}

