#include<stdio.h>

struct item {
    int weight;
    int value;
};

// Function to compare items based on their value/weight ratio
int cmp(const void *a, const void *b) {
    double ratio_a = ((struct item*)a)->value / (double)((struct item*)a)->weight;
    double ratio_b = ((struct item*)b)->value / (double)((struct item*)b)->weight;
    return ratio_b - ratio_a;
}

// Function to solve the fractional knapsack problem using the greedy method
double fractionalKnapsack(int capacity, struct item items[], int n) {
    // Sort items based on their value/weight ratio
    qsort(items, n, sizeof(struct item), cmp);

    double value = 0.0;
    int i;
    for (i = 0; i < n; i++) {
        if (capacity == 0) {
            return value;
        }

        int weight = items[i].weight;
        int itemValue = items[i].value;

        if (weight > capacity) {
            value += capacity * (itemValue / (double) weight);
            capacity = 0;
        } else {
            value += itemValue;
            capacity -= weight;
        }
    }

    return value;
}

// Main function to test the fractional knapsack algorithm
int main() {
    // Sample input
    int capacity = 50;
    struct item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);

    double max_value = fractionalKnapsack(capacity, items, n);
    printf("Maximum value: %lf", max_value);

    return 0;
}
