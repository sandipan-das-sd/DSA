#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 5
int selectminKey(int value[],bool setMST[])
{
    int i;
    int minimum=INT_MAX;
   int vertex=-1;
   for(i=0;i<V;i++)
   {
    if(!setMST[i] && value[i]<minimum )
    {
        vertex=i;
        minimum=value[i];

    }
   }
   return vertex;
}
void findMST(int graph[V][V])
{
    int i,j;
    int parent[V];
    int value[V];
    bool setMST[V];
    for(i=0;i<V;i++)
    {
        value[i]=INT_MAX;
        setMST[i]=false;
    }
    parent[0]=-1;
    value[0]=0;
    for(i=0;i<V-1;i++)
    {
        int u=selectminKey(value,setMST);
        setMST[u]=true;
        for(j=0;j<V;j++)
        {
            if(graph[u][j] && !setMST[j] && graph[u][j]<value[j])
            {
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }
   // Print MST
    for (int i = 1; i < V; ++i)
        printf("U->V: %d->%d  wt = %d\n", parent[i], i, graph[parent[i]][i]);

}
int main()
{
    int graph[V][V]={
        {0,4,5,8,6},
        {1,7,9,3,6},
        {0,4,7,56,5},
        {1,7,3,8,4},
        {9,7,2,6,7}
       

    };
     
        findMST(graph);
        return 0;
}