#include <stdio.h>
#include <stdlib.h>

int mini(int p, int k)
{
    if(p<k)
        return p;
    return k;
}

int binomial(int n, int k, int c[n+1][k+1])
{
    int i, j;
    for(i=0;i<=n;i++)
        for(j=0;j<=mini(i,k);j++)
            if(j==0 || i==j)
                c[i][j]=1;
            else
                c[i][j]=c[i-1][j-1] + c[i-1][j];
    return c[n][k];
}

int main()
{
    int n, k, coeff;
    printf("Enter n and k in c(n,k): \n");
    scanf("%d%d", &n,&k);
    if(k>n)
    {
        printf("Invalid Input!!");
        exit(0);
    }
    int table[n+1][k+1];
    coeff=binomial(n,k,table);
    printf("Binomial Coefficient, c(%d, %d) = %d\n", n,k,coeff);
    return 0;
}
