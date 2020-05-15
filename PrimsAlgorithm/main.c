#include <stdio.h>
#include <stdlib.h>

int v,e,adjMat[20][20], VT[20], V_VT[20],edges[25][3],inc=0;

void initialize()
{
    int i;
    for(i=1;i<=v;i++)
    {
        VT[i] = 0;
        V_VT[i] = 1;
    }
    VT[1]=1;
    V_VT[1]=0;
}


void prims()
{
    int i,j,k,v1,v2,min;
    initialize();
    for(i=1;i<v;i++)
    {
        min = 9999;
        for(j=1;j<=v;j++)
            for(k=1;k<=v;k++)
            if(VT[j]!=0 && V_VT[k]!=0 && adjMat[j][k]<min)
        {
            min = adjMat[j][k];
            v1=j;
            v2=k;
        }
        edges[inc][0]=v1;
        edges[inc][1]=v2;
        edges[inc][2]=min;
        inc++;
        VT[v2]=1;
        V_VT[v2]=0;
    }
}


int main()
{
    int i,j,v1,v2,w, total=0;
    printf("Enter the number of Vertices : ");
    scanf("%d" , &v);
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    printf("Enter the %d edges : \n", e);

    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            if(i == j)
                adjMat[i][j]=0;
            else
                adjMat[i][j]=999;
        }
    }


    for(i=1;i<=e;i++)
    {
        printf("Edge- %d : ",i);
        scanf("%d%d",&v1,&v2);
        printf("Enter the weight of edge %d %d : ", v1,v2);
        scanf("%d",&w);
        adjMat[v1][v2] = adjMat[v2][v1] = w;
    }

   prims();

    printf("\nEdges in Minimum Spanning Tree : \n");
    for(i=0;i<inc;i++)
    {
        v1=edges[i][0];
        v2=edges[i][1];
        total += edges[i][2];
        printf("%d -- > %d (Weight : %d)\n",v1,v2,adjMat[v1][v2]);
    }
    printf("\nSum of edge Weight in minimum spanning tree : %d\n\n",total);
    return 0;
}
