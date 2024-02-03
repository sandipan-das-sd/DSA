#include <stdio.h>
#include <stdbool.h> // Include stdbool.h for boolean datatype
#include <limits.h> // Include limits.h for INT_MAX
#define MAX_VERTICES 100 // Define the maximum number of vertices

// Define global variables
int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
bool visited[MAX_VERTICES]; // Array to track visited vertices
int dist[MAX_VERTICES]; // Array to track distance from source
int pred[MAX_VERTICES]; // Array to track predecessor in the shortest path
int queue[MAX_VERTICES]; // Queue for BFS traversal
int front = 0, rear = -1; // Variables for queue
int i,neighbour,j;
// Function to add a vertex to the queue
void enqueue(int vertex) {
    queue[++rear] = vertex;
}

// Function to remove a vertex from the queue
int dequeue() {
    return queue[front++];
}

// Function to perform BFS traversal
bool bfs(int src, int dest, int vertex) {
    for ( i = 0; i < vertex; i++) {
        visited[i] = false;
        dist[i] = INT_MAX; // Initialize distances to infinity
        pred[i] = -1; // Initialize predecessors to -1
    }

    visited[src] = true;
    dist[src] = 0;
    enqueue(src);
 
    while (front <= rear) { // While queue is not empty
        int cur = dequeue();
        
        //Traverse neighbors of the current vertex
        for ( neighbour = 0; neighbour < vertex; neighbour++) {   
            if (adj[cur][neighbour] && !visited[neighbour])  {                                                                                                         
                visited[neighbour] = true;
                dist[neighbour] = dist[cur] + 1;
                pred[neighbour] = cur;
                enqueue(neighbour);
            }
        }
	
        if (cur == dest) { // If destination is reached
            return true;
        }
    }
    return false; // Destination not reachable
}

int main() {
    int vertex, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertex);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for ( i = 0; i < vertex; i++) {
        for ( j = 0; j < vertex; j++) {
            adj[i][j] = 0;
        }
    }

    // Input the edges
    printf("Enter the edges (format: src dest):\n");
    for ( i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        adj[dest][src] = 1; // Assuming undirected graph
    }

    int source, destination;
    printf("Enter source vertex: ");
    scanf("%d", &source);
    printf("Enter destination vertex: ");
    scanf("%d", &destination);

    if (bfs(source, destination, vertex)) {
        printf("There is a path from %d to %d\n", source, destination);
    } else {
        printf("There is no path from %d to %d\n", source, destination);
    }

    return 0;
}

