#include <stdio.h>
#define N 4

// A utility function to count inversions in the given array 'arr[]'.
int getInvCount(int arr[]) {
    int inv_count = 0;
    for (int i = 0; i < N * N - 1; i++) {
        for (int j = i + 1; j < N * N; j++) {
            // Count pairs (arr[i], arr[j]) such that 
            // i < j but arr[i] > arr[j]
            if (arr[j] && arr[i] && arr[i] > arr[j])
                inv_count++;
        }
    }
    return inv_count;
}

// Find the position of the blank space from the bottom
int findXPosition(int puzzle[N][N]) {
    // Start from bottom-right corner of matrix
    for (int i = N - 1; i >= 0; i--)
        for (int j = N - 1; j >= 0; j--)
            if (puzzle[i][j] == 0)
                return N - i;
}

// This function returns true if the given instance of the N*N-1 puzzle is solvable
int isSolvable(int puzzle[N][N]) {
    // Count inversions in given puzzle
    int invCount = getInvCount((int*)puzzle);

    // If grid is odd, return true if inversion count is even.
    if (N & 1)
        return !(invCount & 1);

    else { // Grid is even
        int pos = findXPosition(puzzle);
        if (pos & 1)
            return !(invCount & 1);
        else
            return invCount & 1;
    }
}

/* Driver program to test the above functions */
int main() {

    int puzzle[N][N] = {
        {12, 1, 10, 2},
        {7, 11, 4, 14},
        {5, 0, 9, 15}, // Value 0 is used for the empty space
        {8, 13, 6, 3}
    };

    /*
    int puzzle[N][N] = {
        {1, 8, 2},
        {0, 4, 3},
        {7, 6, 5}
    };

    int puzzle[N][N] = {
        {13, 2, 10, 3},
        {1, 12, 8, 4},
        {5, 0, 9, 6},
        {15, 14, 11, 7},
    };

    int puzzle[N][N] = {
        {6, 13, 7, 10},
        {8, 9, 11, 0},
        {15, 2, 12, 5},
        {14, 3, 1, 4},
    };

    int puzzle[N][N] = {
        {3, 9, 1, 15},
        {14, 11, 4, 6},
        {13, 0, 10, 12},
        {2, 7, 8, 5},
    };
    */

    isSolvable(puzzle) ? printf("Solvable\n") : printf("Not Solvable\n");
    return 0;
}

