#include <stdio.h>
#include <stdlib.h>


int Partition(int a[],int l, int r)
{
    int p, i, j,temp;
    p=a[l];
    i=l;
    j=r+1;
    do  /** Till i and j crosses each other*/
    {
        do
        {
            i++;
        }while(a[i]<p&&i<=r);
        do
        {
            j--;
        }while(a[j]>p);

        if(i<=r)
        {
            temp = a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    if(i<=r)  /**Undo Unnecessary Swap*/
    {
        temp = a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    temp =a[l]; /**Swap Pivot and J^th element to put pivot in right position */
    a[l] = a[j];
    a[j]=temp;
    return j;
}

void QuickSort(int a[], int l, int r)
{
    if(l<r)
    {
        int s = Partition(a,l,r); /**Partition the array into sub- array based on pivot element*/
        QuickSort(a,l,s-1);/**Sort First sub-array*/
        QuickSort(a,s+1,r);/**Sort Second Sub-Array*/
    }
}

int main()
{
    int n,i;
    printf("Enter the Number of Elements: \n");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements: \n",n);
    for(i =0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array Before Sorting: \n");
    for(i =0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    QuickSort(a,0,n-1);
    printf("\nArray After Sorting : \n");
    for(i =0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
