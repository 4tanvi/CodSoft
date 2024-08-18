#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };

void printBoard()
{
    cout << "\n";
    cout << "  1 2 3\n";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << i + 1 << ' ';
        for (int j = 0; j < SIZE; ++j)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}

bool checkWinner(char player)
    {
    for (int i = 0; i < SIZE; ++i)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || (board[0][i] == player && board[1][i] == player && board[2][i] == player))
        {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || (board[2][0] == player && board[1][1] == player && board[0][2] == player))
    {
        return true;
    }
    return false;
}

bool isBoardFull()
{
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

bool makeMove(char player)
{
    int row, col;
    while (true)
    {
        cout << "Player " << player << ", enter row and column (1-3): ";
        cin >> row >> col;
        row--;
        col--;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ')
        {
            board[row][col] = player;
            return true;
        } 
        else 
        {
            cout << "Invalid move. Try again.\n";
        }
    }
}

int main()
{
    char currentPlayer = 'X';
    bool gameWon = false;

    while (true)
    {
        printBoard();
        if (makeMove(currentPlayer))
            {
            if (checkWinner(currentPlayer))
            {
                cout << "Player " << currentPlayer << " wins!\n";
                gameWon = true;
                break;
            }
            if (isBoardFull())
            {
                cout << "The game is a draw!\n";
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    printBoard();
    return 0;
}