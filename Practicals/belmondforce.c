#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct edge {
    int src, dst, wt;
};

int V, E;

void bellmanFord(struct edge Edges[]) {
    int *parent = (int *)malloc(V * sizeof(int));
    int *cost_parent = (int *)malloc(V * sizeof(int));
    int *value = (int *)malloc(V * sizeof(int));
    
    for (int i = 0; i < V; ++i)
        value[i] = INT_MAX;
    
    parent[0] = -1;  // Start node has no parent
    value[0] = 0;    // Start node has value=0 to get picked 1st

    int updated;
    for (int i = 0; i < V - 1; ++i) {
        updated = 0;
        for (int j = 0; j < E; ++j) {
            int U = Edges[j].src;
            int V = Edges[j].dst;
            int wt = Edges[j].wt;
            if (value[U] != INT_MAX && value[U] + wt < value[V]) {
                value[V] = value[U] + wt;
                parent[V] = U;
                cost_parent[V] = value[V];
                updated = 1;
            }
        }
        if (updated == 0)
            break;
    }

    // Check for negative-weight cycles
    if (updated) {
        for (int j = 0; j < E; ++j) {
            int U = Edges[j].src;
            int V = Edges[j].dst;
            int wt = Edges[j].wt;
            if (value[U] != INT_MAX && value[U] + wt < value[V]) {
                printf("Graph has -VE edge cycle\n");
                free(parent);
                free(cost_parent);
                free(value);
                return;
            }
        }
    }

    // Print Shortest Path Graph
    for (int i = 1; i < V; ++i)
        printf("U->V: %d->%d  Cost to reach %d from source 0 = %d\n", parent[i], i, parent[i], value[i]);

    free(parent);
    free(cost_parent);
    free(value);
}

int main() {
    scanf("%d %d", &V, &E);  // Enter number of vertices and edges
    struct edge *Edges = (struct edge *)malloc(E * sizeof(struct edge));

    // Input all E edges
    for (int i = 0; i < E; ++i)
        scanf("%d %d %d", &Edges[i].src, &Edges[i].dst, &Edges[i].wt);

    bellmanFord(Edges);

    free(Edges);
    return 0;
}
