#include <stdio.h>
#include <stdlib.h>

int v,e,k,visited[20],i,j,w,adj[20][20],in[20],count=0,order[20];

int is_all_node_visited()
{
    for(i=1;i<=v;i++)
    {
        if(visited[i]==0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    printf("Enter the number of vertices's ...\n");
    scanf("%d",&v);
    printf("Enter the number of edges...\n");
    scanf("%d", &e);
    printf("Enter the Adjancey Matrix .. .\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            if(adj[i][j] == 1)
            {
                in[j] = in[j] + 1;
            }
        }
    }
    while(1)
    {
        if(is_all_node_visited())
            break;
        else
        {
            for(i=1;i<=v;i++)
            {
                if(in[i] == 0 && visited[i] == 0)
                {
                    order[k] = i;
                    k++;
                    visited[i] = 1;
                    for(w=1;w<=v;w++)
                    {
                        if(adj[i][w] == 1 && visited[w] == 0)
                        {
                            in[w]--;
                        }
                    }
                }
            }
        }
    }
    printf("Topological Ordering is ....\n");
    for(i=0;i<v;i++)
    {
        printf("%d", order[i]);
    }
    return 0;
}
