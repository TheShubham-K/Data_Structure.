#include <stdio.h>
#include <stdlib.h>

int weight[25],value[25],V[25][25];
int max(int a, int b)
{
    return (a > b)? a:b;
}

int MFK(int i, int j)
{
    if(i >= 0 && j >= 0)
    {
        int val;
        if(V[i][j]<0)
        {
            if(j<weight[i])
                val = MFK(i-1, j);
            else
                val = max(MFK(i-1,j), value[i] + MFK(i-1,j-weight[i]));
            V[i][j] = val;
        }
    }
    return V[i][j];
}

int main()
{
    int n,w,i,j,x,y,sol;
    printf("Enter the number of items : ");
    scanf("%d", &n);
    printf("Enter the threshold weight of Knapsack : ");
    scanf("%d", &w);
    for(i=0;i<=n;i++)
        for(j=0;j<=w;j++)
            if(i == 0 || j == 0)
                V[i][j] = 0;
            else
                V[i][j] = -1;
    printf("Enter Weight and Value of %d items : \n",n);
    printf("Format : Weight <space> Value\n");
    for(i=1;i<=n;i++)
    {
        printf("Item - %d : ",i);
        scanf("%d%d", &x, &y);
        weight[i] = x;
        value[i] = y;
    }
    sol = MFK(n,w);
    printf("The Optimal Solution is %d.", sol);
    return 0;
}
