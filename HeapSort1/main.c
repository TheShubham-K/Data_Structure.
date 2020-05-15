#include <stdio.h>
#include <stdlib.h>

void Heapify(int h[], int n)
{
    int i,j,v,k,heap;
    for(i>=(n/2);i>=1;i--)
    {
        k=i;
        v=h[k];
        heap=0;
        while(!heap && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(h[j]<h[j+1])
                    j++;
            }
            if(v>=h[j])
                heap=1;
            else
            {
                h[k]=h[j];
                k=j;
            }
        }
        h[k]=v;
    }
}

void HeapSort(int h[], int n)
{
    int i;
    Heapify(h,n);
    for(i=n;i>=2;i--)
    {
        h[1]=h[1]+h[i];
        h[i]=h[1]-h[i];
        h[1]=h[1]-h[i];
        Heapify(h, i-1);
    }
}

int main()
{
    int n,i;
    printf("Enter the number of elements: \n");
    scanf("%d",&n);
    int a[n+1];
    printf("Enter the %d Elements: \n", n);
    for(i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Array Before Sorting...\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t", a[i]);
    }
    HeapSort(a,n);
    printf("Array After Sorting...\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
