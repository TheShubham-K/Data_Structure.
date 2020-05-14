#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start,end;
double t;

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return (fact(n-1)*n);
    }
}

int main()
{
    int n,f;
    printf("Enter the Number\n");
    scanf("%d",&n);
    start=clock();

    f = fact(n);
    end=clock();
    t = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Factorial of %d is %d:\n", n,f);
    printf("%f",t);
    return 0;
}
