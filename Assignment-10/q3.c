/*3. Reverse an Array
Write a C program to reverse the elements of a one-dimensional array using recursion.
*/
#include <stdio.h>

void reverseArray(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int temp = arr[l];
    arr[l] = arr[r];
    arr[r] = temp;
    reverseArray(arr, l + 1, r - 1);
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
    reverseArray(arr, 0, n - 1);
    printf("Reversed array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
