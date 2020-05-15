#include <stdio.h>
#include <stdlib.h>

int i,j,k,n,v,l,heap,true=1,false=0;

void heapConstr(int h[])
{
    for(i=(n/2);i>=1;i--)
    {
        k=i;
        v=h[k];
        heap=false;
        while(!heap && (2*k)<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(h[j]<h[j+1])
                    j=j+1;
            }
            if(v>=h[j])
            {
                heap=true;
            }
            else
            {
                h[k]=h[j];
                k=j;
            }
            h[k]=v;
        }
    }
    printf("\nAfter heap Construction:\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",h[i]);
    }
    heapsort(h);
}

void heapsort(int h[])
{
    int temp;
    temp = h[l];
    h[l]=h[n];
    h[n]=temp;
    printf("\n Element being Deleted: %d", h[n]);
    n--;
    if(n==0)
    {
        printf("\n HEAP SORT END ");
        exit(0);
    }
    heapConstr(h);
}


int main()
{
    int h[20];
    printf("Enter the Size: \n");
    scanf("%d", &n);
    printf("Enter the array Elements: \n");
    for(i=1;i<=n;i++)
    {
        scanf("%d", &h[i]);
    }
    heapConstr(h);
    return 0;
}
