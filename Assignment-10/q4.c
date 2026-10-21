/*. Second-Largest Element
Write a C program to find the second-largest distinct element in an array using recursion. Display a suitable message if fewer than two distinct elements exist.*/
#include <stdio.h>

int findSecondLargest(int arr[], int n, int *largest, int *secondLargest) {
    if (n == 0) {
        return 0;
    }
    if (arr[0] > *largest) {
        *secondLargest = *largest;
        *largest = arr[0];
    } else if (arr[0] > *secondLargest && arr[0] != *largest) {
        *secondLargest = arr[0];
    }
    return findSecondLargest(arr + 1, n - 1, largest, secondLargest);
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
    int largest = arr[0];
    int secondLargest = arr[0];
    if (findSecondLargest(arr, n, &largest, &secondLargest) == 0) {
        printf("There are fewer than two distinct elements in the array.\n");
    } else {
        printf("The second-largest distinct element is: %d\n", secondLargest);
    }    return 0;
}
