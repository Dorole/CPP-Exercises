#include <iostream>
#include <algorithm>


using namespace std;


// ************ BOARD & PIECES *************

void drawBoard(char board[8][8])
{
	cout
		<< endl
		<< "  a b c d e f g h" << endl
		<< "  - - - - - - - -" << endl
		<< "8 " << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "|" << board[0][3] << "|" << board[0][4] << "|" << board[0][5] << "|" << board[0][6] << "|" << board[0][7] << endl
		<< "  -+-+-+-+-+-+-+-" << endl
		<< "7 " << board[1][0] << "|" << board[1][1] << "|" << board[1][2] << "|" << board[1][3] << "|" << board[1][4] << "|" << board[1][5] << "|" << board[1][6] << "|" << board[1][7] << endl
		<< "  -+-+-+-+-+-+-+-" << endl
		<< "6 " << board[2][0] << "|" << board[2][1] << "|" << board[2][2] << "|" << board[2][3] << "|" << board[2][4] << "|" << board[2][5] << "|" << board[2][6] << "|" << board[2][7] << endl
		<< "  -+-+-+-+-+-+-+-" << endl
		<< "5 " << board[3][0] << "|" << board[3][1] << "|" << board[3][2] << "|" << board[3][3] << "|" << board[3][4] << "|" << board[3][5] << "|" << board[3][6] << "|" << board[3][7] << endl
		<< "  -+-+-+-+-+-+-+-" << endl
		<< "4 " << board[4][0] << "|" << board[4][1] << "|" << board[4][2] << "|" << board[4][3] << "|" << board[4][4] << "|" << board[4][5] << "|" << board[4][6] << "|" << board[4][7] << endl
		<< "  -+-+-+-+-+-+-+-" << endl
		<< "3 " << board[5][0] << "|" << board[5][1] << "|" << board[5][2] << "|" << board[5][3] << "|" << board[5][4] << "|" << board[5][5] << "|" << board[5][6] << "|" << board[5][7] << endl
		<< "  -+-+-+-+-+-+-+-" << endl
		<< "2 " << board[6][0] << "|" << board[6][1] << "|" << board[6][2] << "|" << board[6][3] << "|" << board[6][4] << "|" << board[6][5] << "|" << board[6][6] << "|" << board[6][7] << endl
		<< "  -+-+-+-+-+-+-+-" << endl
		<< "1 " << board[7][0] << "|" << board[7][1] << "|" << board[7][2] << "|" << board[7][3] << "|" << board[7][4] << "|" << board[7][5] << "|" << board[7][6] << "|" << board[7][7] << endl;
}

enum ChessField
{
	PAWN, KING, QUEEN, BISHOP, KNIGHT, ROOK, EMPTY
};

struct ChessPiece
{
	ChessField chessField;
	string pieceName;
	char symbol;
};

ChessPiece convertStringToChessPiece(string pieceName)
{
	transform(pieceName.begin(), pieceName.end(), pieceName.begin(), ::tolower);

	if (pieceName == "pawn")
		return { PAWN, "PAWN", 'p' };
	else if (pieceName == "king")
		return { KING, "KING", 'k' };
	else if (pieceName == "queen")
		return { QUEEN, "QUEEN", 'q' };
	else if (pieceName == "bishop")
		return { BISHOP, "BISHOP", 'b' };
	else if (pieceName == "knight")
		return { KNIGHT, "KNIGHT", 'n' };
	else if (pieceName == "rook")
		return { ROOK, "ROOK", 'r' };
	else
		return { EMPTY, "INVALID", ' ' };
}

enum Color
{
	WHITE, BLACK, NONE
};

struct FieldStruct
{
	ChessPiece piece;
	Color color;

	string position;
	// needed?
	int row;
	int column;
};

struct Player
{
	Color color;
	string playerName;
};

string convertBoardFieldToChessPosition(int row, int column)
{
	string position;
	position += ('a' + column); // Use ASCII value to convert column index to letters a-h
	position += ('8' - row);	// Use ASCII value to convert row index to numbers 1-8

	return position;
}

void initializeBoard(char board[8][8], FieldStruct boardFields[8][8])
{
	int boardSize = 8;
	const string PAWN = "pawn";
	const string KING = "king";
	const string QUEEN = "queen";
	const string BISHOP = "bishop";
	const string KNIGHT = "knight";
	const string ROOK = "rook";
	const string EMPTY = "empty";

	//pawns
	for (int i = 0; i < boardSize; i++)
	{
		board[1][i] = 'p';
		board[6][i] = 'P';

		boardFields[1][i].piece = convertStringToChessPiece(PAWN);
		boardFields[1][i].color = BLACK;
		boardFields[6][i].piece = convertStringToChessPiece(PAWN);
		boardFields[6][i].color = WHITE;
	}

	//kings 
	board[0][4] = 'k';
	board[7][4] = 'K';

	boardFields[0][4].piece = convertStringToChessPiece(KING);;
	boardFields[0][4].color = BLACK;
	boardFields[7][4].piece = convertStringToChessPiece(KING);
	boardFields[7][4].color = WHITE;


	//queens 
	board[0][3] = 'q';
	board[7][3] = 'Q';

	boardFields[0][3].piece = convertStringToChessPiece(QUEEN);
	boardFields[0][3].color = BLACK;
	boardFields[7][3].piece = convertStringToChessPiece(QUEEN);
	boardFields[7][3].color = WHITE;

	//bishops 
	board[0][2] = board[0][5] = 'b';
	board[7][2] = board[7][5] = 'B';

	boardFields[0][2].piece = convertStringToChessPiece(BISHOP);
	boardFields[0][2].color = BLACK;
	boardFields[0][5].piece = convertStringToChessPiece(BISHOP);
	boardFields[0][5].color = BLACK;
	boardFields[7][2].piece = convertStringToChessPiece(BISHOP);
	boardFields[7][2].color = WHITE;
	boardFields[7][5].piece = convertStringToChessPiece(BISHOP);
	boardFields[7][5].color = WHITE;


	//knights 
	board[0][1] = board[0][6] = 'n';
	board[7][1] = board[7][6] = 'N';

	boardFields[0][1].piece = convertStringToChessPiece(KNIGHT);
	boardFields[0][1].color = BLACK;
	boardFields[0][6].piece = convertStringToChessPiece(KNIGHT);
	boardFields[0][6].color = BLACK;
	boardFields[7][1].piece = convertStringToChessPiece(KNIGHT);
	boardFields[7][1].color = WHITE;
	boardFields[7][6].piece = convertStringToChessPiece(KNIGHT);
	boardFields[7][6].color = WHITE;

	//rooks
	board[0][0] = board[0][7] = 'r';
	board[7][0] = board[7][7] = 'R';

	boardFields[0][0].piece = convertStringToChessPiece(ROOK);
	boardFields[0][0].color = BLACK;
	boardFields[0][7].piece = convertStringToChessPiece(ROOK);
	boardFields[0][7].color = BLACK;
	boardFields[7][0].piece = convertStringToChessPiece(ROOK);
	boardFields[7][0].color = WHITE;
	boardFields[7][7].piece = convertStringToChessPiece(ROOK);
	boardFields[7][7].color = WHITE;

	//empty spaces
	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			board[i][j] = ' ';
			boardFields[i][j].piece = convertStringToChessPiece(EMPTY);
			boardFields[i][j].color = NONE;
		}
	}

	//assign positions
	for (int row = 0; row < boardSize; row++)
	{
		for (int column = 0; column < boardSize; column++)
		{
			boardFields[row][column].position = convertBoardFieldToChessPosition(row, column);
			boardFields[row][column].row = row;
			boardFields[row][column].column = column;
		}
	}
}

Player initializePlayer(Color color, string name)
{
	Player newPlayer;
	newPlayer.color = color;
	newPlayer.playerName = name;

	return newPlayer;
}

ChessField getChessField(FieldStruct fieldStruct)
{
	ChessPiece piece = fieldStruct.piece;
	return piece.chessField;
}


// ************ MOVEMENT VALIDATION ************

bool hasKingMovedIntoCheck(FieldStruct boardFields[8][8], FieldStruct finish, Color opponentColor);

bool isValidPawnMove(FieldStruct start, FieldStruct finish)
{
	//TO DO - pawn promotion, en passant

	Color color = start.color;
	int direction = color == WHITE ? 1 : -1;

	//check if it is this pawn's first move and the pawn moves by 2 fields forward
	if ((start.row == (color == WHITE ? 6 : 1)) &&
		(finish.row == start.row + (-2 * direction)) &&
		(start.column == finish.column) &&
		(finish.color == NONE))
		return true;

	//check if the pawn moves by 1 field forward
	if ((start.column == finish.column) &&
		(finish.row == start.row - direction) &&
		(finish.color == NONE))
		return true;

	//check if pawn can capture (diagonally)
	if ((finish.row == start.row - direction) &&
		(finish.column == start.column + 1 || finish.column == start.column - 1))
		return (finish.color != NONE) && (finish.color != color);

	return false;
}

bool isValidKingMove(FieldStruct boardFields[8][8], FieldStruct start, FieldStruct finish)
{
	Color opponentColor = (start.color == WHITE) ? BLACK : WHITE;

	//check if final position is correct
	int rowDifference = abs(finish.row - start.row);
	int colDifference = abs(finish.column - start.column);

	if (finish.color == start.color) return false;

	if ((rowDifference == 1 && finish.column == start.column) || (colDifference == 1 && finish.row == start.row))
	{
		if (hasKingMovedIntoCheck(boardFields, finish, opponentColor))
			return false;
		else
			return (finish.color != start.color);
	}

	return false;
}

bool isValidKnightMove(FieldStruct start, FieldStruct finish)
{
	//check if final position is correct
	int rowDifference = abs(finish.row - start.row);
	int colDifference = abs(finish.column - start.column);

	if ((rowDifference == 1 && colDifference == 2) || (rowDifference == 2 && colDifference == 1))
		return (finish.color != start.color);

	return false;
}

bool isValidBishopMove(FieldStruct boardFields[8][8], FieldStruct start, FieldStruct finish)
{
	//check if move is diagonal
	int rowDifference = abs(start.row - finish.row);
	int columnDifference = abs(start.column - finish.column);

	if (rowDifference != columnDifference) return false;

	//check if path is clear
	int verticalMove = (finish.row > start.row) ? 1 : -1;
	int horizontalMove = (finish.column > start.column) ? 1 : -1;

	int currentRow = start.row + verticalMove;
	int currentColumn = start.column + horizontalMove;

	while (currentRow != finish.row && currentColumn != finish.column)
	{
		ChessField thisField = getChessField(boardFields[currentRow][currentColumn]);

		if (thisField != EMPTY) return false;

		currentRow += verticalMove;
		currentColumn += horizontalMove;
	}

	ChessField finishField = getChessField(boardFields[finish.row][finish.column]);

	//return true if finish field is empty or can capture
	return (finishField == EMPTY || finish.color != start.color);
}

bool isValidRookMove(FieldStruct boardFields[8][8], FieldStruct start, FieldStruct finish)
{
	//TO DO: castling - ! this function is used for queen as well, validate if rook

	//check if the move is along the same row or the same column
	if (start.row != finish.row && start.column != finish.column)
		return false;

	//check if path is clear
	if (start.row == finish.row)
	{
		// determine direction (right or left)
		int horizontalMove = (finish.column > start.column) ? 1 : -1;
		int currentColumn = start.column + horizontalMove;

		while (currentColumn != finish.column)
		{
			ChessField thisField = getChessField(boardFields[start.row][currentColumn]);

			if (thisField != EMPTY) return false;

			currentColumn += horizontalMove;
		}
	}
	else
	{
		//determine direction (down or up)
		int verticalMove = (finish.row > start.row) ? 1 : -1;
		int currentRow = start.row + verticalMove;

		while (currentRow != finish.row)
		{
			ChessField thisField = getChessField(boardFields[currentRow][start.column]);

			if (thisField != EMPTY) return false;

			currentRow += verticalMove;
		}
	}

	//return true if the finish field is empty or can capture
	return (finish.color != start.color);
}

bool isValidQueenMove(FieldStruct boardFields[8][8], FieldStruct start, FieldStruct finish)
{
	return (isValidBishopMove(boardFields, start, finish) || isValidRookMove(boardFields, start, finish));
}


bool isValidPosition(string input)
{
	if (input.length() != 2) return false;

	char column = input[0];
	char row = input[1];

	if (column < 'a' || column > 'h' || row < '1' || row > '8')
		return false;

	return true;
}

bool isValidMove(ChessField selectedField, FieldStruct boardFields[8][8], FieldStruct start, FieldStruct finish)
{
	bool isMoveValid = true;

	switch (selectedField)
	{
	case PAWN:
		if (!isValidPawnMove(start, finish))
			isMoveValid = false;
		break;
	case KING:
		if (!isValidKingMove(boardFields, start, finish))
			isMoveValid = false;
		break;
	case QUEEN:
		if (!isValidQueenMove(boardFields, start, finish))
			isMoveValid = false;
		break;
	case BISHOP:
		if (!isValidBishopMove(boardFields, start, finish))
			isMoveValid = false;
		break;
	case KNIGHT:
		if (!isValidKnightMove(start, finish))
			isMoveValid = false;
		break;
	case ROOK:
		if (!isValidRookMove(boardFields, start, finish))
			isMoveValid = false;
		break;
	default:
		cout << "Invalid piece. Check the code." << endl;
		isMoveValid = false;
		break;
	}

	return isMoveValid;
}


// ************ CHECK & CHECKMATE VALIDATION ************

FieldStruct enemyKingLocation(FieldStruct boardFields[8][8], Color currentPlayerColor)
{
	Color opponentColor = (currentPlayerColor == WHITE) ? BLACK : WHITE;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (boardFields[i][j].color == opponentColor && getChessField(boardFields[i][j]) == KING)
			{
				return boardFields[i][j];
			}
		}
	}
}

bool isCheck(FieldStruct boardFields[8][8], FieldStruct start)
{
	FieldStruct kingPosition = enemyKingLocation(boardFields, start.color);
	ChessField thisField = getChessField(start);

	return (isValidMove(thisField, boardFields, start, kingPosition));
}

bool isKingInCheck(FieldStruct boardFields[8][8], FieldStruct kingPosition, Color kingColor)
{
	Color opponentColor = (kingColor == WHITE) ? BLACK : WHITE;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (boardFields[i][j].color != opponentColor) continue;

			ChessField thisField = getChessField(boardFields[i][j]);

			if (isValidMove(thisField, boardFields, boardFields[i][j], kingPosition))
				return true;
		}
	}

	return false;

}

bool hasKingMovedIntoCheck(FieldStruct boardFields[8][8], FieldStruct finish, Color opponentColor)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (boardFields[i][j].color != opponentColor) continue;

			ChessField thisField = getChessField(boardFields[i][j]);

			if (isValidMove(thisField, boardFields, boardFields[i][j], finish))
			{
				cout << "Cannot move into a check!" << endl;
				return false;
			}
			else
				return true;

		}
	}
}

bool isCheckmate(FieldStruct boardFields[8][8], Color playerColor)
{
	FieldStruct kingPosition = enemyKingLocation(boardFields, playerColor);
	Color kingColor = (playerColor == WHITE) ? BLACK : WHITE;

	if (!isKingInCheck(boardFields, kingPosition, kingColor)) return false;

	//check for valid moves to get out of check
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (isValidKingMove(boardFields, kingPosition, boardFields[i][j]))
				return false;
		}
	}

	return true;
}


// ************ TURN MANAGEMENT ************

void Move(FieldStruct boardFields[8][8], char board[8][8], Player currentPlayer)
{
	string pieceName;
	string currentPosition;
	string newPosition;
	bool isValidCurrentPosition = false;
	bool isValidNewPosition = false;
	int currentRow, currentCol;
	int newRow, newCol;

	cout << "Make your move." << endl;


	// ------------------- PIECE SELECTION -------------------

	ChessPiece selectedPiece;

	do
	{
		cout << "Piece: ";
		cin >> pieceName;
		selectedPiece = convertStringToChessPiece(pieceName);

		if (selectedPiece.chessField != EMPTY)
			break;
		else
			cout << "Invalid selection!" << endl;

	} while (selectedPiece.chessField == EMPTY);


	// ------------------- STARTING POS -------------------

	cout << "From: ";

	do
	{
		cin >> currentPosition;

		if (!isValidPosition(currentPosition))
		{
			cout << "Invalid input! Select a valid position: ";
			continue;
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (boardFields[i][j].position == currentPosition)
				{
					ChessPiece pieceOnThisField = boardFields[i][j].piece;

					if (pieceOnThisField.chessField != selectedPiece.chessField || boardFields[i][j].color != currentPlayer.color)
					{
						cout << "Invalid selection!" << endl;
						cout << "Select a valid current position of " << currentPlayer.playerName << " " << selectedPiece.pieceName << ": ";
					}
					else
					{
						isValidCurrentPosition = true;
						currentRow = i;
						currentCol = j;
						break;
					}
				}
				else
					continue;
			}
		}

	} while (!isValidCurrentPosition);


	// ------------------- MOVE TO NEW POS -------------------

	cout << "To: ";

	do
	{
		cin >> newPosition;

		if (!isValidPosition(newPosition))
		{
			cout << "Invalid input! Select a valid position: ";
			continue;
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (boardFields[i][j].position == newPosition)
				{
					ChessPiece pieceOnThisField = boardFields[i][j].piece;

					if (!isValidMove(selectedPiece.chessField, boardFields, boardFields[currentRow][currentCol], boardFields[i][j]))
						cout << "Invalid selection! Select a new position: " << endl;

					else
					{
						isValidNewPosition = true;
						newRow = i;
						newCol = j;

						//update visuals
						board[currentRow][currentCol] = ' ';

						if (currentPlayer.color == WHITE)
							board[newRow][newCol] = toupper(selectedPiece.symbol);
						else
							board[newRow][newCol] = tolower(selectedPiece.symbol);

						//update struct values
						boardFields[currentRow][currentCol].color = NONE;
						boardFields[newRow][newCol].color = currentPlayer.color;
						boardFields[currentRow][currentCol].piece = convertStringToChessPiece("empty");
						boardFields[newRow][newCol].piece = convertStringToChessPiece(selectedPiece.pieceName);

						//announce capture
						if (pieceOnThisField.chessField != EMPTY)
						{
							string opponentColor = currentPlayer.color == WHITE ? "BLACK" : "WHITE";

							cout << currentPlayer.playerName << " " << selectedPiece.pieceName << " captured "
								<< opponentColor << " " << pieceOnThisField.pieceName << endl;
						}

						break;
					}
				}
				else
					continue;
			}
		}

	} while (!isValidNewPosition);

	cout << currentPlayer.playerName << " " << selectedPiece.pieceName << " to " << newPosition << endl;


	// ------------------- CHECK FOR CHECK -------------------

	if (isCheck(boardFields, boardFields[newRow][newCol]) && !isCheckmate(boardFields, currentPlayer.color))
		cout << "\nCHECK!" << endl;
}


int main()
{
	char board[8][8];
	FieldStruct boardFields[8][8];

	Player whitePlayer = initializePlayer(WHITE, "WHITE");
	Player blackPlayer = initializePlayer(BLACK, "BLACK");
	Player currentPlayer = whitePlayer;

	initializeBoard(board, boardFields);
	drawBoard(board);

	while (!isCheckmate(boardFields, currentPlayer.color))
	{
		cout << "\nCurrent turn: " << currentPlayer.playerName << endl;
		Move(boardFields, board, currentPlayer);
		drawBoard(board);

		if (isCheckmate(boardFields, currentPlayer.color))
		{
			cout << "\nCHECKMATE!" << endl;
			cout << currentPlayer.playerName << " WINS!" << endl;
			break;
		}
		else
			currentPlayer = (currentPlayer.color == WHITE) ? blackPlayer : whitePlayer;
	}

}