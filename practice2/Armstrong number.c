#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m, rem, sum=0, n;
    printf("Enter n: ",n);
    scanf("%d",&n);
    m=n;
    while(n>0)
    {
        rem = n%10;
        sum = sum + rem*rem*rem;
        n = n/10;
    }
    if (m==sum)
    {
        printf("Armstrong Number");
    }
    else
        printf("Not An Armstrong Number");

    return 0;
}
