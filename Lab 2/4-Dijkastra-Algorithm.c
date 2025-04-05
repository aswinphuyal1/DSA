#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

int mat[99][99] = {0};

void Edges(int numedge) {
    int node1, node2, weight;
    printf("Enter (node1) -> (node2) = weight:\n");
    for (int i = 0; i < numedge; i++) {
        scanf("%d%d%d", &node1, &node2, &weight);
        mat[node1][node2] = mat[node2][node1] = weight;
    }
}

// Function to find the vertex with the minimum distance value
int minDistance(int* distance, bool* visited, int node) {
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 1; i <= node; i++) {
        if (!visited[i]) {
            if (distance[i] < min) {
                min = distance[i];
                min_index = i;
            }
        }
    }
    return min_index;
}

// Function to find the shortest path using Dijkstra's Algorithm
void Dijkstra(int src, int node) {
    int* distance = (int*)malloc((node + 1) * sizeof(int));  // Dynamic allocation
    bool* visited = (bool*)malloc((node + 1) * sizeof(bool)); // Dynamic allocation

    // Initialize distance array and visited array
    for (int i = 1; i <= node; i++) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[src] = 0;

    // Apply Dijkstra's algorithm
    for (int count = 1; count <= node - 1; count++) {
        int u = minDistance(distance, visited, node);
        visited[u] = true;

        for (int i = 1; i <= node; i++) {
            if (!visited[i] && mat[u][i]) {
                if (distance[i] > distance[u] + mat[u][i])
                    distance[i] = distance[u] + mat[u][i];
            }
        }
    }

    // Display the results
    printf("Shortest path using Dijkstra's Algorithm :\n");
    printf("\n-------------------------------------------------------------\n");
    printf("%12s", "Node |");
    for (int i = 1; i <= node; i++)
        printf("%3d |", i);
    printf("\n-------------------------------------------------------------\n");
    printf("%12s", "Distance |");
    for (int i = 1; i <= node; i++)
        printf("%3d |", distance[i]);
    printf("\n-------------------------------------------------------------\n");

    // Free allocated memory
    free(distance);
    free(visited);
}

int main() {
    int node, numedges, src;
printf("**\tCompiled By Aswin phuyal\t**\n");
    printf("Enter number of nodes : ");
    scanf("%d", &node);
    printf("Enter number of edges : ");
    scanf("%d", &numedges);

    // Take input for edges
    Edges(numedges);

    printf("Enter the source node : ");
    scanf("%d", &src);

    // Find and display the shortest paths
    Dijkstra(src, node);
    return 0;
}

