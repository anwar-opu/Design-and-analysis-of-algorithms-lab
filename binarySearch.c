#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the target is found, return its index
        if (arr[mid] == target)
            return mid;

        // If the target is smaller than the middle element,
        // search in the left half of the array
        if (arr[mid] > target)
            return binarySearch(arr, left, mid - 1, target);

        // If the target is larger than the middle element,
        // search in the right half of the array
        return binarySearch(arr, mid + 1, right, target);
    }

    // If the target is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, 0, n - 1, target);

    if (result == -1)
        printf("Element not found in the array.\n");
    else
        printf("Element found at index %d.\n", result);

    return 0;
}
