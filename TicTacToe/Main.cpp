#include <iostream>
#include <array>
#include <cstdlib>
#include <string>

using namespace std;
const int GRID_SIZE = 3;
bool gameOver = false;
bool startUp = false;

int playerChoice;
int turn = 1;

void DrawBoard();
void Instructions();
void PlayerTurn();
//void WinCondition(char* pBoardValue);
char* UpdateBoard(char* boardValue, int* playerTurn);

//char board[3][3] = { {'0','1','2'},{'3', '4', '5'},{'6', '7', '8'} };
array<array<char, 3>, 3> board = {{ {'0','1','2'},{'3', '4', '5'},{'6', '7', '8'} }};

int main(int argc, char* args[])
{
	array<array<char, 3>, 3>* pBoard;
	pBoard = &board;

	int* pPlayerChoice;
	pPlayerChoice = &playerChoice;

	while (!gameOver)
	{
		if (!startUp)
		{
			Instructions();
			startUp = true;
		}
		DrawBoard();
		PlayerTurn();
		UpdateBoard(pBoard, pPlayerChoice);
		WinCondition(pBoard);
	}

	return 0;
}

void DrawBoard()
{
	cout << "       " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
	cout << "     -----+-----+-----" << endl;
	cout << "       " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
	cout << "     -----+-----+-----" << endl;
	cout << "       " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
	cout << "     -----+-----+-----" << endl;
}

void PlayerTurn()
{
	if (turn == 1)
	{
		cout << "Player1 [X] turn: " << endl;
		cin >> playerChoice;
	}
	else if (turn == 2)
	{
		cout << "Player2 [O] turn: " << endl;
		cin >> playerChoice;
	}

}

char* UpdateBoard(char* pBoardValue, int* pPlayerChoice)
{
	if (turn == 1)
	{
		int x = *pPlayerChoice;
		pBoardValue[x] = 'X';
		turn = 2;
		
	}
	else if (turn == 2)
	{
		int x = *pPlayerChoice;
		pBoardValue[x] = 'O';
		turn = 1;
	}


	return pBoardValue;
}

void WinCondition(array<array<char, 3>, 3>* pBoardValue)
{
	if (pBoardValue[0][0] == 'X' && pBoardValue[0][1] && pBoardValue[0][2])
	{
		cout << "Winner" << endl;
	}
}

void Instructions()
{
	char beginKey = ' ';
	cout << "Welcome to TicTacToe! Enter any key to begin" << endl;
	cin >> beginKey;
}

