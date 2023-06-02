#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // Key found at index i
        }
    }
    return -1;  // Key not found
}

int main() {
    int arr[] = {5, 2, 8, 12, 9};
    int key = 9;

    int index = linearSearch(arr, sizeof(arr) / sizeof(arr[0]), key);

    if (index != -1) {
        printf(" %d found at index %d\n", key, index+1);
    } else {
        printf(" %d not found\n", key);
    }

    return 0;
}
