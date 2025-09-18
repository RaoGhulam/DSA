#include <iostream>
using namespace std;

const int N = 4;
int board[N][N];

void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if placing a queen at board[row][col] is safe
bool isSafe(int row, int col)
{
    // Check the column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queen problem using backtracking
bool solveNQueens(int row)
{
    if (row == N)
    {
        printBoard();
        return true;
    }

    bool result = false;
    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            // Place queen
            board[row][col] = 1;

            // Recur to place the rest of the queens
            result = solveNQueens(row + 1) || result;

            // Backtrack: remove the queen
            board[row][col] = 0;
        }
    }

    return result;
}

int main()
{
    // Initialize the board with 0s
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 0;
        }
    }

    if (!solveNQueens(0))
    {
        cout << "No solution exists for " << N << " queens." << endl;
    }

    return 0;
}
