#include <stdio.h>
#include <stdlib.h>

int fact(long n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1)

    {
        return 1;
    }
    else{
        return(fact(n-1)+fact(n-2));
    }
}

int main()
{
    long n,f;
    for(;;)
    {
        printf("Enter the Number\n");
        scanf("%ld",&n);
        f = fact(n);
        printf("Fibo of %ld is %ld:\n", n,f);
    }

    return 0;
}

