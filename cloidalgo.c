#include <stdio.h>

#define INF 9999 // Infinity value for representing absence of connection
#define V 4 // Define the number of vertices in the graph
int i,j,k;
// A function to print the solution matrix
void printSolution(int dist[][V], int n);

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int dist[][V], int n) {
    int i, j, k;

    /* Add all vertices one by one to
      the set of intermediate vertices.
      ---> Before start of an iteration, we
      have shortest distances between all
      pairs of vertices such that the shortest
      distances consider only the
      vertices in set {0, 1, 2, .. k-1} as
      intermediate vertices.
      ----> After the end of an iteration,
      vertex no. k is added to the set of
      intermediate vertices and the set
      becomes {0, 1, 2, .. k} */
    for (k = 0; k < n; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < n; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < n; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printSolution(dist, n);
}

/* A utility function to print solution */
void printSolution(int dist[][V], int n) {
    printf(
        "The following matrix shows the shortest distances"
        " between every pair of vertices \n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = V; // Number of vertices
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    // Function call
    floydWarshall(graph, n);
    return 0;
}


