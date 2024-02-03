#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Edge {
    int src, dest, wt;
};
int i,j;
void createGraph(struct Edge *graph[], int V) {
	
    for (i = 0; i < V; i++) {
        graph[i] = malloc(sizeof(struct Edge) * V);
    }

    graph[0][0] = (struct Edge) {0, 1, 1};
    graph[0][1] = (struct Edge) {0, 2, 1};
    graph[1][0] = (struct Edge) {1, 0, 1};
    graph[1][1] = (struct Edge) {1, 3, 1};
    graph[2][0] = (struct Edge) {2, 0, 1};
    graph[2][1] = (struct Edge) {2, 4, 1};
    graph[3][0] = (struct Edge) {3, 1, 1};
    graph[3][1] = (struct Edge) {3, 4, 1};
    graph[3][2] = (struct Edge) {3, 5, 1};
    graph[4][0] = (struct Edge) {4, 2, 1};
    graph[4][1] = (struct Edge) {4, 3, 1};
    graph[4][2] = (struct Edge) {4, 5, 1};
    graph[5][0] = (struct Edge) {5, 3, 1};
    graph[5][1] = (struct Edge) {5, 4, 1};
    graph[5][2] = (struct Edge) {5, 6, 1};
    graph[6][0] = (struct Edge) {6, 5, 1};
}

void bfs(struct Edge *graph[], int V) {
    bool visited[V];
    for ( i = 0; i < V; i++) {
        visited[i] = false;
    }

    int queue[V];
    int front = 0, rear = 0;
    queue[rear++] = 0; // Source = 0

    while (front < rear) {
        int curr = queue[front++];
        if (!visited[curr]) {
            printf("%d ", curr);
            visited[curr] = true;
            for ( i = 0; i < V; i++) {
                if (graph[curr][i].dest != -1) {
                    queue[rear++] = graph[curr][i].dest;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    /*
    1 --- 3
     /    | \
    0     |  5 -- 6
     \    | / 
       2 -- 4
    */
    int V = 7;
    int i,j;
    struct Edge *graph[V];
    for ( i = 0; i < V; i++) {
        graph[i] = malloc(sizeof(struct Edge) * V);
        for ( j = 0; j < V; j++) {
            graph[i][j].dest = -1;
        }
    }

    createGraph(graph, V);
    bfs(graph, V);

    // Free allocated memory
    for (i = 0; i < V; i++) {
        free(graph[i]);
    }

    return 0;
}

