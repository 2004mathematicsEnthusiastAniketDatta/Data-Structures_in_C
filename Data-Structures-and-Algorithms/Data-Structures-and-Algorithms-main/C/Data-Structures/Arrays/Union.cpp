#include <stdio.h>
void next_distinct(int arr[], int size, int* x)
{
	/* Moving to next distinct element */
	do {
		++(*x);
	} while (*x < size && arr[*x - 1] == arr[*x]);
}

void printUnion(int arr1[], int size1, int arr2[],
				int size2)
{
	int i = 0, j = 0;
	while (i < size1 && j < size2) {
		if (arr1[i] < arr2[j]) {
			printf("%d ", arr1[i]);
			next_distinct(arr1, size1,
						&i); // Incrementing i to next
							// distinct element
		}
		else if (arr1[i] > arr2[j]) {
			printf("%d ", arr2[j]);
			next_distinct(arr2, size2,
						&j); // Incrementing j to next
							// distinct element
		}
		else {
			printf("%d ",
				arr1[i]); // OR printf("%d ", arr2[j]);
			next_distinct(arr1, size1,
						&i); // Incrementing i to next
							// distinct element
			next_distinct(arr2, size2,
						&j); // Incrementing j to next
							// distinct element
		}
	}
	// Remaining elements of the larger array
	while (i < size1) {
		printf("%d ", arr1[i]);
		next_distinct(
			arr1, size1,
			&i); // Incrementing i to next distinct element
	}
	while (j < size2) {
		printf("%d ", arr2[j]);
		next_distinct(
			arr2, size2,
			&j); // Incrementing j to next distinct element
	}
}

int main()
{
	int arr1[] = { 1, 2, 2, 2, 3 }; // Duplicates Present
	int arr2[] = { 2, 3, 3, 4, 5, 5 }; // Duplicates Present
	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	printUnion(arr1, size1, arr2, size2);

	return 0;
}

