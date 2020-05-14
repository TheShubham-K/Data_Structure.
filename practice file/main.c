#include <stdio.h>
#include <stdlib.h>

void Merge(int b[], int c[], int a[], int p, int q)
{
    int i=0,j=0,k=0;
}

void Quicksort(int a[], int l, int r)
{
    if(l<r)
    {
        int s = parition(a, l, r);
        Quicksort(a, l, s-1);
        Quicksort(a, s+1, r);
    }
}
int main()
{
    int i,n;
    printf("Enter the Number of Elements.\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array Before Sorting is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    Quicksort(a, 0 , n-1);
    printf("\nArray After Sorting is: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
