#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

int selectminkey(int value[], bool setMST[]) {
    int minimum = INT_MAX;
    int vertex = -1;
    for (int i = 0; i < V; i++) {
        if (!setMST[i] && value[i] < minimum) {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void primMST(int graph[V][V]) {
    int parent[V];    // Array to store constructed MST
    int value[V];     // Key values used to pick minimum weight edge in cut
    bool setMST[V];   // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        value[i] = INT_MAX;
        setMST[i] = false;
    }

    // Always include first 1st vertex in MST.
    value[0] = 0;    // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1;  // First node is always root of MST

    // The MST will have V vertices
    for (int i = 0; i < V - 1; i++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = selectminkey(value, setMST);

        // Add the picked vertex to the MST Set
        setMST[u] = true;

        // Update value and parent index of the adjacent vertices of the picked vertex.
        for (int j = 0; j < V; j++) {
            // graph[u][j] is non-zero only for adjacent vertices of m
            // setMST[j] is false for vertices not yet included in MST
            // Update the key only if graph[u][j] is smaller than value[j]
            if (graph[u][j] && !setMST[j] && graph[u][j] < value[j]) {
                parent[j] = u;
                value[j] = graph[u][j];
            }
        }
    }

    // Print the constructed MST
    for (int i = 1; i < V; i++)
        printf("U->V: %d->%d  wt = %d\n", parent[i], i, graph[parent[i]][i]);
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 5, 6},
        {4, 0, 7, 8, 6},
        {0, 7, 0, 5, 7},
        {5, 8, 5, 0, 7},
        {6, 6, 7, 7, 0}
    };

    primMST(graph);
    return 0;
}
