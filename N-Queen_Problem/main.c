#include <stdio.h>
#include <stdlib.h>

int cannotBePlaced(int k, int col[])
{
    int i;
    for(i=1;i<=k-1;i++)
    {
        if(col[k]==col[i] || (abs(i-k)==abs(col[i] - col[k])))
            return 1;
    }
    return 0;
}


int NQueen(int n)
{
    int k = 1;
    int count=0;
    int i,j,col[n+1];
    col[k]=0;
    while(k!=0)
    {
        col[k] += 1;
        while(col[k]<=n && cannotBePlaced(k,col))
            col[k]=col[k]+1;
        if(col[k]<=n)
        {
            if(k==n)
            {
                count++;
                printf("\nSolution - %d : \n",count);
                for(i=1;i<=n;i++)
                {
                    for(j=1;j<=n;j++)
                        if(col[i] == j)
                            printf(" Q%d",i);
                        else
                            printf(" * ");
                    printf("\n\n");
                }
            }
        else
        {
            k++;
            col[k]=0;
        }
    }
    else
        k--;
    }
    return count;
}

int main()
{
    int n,solutions;
    printf("Enter the number of queens : ");
    scanf("%d",&n);
    solutions=NQueen(n);
    if(solutions==0)
        printf("No solution!!");
    return 0;
}
