#include <stdio.h>
#include <stdlib.h>
void tower(int n, char sp, char dp, char ap);

int main()
{
    int n;
    printf("Enter the number of disk\n");
    scanf("%d\n",&n);
    printf("the Disk increments are\n");
    tower(n,'A','B','C');
    return 0;
}
void tower(int n, char sp, char dp, char ap)
{
    if(n==1)
        printf("Moving disk from %c to %c\n",sp,dp);
        return;
    tower(n-1,sp,ap,dp);
    printf("Move disk %d from %c to %c",n,sp,dp);
    tower(n-1,ap, dp, sp);
    return;
}
