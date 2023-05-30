#pragma once

struct functions
{
	void drawGrid(char  grid[3][3]);

	void initializeGrid(char  grid[3][3]);

	bool gameOver(char  grid[3][3], char currentPlayer);

	bool isFieldAvailable(char  grid[3][3], int& row, int& column);

	void playerMove(char currentPlayer, int& row, int& column);

	void switchPlayer(char& currentPlayer);

	void setCleanBoard(char  grid[3][3], int& row, int& column);

	bool checkForReplay();

	void handleGameplay(char  grid[3][3], char& currentPlayer, int& row, int& column, bool& shouldPlay);

};

