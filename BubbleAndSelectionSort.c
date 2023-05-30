// Bubble sort in C
#include<stdio.h>
void bubbleSort(int array[], int size) {
  int i, j, temp;

  for (i = 0; i < size - 1; i++) {
    for (j = 0; j < size - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

// Selection sort in C
void selectionSort(int array[], int size) {
  int i, j, min_index;

  for (i = 0; i < size - 1; i++) {
    min_index = i;
    for (j = i + 1; j < size; j++) {
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }

    int temp = array[i];
    array[i] = array[min_index];
    array[min_index] = temp;
  }
}

// Driver code
int main() {
  int array[] = {10, 8, 2, 7, 1, 9, 6, 5, 4, 3};
  int size = sizeof(array) / sizeof(array[0]);

  printf("Unsorted array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  bubbleSort(array, size);

  printf("Sorted array (bubble sort): ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  selectionSort(array, size);

  printf("Sorted array (selection sort): ");
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}

