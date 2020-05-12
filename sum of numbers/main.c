#include <stdio.h>
#include <stdlib.h>

int main()
{


    int m, rem, sum=0, n;
    printf("Enter n: ",n);
    scanf("%d",&n);
    while(n>0)
    {
        rem = n%10;
        sum = sum+rem;
        n = n/10;
    }
    printf("Sum of Digits are %d",sum);
    return 0;
}


