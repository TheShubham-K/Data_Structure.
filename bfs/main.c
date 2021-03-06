#include <stdio.h>
#include <stdlib.h>

int count=0,v,e,visited[20],mat[20][20],queue[20],front=0,rear=-1;
void bfs(int w)
{
    int j;
    count++;
    visited[w]=count; /**Mark vertex w as visited*/
    queue[++rear]=w;
    while(front<=rear)
    {
        printf("%d(%d)\t",queue[front],visited[queue[front]]);
        for(j=0;j<v;j++)
        {
            if(visited[j]==0&&mat[queue[front]][j]==1)
            {
                count++;
                visited[j]=count;
                queue[++rear]=j;
            }
        }
        front++;
    }
}
void BFS()  /**TO ensure all the vertices are visited*/
{
    int i;
    for(i=1;i<=v;i++)
    {
        if(visited[i]==0)
        {
            bfs(i);
        }
    }
}

int main()
{
    int i, v1, v2, ch;
    printf("Select the type of Graph:\n\t> 1.Directed Graph\n\t>2.Undirected Graph\n");
    scanf("%d",&ch);
    if(ch!=1&&ch!=2)
    {
        printf("Invalid option !!\n");
        return 0;
    }
    printf("Enter the number of vertices: \n");
    scanf("%d",&v);
    printf("Enter the number of edges: \n");
    scanf("%d",&e);
    printf("Enter %d edges one by one: \n",e);
    for(i=1;i<=e;i++)
    {
        printf("Edge--%d: \n",i);
        scanf("%d%d",&v1,&v2);
        if(ch==1)
        {
            mat[v1][v2]=1; /**Directed Graph*/
        }
        else
        {
            mat[v1][v2]=mat[v2][v1]=1; /**Undirected Graph*/
        }
    }
    printf("\nOrder of vertices processed:\n");
    BFS();
    return 0;
}
