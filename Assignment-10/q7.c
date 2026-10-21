/*
7. Symmetric Matrix
Write a C program to check whether a square matrix is symmetric using recursion.
*/
#include <stdio.h>

int isSymmetric(int matrix[][10], int n, int i, int j) {
    if (i >= n || j >= n) {
        return 1; // Base case: reached the end of the matrix
    }
    if (matrix[i][j] != matrix[j][i]) {
        return 0; // Not symmetric
    }
    if (i == j) {
        return isSymmetric(matrix, n, i + 1, 0); // Move to the next row
    } else {
        return isSymmetric(matrix, n, i, j + 1); // Move to the next column
    }
}
int main() {
    int n, i, j;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int matrix[10][10];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (isSymmetric(matrix, n, 0, 0)) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }
    return 0;
}
