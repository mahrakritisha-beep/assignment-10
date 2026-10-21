/*Write a C program to find the maximum element in an array and count the number of times it occurs using recursion.

*/
#include <stdio.h>
void findMaxAndCount(int arr[], int n, int *max, int *count) {
    if (n == 0) {
        return;
    }
    if (arr[n - 1] > *max) {
        *max = arr[n - 1];
        *count = 1;
    } else if (arr[n - 1] == *max) {
        (*count)++;
    }
    findMaxAndCount(arr, n - 1, max, count);
}
   int main() {
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    int count = 0;
    findMaxAndCount(arr, n, &max, &count);
    printf("The maximum element is: %d\n", max);
    printf("It occurs %d times in the array.\n", count);
    return 0;
}
