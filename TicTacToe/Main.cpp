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
char* UpdateBoard(char* boardValue, int* playerTurn);

char grid[3][3] = { {'0','1','2'},{'3', '4', '5'},{'6', '7', '8'} };

int main(int argc, char* args[])
{
	char* pGrid;
	pGrid = &grid[0][0];

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
		UpdateBoard(pGrid, pPlayerChoice);
	}

	return 0;
}

void DrawBoard()
{
	cout << "       " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << endl;
	cout << "     -----+-----+-----" << endl;
	cout << "       " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << endl;
	cout << "     -----+-----+-----" << endl;
	cout << "       " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << endl;
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

char* UpdateBoard(char* pBoardValue, int* pPlayerTurn)
{
	if (turn == 1)
	{
		int x = *pPlayerTurn;
		pBoardValue[x] = 'X';
		turn = 2;
	}
	else if (turn == 2)
	{
		int x = *pPlayerTurn;
		pBoardValue[x] = 'O';
		turn = 1;
	}


	return pBoardValue;
}

//char* WinCondition(char* pBoardValue, int* pPlayerTurn)
//{
//
//}

void Instructions()
{
	char beginKey = ' ';
	cout << "Welcome to TicTacToe! Enter any key to begin" << endl;
	cin >> beginKey;
}

