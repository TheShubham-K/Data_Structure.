#include <stdio.h>
#include <stdlib.h>


int binarySearch(int a[],int n,int key)
{
    int l=0,mid,r=n-1;
    while(l<=r)
    {
        mid = (l+r)/2;
        if(a[mid]==key)
            return mid;
        if(key<a[mid])
            r = mid -1;
        else
            l=mid +1;
    }
    return -1;
}

int main()
{
    int i,n,key;
    printf("Enter the number of Elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d Elements in Non-decreasing order: \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the Key to be Searched\n");
    scanf("%d", &key);
    i = binarySearch(a,n,key);
    if(i==-1)
    {
        printf("Key Element Not Found!\n");
    }
    else
    {
        printf("%d is present at position %d",key,i+1);
    }
    return 0;
}
