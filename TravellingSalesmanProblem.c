#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices

int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
};

int visited[V];
int minPath[V + 1];
int minCost = INT_MAX;

void tsp(int currentVertex, int totalCost, int level) {
    if (level == V) {
        if (graph[currentVertex][0] != 0 && (totalCost + graph[currentVertex][0]) < minCost) {
            minCost = totalCost + graph[currentVertex][0];
            for (int i = 0; i < V; i++) {
                minPath[i] = visited[i];
            }
            minPath[V] = 0;
        }
        return;
    }

    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[currentVertex][i] != 0) {
            visited[i] = 1;
            tsp(i, totalCost + graph[currentVertex][i], level + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    visited[0] = 1;
    tsp(0, 0, 1);

    printf("Minimum Cost: %d\n", minCost);
    printf("Path: ");
    for (int i = 0; i <= V; i++) {
        printf("%d ", minPath[i]);
    }
    printf("\n");

    return 0;
}
