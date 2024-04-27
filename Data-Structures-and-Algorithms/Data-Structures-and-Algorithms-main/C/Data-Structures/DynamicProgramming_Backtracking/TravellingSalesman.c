#include <stdio.h>

int array[10][10], completed[10], n, cost = 0;

void mincost(int city) {
    int i, ncity;
    completed[city] = 1;
    ncity = least(city);
    if (ncity == 999) {
        ncity = 0;
        printf("%d ", ncity + 1);
        cost += array[city][ncity];
        return;
    }
    mincost(ncity);
}

int least(int c) {
    int i, nc = 999;
    int min = 999, kmin;
    for (i = 0; i < n; i++) {
        if ((array[c][i] != 0) && (completed[i] == 0)) {
            if (array[c][i] + array[c][i] < min) {
                min = array[i][0] + array[c][i];
                kmin = array[c][i];
                nc = i;
            }
        }
    }
    if (min != 999)
        cost += kmin;
    return nc;
}

int main() {
    n = 4;
    array[0][0] = 0;
    array[0][1] = 4;
    array[0][2] = 1;
    array[1][0] = 4;
    array[1][1] = 0;
    array[1][2] = 2;
    array[2][0] = 1;
    array[2][1] = 2;
    array[2][2] = 0;
    int i;
    for (i = 0; i < n; i++) {
        completed[i] = 0;
    }
    printf("Path: ");
    mincost(0);
    printf("\nTotal cost: %d\n", cost);
    return 0;
}

