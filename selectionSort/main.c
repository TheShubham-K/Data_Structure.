#include <stdio.h>
#include <stdlib.h>

int selection(int a[],int n)
{
    int i,j,min,temp;
    for(i=0;i<n-2;i++)
    {
        min=i;
        for(j=i+1;j<n-1;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    return 0;
}
int main()
{
    int i,j,n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection(a,n);
    printf("After Sorting:\n");
    for(j=0;j<n;j++)
    {
        printf("%d\n",a[j]);
    }
    return 0;
}
