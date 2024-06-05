#include <stdio.h>
#include <stdlib.h>

#define N 8 // You can change this value to solve for a different size of board

int place(int *board, int k, int i)
{
    for (int j = 0; j < k; j++)
    {
        if (board[j] == i || abs(board[j] - i) == abs(j - k))
        {
            return 0;
        }
    }
    return 1;
}

void printSolution(int *board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i] == j)
            {
                printf("Q ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void NQueens(int *board, int k)
{
    for (int i = 0; i < N; i++)
    {
        if (place(board, k, i))
        {
            board[k] = i;
            if (k == N - 1)
            {
                printSolution(board);
            }
            else
            {
                NQueens(board, k + 1);
            }
        }
    }
}

int main()
{
    int board[N];
    for (int i = 0; i < N; i++)
    {
        board[i] = -1; // Initialize the board with -1
    }
    NQueens(board, 0);
    return 0;
}
