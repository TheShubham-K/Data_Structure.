#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int a[],int n)
{
    int i,j,v;
    for(i=1;i<n;i++)
    {
        v=a[i];
        j=i-1;
        while(a[j]>v &&j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
    }
}


int main()
{
    int i,n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d Elements: \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array Before Sorting.\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    InsertionSort(a,n);
    printf("Array After Sorting.\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
