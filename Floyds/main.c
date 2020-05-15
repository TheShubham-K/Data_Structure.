#include <stdio.h>
#include <stdlib.h>

int W[25][25];

int mini(int a, int b)
{
    if(a<b)
        return a;
    return b;
}

void floyds(int n)
{
    int i, j, k;
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
                W[i][j]=mini(W[i][j], W[i][k]+W[k][j]);
            }
        }
    }
}

int main()
{
    int v,e,i,j,v1,v2,w;
    printf("Enter the number of vertices and edges: \n");
    scanf("%d%d", &v,&e);
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            if(i==j)
            {
                W[i][j]=0;
            }
            else
            {
                W[i][j]=999;
            }
        }
    }
    printf("\nEnter %d Edges:\n", e);
    for(i=1;i<=e;i++)
    {
        printf("\nEdge -- %d:",i);
        scanf("%d%d",&v1,&v2);
        printf("Enter the distance %d --> %d:\n",v1,v2);
        scanf("%d", &w);
        W[v1][v2]=w;
    }
    printf("\nWeight Matrix is :\n");
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
            printf("%d\t", W[i][j]);
        printf("\n");
    }
    floyds(v);
    printf("\nShorted distance Matrix:\n");
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
            printf("%d\t", W[i][j]);
        printf("\n");
    }
    return 0;
}
