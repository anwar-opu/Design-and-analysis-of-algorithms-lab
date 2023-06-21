#include <stdio.h>

struct MinMax {
    int min;
    int max;
};

struct MinMax findMinMax(int arr[], int low, int high) {
    struct MinMax mm, mmLeft, mmRight;
    int mid;

    if (low == high) {
        mm.min = arr[low];
        mm.max = arr[high];
        return mm;
    }

    if (high - low == 1) {
        if (arr[low] < arr[high]) {
            mm.min = arr[low];
            mm.max = arr[high];
        } else {
            mm.min = arr[high];
            mm.max = arr[low];
        }
        return mm;
    }

    mid = (low + high) / 2;
    mmLeft = findMinMax(arr, low, mid);
    mmRight = findMinMax(arr, mid + 1, high);

    mm.min = (mmLeft.min < mmRight.min) ? mmLeft.min : mmRight.min;
    mm.max = (mmLeft.max > mmRight.max) ? mmLeft.max : mmRight.max;

    return mm;
}

int main() {
    int arr[] = {7, 3, 9, 2, 5, 1, 8, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct MinMax result = findMinMax(arr, 0, size - 1);
    printf("Minimum number: %d\n", result.min);
    printf("Maximum number: %d\n", result.max);

    return 0;
}

