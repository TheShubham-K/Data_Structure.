#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,flag,high,low,mid,key,i;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    int a[n];
    printf("Enter the Elements of the  array: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    high=n-1;
    low=0;
    flag=0;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(a[mid]==key)
        {
            flag=1;
            break;
        }
        else if(key>a[mid])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(flag==1)
    {
        printf("%d found and its position is %d\n",key,mid+1);
    }
    else
    {
        printf("%d not found\n",key);
    }
    return 0;
}
