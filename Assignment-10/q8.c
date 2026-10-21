/*  Matrix Multiplication
Write a C program to multiply two compatible matrices using recursive functions.*/
#include <stdio.h>

int A[10][10], B[10][10], C[10][10];
int r1, c1, r2, c2;

/* Recursive function to calculate one element */
int multiply(int i, int j, int k)
{
    if (k == c1)
        return 0;

    return A[i][k] * B[k][j] + multiply(i, j, k + 1);
}

/* Recursive function to calculate all elements */
void matrixMultiply(int i, int j)
{
    if (i == r1)
        return;

    if (j == c2)
    {
        matrixMultiply(i + 1, 0);
        return;
    }

    C[i][j] = multiply(i, j, 0);

    matrixMultiply(i, j + 1);
}

int main()
{
    int i, j;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &B[i][j]);

    matrixMultiply(0, 0);

    printf("Product matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}
