#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum element in an array
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to find the minimum element in an array
int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Heapify a subtree rooted with node i which is an index in arr[]
void heapify(int arr[], int size, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int size) {
    // Build heap (rearrange array)
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    // One by one extract an element from heap
    for (int i = size - 1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int arr[] = {9, 4, 2, 7, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Finding maximum and minimum elements in the array
    int max = findMax(arr, size);
    int min = findMin(arr, size);

    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);

    printf("Array before sorting: ");
    printArray(arr, size);

    // Sorting the array using Heap Sort
    heapSort(arr, size);

    printf("Array after sorting: ");
    printArray(arr, size);

    return 0;
}
