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
void WinCondition(array<array<char, 3>, 3>* pBoardValue);
array<array<char, 3>, 3>* UpdateBoard(array<array<char, 3>, 3>* boardValue, int* playerTurn);

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

array<array<char, 3>, 3>* UpdateBoard(array<array<char, 3>, 3>* pBoardValue, int* pPlayerChoice)
{
	//row
	int x1 = *pPlayerChoice / 3;
	//column
	int x2 = *pPlayerChoice % 3;
	if (turn == 1)
	{
		if (turn == 1 && (*pBoardValue)[x1][x2] == 'O')
		{
			cout << "Place is taken" << endl;
		}
		else
		{
			(*pBoardValue)[x1][x2] = 'X';
			turn = 2;
		}
		
	}
	else if (turn == 2)
	{
		if (turn == 2 && (*pBoardValue)[x1][x2] == 'X')
		{
			cout << "Place is taken" << endl;
		}
		else
		{
			(*pBoardValue)[x1][x2] = 'O';
			turn = 1;
		}
		
	}
	
	return pBoardValue;
}

void WinCondition(array<array<char, 3>, 3>* pBoardValue)
{
	//Row wins
	int row1x = (*pBoardValue)[0][0] == 'X' && (*pBoardValue)[0][1] == 'X' && (*pBoardValue)[0][2] == 'X';
	int row2x = (*pBoardValue)[1][0] == 'X' && (*pBoardValue)[1][1] == 'X' && (*pBoardValue)[1][2] == 'X';
	int row3x = (*pBoardValue)[2][2] == 'X' && (*pBoardValue)[2][1] == 'X' && (*pBoardValue)[2][2] == 'X';
	int row1o = (*pBoardValue)[0][0] == 'O' && (*pBoardValue)[0][1] == 'O' && (*pBoardValue)[0][2] == 'O';
	int row2o = (*pBoardValue)[1][0] == 'O' && (*pBoardValue)[1][1] == 'O' && (*pBoardValue)[1][2] == 'O';
	int row3o = (*pBoardValue)[2][2] == 'O' && (*pBoardValue)[2][1] == 'O' && (*pBoardValue)[2][2] == 'O';
	//Column win
	int col1x = (*pBoardValue)[0][0] == 'X' && (*pBoardValue)[1][0] == 'X' && (*pBoardValue)[2][0] == 'X';
	int col2x = (*pBoardValue)[0][1] == 'X' && (*pBoardValue)[1][1] == 'X' && (*pBoardValue)[2][1] == 'X';
	int col3x = (*pBoardValue)[0][2] == 'X' && (*pBoardValue)[1][2] == 'X' && (*pBoardValue)[2][2] == 'X';
	int col1o = (*pBoardValue)[0][0] == 'O' && (*pBoardValue)[1][0] == 'O' && (*pBoardValue)[2][0] == 'O';
	int col2o = (*pBoardValue)[0][1] == 'O' && (*pBoardValue)[1][1] == 'O' && (*pBoardValue)[2][1] == 'O';
	int col3o = (*pBoardValue)[0][2] == 'O' && (*pBoardValue)[1][2] == 'O' && (*pBoardValue)[2][2] == 'O';
	//Diangle win
	int d1x = (*pBoardValue)[0][0] == 'X' && (*pBoardValue)[1][1] == 'X' && (*pBoardValue)[2][2] == 'X';
	int d2x = (*pBoardValue)[0][2] == 'X' && (*pBoardValue)[1][1] == 'X' && (*pBoardValue)[2][0] == 'X';
	int d1o = (*pBoardValue)[0][0] == 'O' && (*pBoardValue)[1][1] == 'O' && (*pBoardValue)[2][2] == 'O';
	int d2o = (*pBoardValue)[0][2] == 'O' && (*pBoardValue)[1][1] == 'O' && (*pBoardValue)[2][0] == 'O';



	if (row1x || row2x || row3x || col1x || col2x || col3x || d1x || d2x)
	{
		cout << "Player 1 is the winner" << endl;
	}
	else if (row1o || row2o || row3o || col1o || col2o || col3o || d1o || d2o)
	{
		cout << "Player 2 is the winner" << endl;
	}
	
}

void Instructions()
{
	char beginKey = ' ';
	cout << "Welcome to TicTacToe! Enter any key to begin" << endl;
	cin >> beginKey;
}




