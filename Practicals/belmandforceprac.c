#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct edge
{
   int src;
   int wt;
   int dst;
};
int V,E;

void belmondForce(struct edge Edge[])
{
int *parent=(int*)malloc(V*sizeof(int));
int *cost_parent=(int*) malloc(V*sizeof(int));
int *value=(int*) malloc(V*sizeof(int));
parent[0]=-1;
value[0]=0;
int updated;
for(int i=0;i<V;i++)
{
updated=0;
for(int j=0;j<E;j++)
{
int U=Edge->src;
int V=Edge->dst;
int wt=Edge->wt;
if(value[U]!=INT_MAX && value[U]+wt<value[V])
{
    value[V]=value[U]+wt;
    parent[V]=U;
    cost_parent[V]=value[V];
    updated=1;
}
}
if(updated==0)
{
    break;
}
if(updated)
{
    for(int j=0;j<E;j++)
    {
        int U= Edge->src;
        int V=Edge->dst;
        int wt=Edge->wt;
        if(value[U]!=INT_MAX &&value[U]+wt<value[V])
        {
            printf("Graph has negative edge cycle\n");
            free(parent);
            free(cost_parent);
            free(value);
            return;

        }

    }
}
}
for (int i = 1; i < V; ++i)
        printf("U->V: %d->%d  Cost to reach %d from source 0 = %d\n", parent[i], i, parent[i], value[i]);

    free(parent);
    free(cost_parent);
    free(value);

}
int main()
{
    printf("Enter the no of edges:-\n");
    scanf("%d",&E);
    printf("Enter the no of vertices:-\n");
    scanf("%d",&V);
    struct edge *Edge =(struct edge*)malloc(E*sizeof(struct edge));
    for (int i = 0; i < E; ++i)
        scanf("%d %d %d", &Edge[i].src, &Edge[i].dst, &Edge[i].wt);

    belmondForce(Edge);

    free(Edge);
    return 0;


}