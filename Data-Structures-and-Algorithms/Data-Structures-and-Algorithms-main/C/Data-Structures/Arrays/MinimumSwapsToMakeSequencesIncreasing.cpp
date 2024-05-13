#include <stdio.h>
#include <limits.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

void minSwap(int* A, int ASize, int* B, int BSize, int* ret) {
    int swap[ASize], not_swap[ASize];
    swap[0] = 1;
    not_swap[0] = 0;
    for (int i = 1; i < ASize; i++) {
        swap[i] = not_swap[i] = INT_MAX;
        if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
            not_swap[i] = not_swap[i - 1];
            swap[i] = swap[i - 1] + 1;
        }
        if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
            not_swap[i] = MIN(not_swap[i], swap[i - 1]);
            swap[i] = MIN(swap[i], not_swap[i - 1] + 1);
        }
    }
    *ret = MIN(swap[ASize - 1], not_swap[ASize - 1]);
}

int main() {
    int A[] = {1, 3, 5, 4};
    int B[] = {1, 2, 3, 7};
    int size = sizeof(A) / sizeof(A[0]);
    int ret;
    minSwap(A, size, B, size, &ret);
    printf("%d\n", ret);
    return 0;
}

