#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int dest;
};
int i;

void createGraph(struct Edge* graph[], int V) {
    for ( i = 0; i < V; i++) {
        graph[i] = NULL;
    }
}

void addEdge(struct Edge* graph[], int src, int dest) {
    struct Edge* newEdge = (struct Edge*)malloc(sizeof(struct Edge));
    newEdge->dest = dest;
    if (graph[src] == NULL) {
        graph[src] = newEdge;
    } else {
        // Traverse the list and add the new edge at the end
        struct Edge* temp = graph[src];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newEdge;
    }
}

int main() {
    int V = 4; // Number of vertices in the graph
    struct Edge* graph[V];
    createGraph(graph, V);

    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 2);

    // Print the adjacency list
    for ( i = 0; i < V; i++) {
        printf("Adjacency list for vertex %d:\n", i);
        struct Edge* current = graph[i];
        while (current != NULL) {
            printf("(%d -> %d) ", i, current->dest);
            current = current->next;
        }
        printf("\n");
    }

    // Free allocated memory
    for ( i = 0; i < V; i++) {
        struct Edge* current = graph[i];
        while (current != NULL) {
            struct Edge* temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}

