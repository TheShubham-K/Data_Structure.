#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    return (a > b)? a:b;
}


int KnapSack(int W, int wt[], int val[], int n)
{
    if(n == 0 || W == 0)
        return 0;
    if(wt[n-1] > W)
        return KnapSack(W, wt, val, n-1);
    else
        return max(val[n-1] + KnapSack(W-wt[n-1], wt, val, n-1), KnapSack(W, wt, val, n-1));
}


int main()
{
    int i,j,W,n,w;
    printf("Enter the Size of the VAL array: ");
    scanf("%d", &n);
    int val[n];
    printf("Enter the items Of the VAL Array: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &val[i]);
    }
    printf("Enter the Size of the Wt. array: ");
    scanf("%d", &w);
    int wt[w];
    printf("Enter the items Of the Wt. Array: \n");
    for(j=0;j<n;j++)
    {
        scanf("%d", &wt[j]);
    }
    printf("Enter the KnapSack Capacity: ");
    scanf("%d", &W);
    printf("%d", KnapSack(W, wt, val, n));
    return 0;
}
