#include <stdio.h>
#include <stdlib.h>

int A[25][25];
void Warshall(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                A[i][j]=A[i][j] || (A[i][k]&&A[k][j]);
}

int main()
{
    int v,e,i,j,v1,v2;
    printf("Enter the number of Vertices and edges: \n");
    scanf("%d%d", &v,&e);
    printf("\nEnter %d edges:\n", e);
    for(i=1;i<=e;i++)
    {
        printf("Edge--%d:",i);
        scanf("%d%d",&v1,&v2);
        A[v1][v2]=1;
    }
    printf("\n\nAdjacency Matrix:\n");
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
            printf("\t%d",A[i][j]);
        printf("\n");
    }
    Warshall(v);
    printf("\n\nTransitive Closure: \n");
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
            printf("\t%d",A[i][j]);
        printf("\n");
    }
    return 0;
}
