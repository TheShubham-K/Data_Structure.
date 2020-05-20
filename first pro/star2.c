#include <stdio.h>
#include <conio.h>

int main()
{
   int i,j,k,n;
   printf("Enter Number:");
   scanf("%d",n);
   for(i=n;i>=1;i--)
   {
       for(k=1;k<=(n-i);k++)
        printf(" ");

       for(j=1;j<=i;j++)
        printf("*");

       for(j=2;j<=i;j++)
        printf("*");

       printf("\n");
   }
   return 0;
}
