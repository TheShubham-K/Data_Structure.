#include <stdio.h>
#include <stdlib.h>

int bubsort(int a[],int n)
{
    int t,i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}

int main()
{
    int i,n;
    printf("Enter the size of the Array:\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the Elements of An array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Elements of the Array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    bubsort(a,n);
    printf("Elements of the array after bubble sorting are: \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
