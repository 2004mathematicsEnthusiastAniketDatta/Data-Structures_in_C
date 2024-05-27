#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int row;
    int col;
    int value;
} Sparse;

void main()
{
    int m = 0, n = 0; // initialize number of rows and columns
    int count = 0;    // initialize number of non-zero elements
    printf("Enter the number of rows: ");
    scanf("%d", &m);
    printf("Enter the number of columns: ");
    scanf("%d", &n);

    // check if the input is valid or not
    if (m <= 0 || n <= 0)
    {
        printf("Invalid input.\n");
        exit(0);
    }

    int **matrix = (int **)malloc(m * sizeof(int *)); // matrix of size m x n
    for (int i = 0; i < m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    // input the matrix from the user and count the number of non-zero elements
    printf("\nEnter the elements of the matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the element at matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
            {
                count++; // count the number of non-zero elements
            }
        }
    }

    if (count < (m * n) / 2) // check if the matrix is sparse or not
    {
        // create a sparse matrix of size (count + 1) x 3 and store the number of rows, columns and non-zero elements in the first row of the sparse matrix
        Sparse *sparse = (Sparse *)malloc((count + 1) * sizeof(Sparse));
        sparse[0].row = m;
        sparse[0].col = n;
        sparse[0].value = count;

        int k = 1; // index of sparse matrix
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] != 0)
                {
                    sparse[k].row = i;
                    sparse[k].col = j;
                    sparse[k].value = matrix[i][j];
                    k++;
                }
            }
        }

        printf("\nThe matrix is a sparse matrix.\n");

        printf("\nSparse Matrix (3 tuple representation):\n");
        printf("Row\tColumn\tValue\n");
        for (int i = 0; i <= count; i++)
        {
            printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
        }

        // transpose the sparse matrix and store it in another sparse matrix of size (count + 1) x 3 and print it
        Sparse *transpose = (Sparse *)malloc((count + 1) * sizeof(Sparse));
        transpose[0].row = n;
        transpose[0].col = m;
        transpose[0].value = count;

        k = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[j][i] != 0)
                {
                    transpose[k].row = i;
                    transpose[k].col = j;
                    transpose[k].value = matrix[j][i];
                    k++;
                }
            }
        }

        printf("\nTranspose of the Sparse Matrix is:\n");
        printf("Row\tColumn\tValue\n");
        for (int i = 0; i <= count; i++)
        {
            printf("%d\t%d\t%d\n", transpose[i].row, transpose[i].col, transpose[i].value);
        }
    }
    else
    {
        printf("The matrix is not sparse matrix.\n");
    }
}
