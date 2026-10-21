/* Column with Minimum Sum
Write a C program to find the column having the minimum sum in a matrix using recursion.*/
#include <stdio.h>

int a[10][10];
int rows, cols;

/* Recursive function to find sum of a column */
int columnSum(int row, int col)
{
    if (row == rows)
        return 0;

    return a[row][col] + columnSum(row + 1, col);
}

/* Recursive function to find column with minimum sum */
int minColumn(int col, int minCol, int minSum)
{
    int sum;

    if (col == cols)
        return minCol;

    sum = columnSum(0, col);

    if (sum < minSum)
    {
        minSum = sum;
        minCol = col;
    }

    return minColumn(col + 1, minCol, minSum);
}

int main()
{
    int i, j, result, firstSum;

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    firstSum = columnSum(0, 0);

    result = minColumn(1, 0, firstSum);

    printf("Column with minimum sum: %d\n", result + 1);
    printf("Minimum sum: %d\n", columnSum(0, result));

    return 0;
}



