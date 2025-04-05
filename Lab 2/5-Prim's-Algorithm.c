#include <stdio.h>
#include <limits.h>
int minKey(int key[], int mstSet[], int V);  // function prototype

// function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// function to implement prim algorithm
void primMST(int graph[99][99], int V) {
    int parent[V];  // array to store the MST
    int key[V];     // key values used to pick the minimum weight edge
    int mstSet[V];  // to represent the set of vertices included in the MST

    // initialize all key values to infinity and mstSet as 0
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;  // All vertices are initially not in MST
    }
    key[0] = 0;  // Start with the first vertex
    parent[0] = -1;  // The first node is always the root of MST

    // Build the MST
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex that is not yet included in MST
        int u = minKey(key, mstSet, V);
        mstSet[u] = 1;  // Add the picked vertex to the MST set

        // Update the key values and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            // graph[u][v] != 0 means there is an edge between u and v
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the edges of the MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int V, E, u, v, w;
    
    // Ask user for the number of vertices and edges
printf("**\tCompiled By Aswin phuyal\t**\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    
    // Create the adjacency matrix for the graph
    int graph[99][99] = {0};  // Maximum of 99 vertices, initialize all to 0
    
    // Ask user for the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    // Input the edges and their weights
    printf("Enter each edge in the format (vertex1 vertex2 weight):\n");
    for (int i = 0; i < E; i++) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = graph[v][u] = w;  // since graph is undirected
    }

    // call the prim's algorithm func
    primMST(graph, V);

    return 0;
}
