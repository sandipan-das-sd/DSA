#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100

// Visited array with size equal to the maximum number of vertices
bool visited[MAX_SIZE];
int i,j;
// Adjacency matrix declaration
int adj[MAX_SIZE][MAX_SIZE];

// Array to store DFS traversal
int ans[MAX_SIZE];
int rear = -1; // Initializing rear to -1

// Function to enqueue a vertex into the answer array
void enqueue(int vertex) {
    ans[++rear] = vertex;
}

// Depth First Search traversal function
void dfs(int v, int n) {
    // Mark the current vertex as visited
    visited[v] = true;

    // Enqueue the current vertex into the answer array
    enqueue(v);

    // Traverse all adjacent vertices of the current vertex
    for( i = 0; i < n; i++) {
        // If an adjacent vertex is not visited and there is an edge between v and i
        if(!visited[i] && adj[v][i] == 1) {
            // Recursively call DFS for the adjacent vertex
            dfs(i, n);
        }
    }
}

int main() {
    int n; // Number of vertices

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for( i = 0; i < n; i++) {
        for( j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Initialize visited array
    for( i = 0; i < MAX_SIZE; i++) {
        visited[i] = false;
    }

    // Perform DFS traversal starting from vertex 0
    dfs(0, n);

    // Print DFS traversal
    printf("DFS Traversal: ");
    for( i = 0; i <= rear; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
//void dfs_utils(struct graph *g, int u, int visit[]) {
//    visit[u] = 1;  // mark the current node as visited
//    
//    printf("%d ", u);  // print the current node
//    struct ListNode *ptr = g->head[u];  // get the head of the adjacency list for the current node
//
//    // iterate over the adjacency list of the current node
//    for (; ptr != NULL; ptr = ptr->next) {
//        if (visit[ptr->data] == 0) {  // if the adjacent node is not visited yet
//            dfs_utils(g, ptr->data, visit);  // recursively call the dfs_utils function for the adjacent node
//        }
//    }
//}
//
//void dfs(struct graph *g, int n, int m) {
//    int visit[n];
//    memset(visit, 0, sizeof(visit));  // initialize the visit array with zeroes
//
//    // iterate over all nodes of the graph
//    for (int i = 0; i < n; i++) {
//        if (visit[i] == 0) {  // if the current node is not visited yet
//            dfs_utils(g, i, visit);  // call the dfs_utils function for the current node
//        }
//    }
//}
