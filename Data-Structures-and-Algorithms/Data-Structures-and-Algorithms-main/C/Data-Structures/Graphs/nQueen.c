#include <stdio.h>
#include <stdbool.h>

void printBoard(int n, int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
        printf("\n");
    }
}

bool isSafe(int n, int board[n][n], int row, int col)
{
    int i, j;

    /* Check this row on left side */
    for (i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    /* Check upper diagonal on left side */
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    /* Check lower diagonal on left side */
    for (i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueenUtil(int n, int board[n][n], int col)
{
    /* base case: If all queens are placed
     then return true */
    if (col >= n)
        return true;

    /* Consider this column and try placing
       this queen in all rows one by one */
    for (int i = 0; i < n; i++)
    {
        if (isSafe(n, board, i, col))
        {
            /* Place this queen in board[i][col] */
            board[i][col] = 1;

            /* recur to place rest of the queens */
            if (solveNQueenUtil(n, board, col + 1))
                return true;

            /* If placing queen in board[i][col]
         doesn't lead to a solution, then
         remove queen from board[i][col] */
            board[i][col] = 0; // BACKTRACK
        }
    }

    return false;
}

int main()
{
    int n, i, j;
    printf("Enter the number of queens 4 or 8: \n");
    scanf("%d", &n);
    if (n != 4 && n != 8)
    {
        printf("Invalid input. Try again nigga.\n");
        return 0;
    }
    int board[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }
    if (solveNQueenUtil(n, board, 0))
    {
        printBoard(n, board);
    }
    else
    {
        printf("No solution.");
        return 0;
    }

    return 0;
}