#include <stdio.h>
#include <stdbool.h>
#define N 4
int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++) {
        for (int j = i + 1; j < N * N; j++) {
            if (arr[j] != 0 && arr[i] != 0 && arr[i] > arr[j])
                inv_count++;
        }
    }
    return inv_count;
}
int findXPosition(int puzzle[N][N])
{
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j >= 0; j--)
            if (puzzle[i][j] == 0)
                return N - i;
    return -1;
}
bool isSolvable(int puzzle[N][N])
{
    int arr[N * N];
    int k = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (puzzle[i][j] != 0) 
                arr[k++] = puzzle[i][j];
    while (k < N * N)
        arr[k++] = 0; 
    int invCount = getInvCount(arr);
    if (N % 2 == 1)
        return invCount % 2 == 0;
    else 
    {
        int pos = findXPosition(puzzle);
        if (pos % 2 == 1)
            return invCount % 2 == 0;
        else
            return invCount % 2 == 1;
    }
}
int main()
{
    //int puzzle[N][N] = {
      //  {1, 2, 3, 4},
        //{5, 6, 0, 8},
        //{9, 10, 7, 11}, 
        //{13, 14, 15, 12}
   // };
   int puzzle[N][N] = {
        {10, 9, 2, 14},
        {7, 11, 1, 8},
        {13, 0, 15, 3}, 
        {6, 12, 4, 5}
    };
    printf("%s\n", isSolvable(puzzle) ? "Solvable" : "Not Solvable");
    return 0;
}
