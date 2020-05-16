#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bruteforce(char t[100],char p[100])
{
    int i,j,m,n;
    n=strlen(t);
    m=strlen(p);
    for(i=0;i<n-m;i++){
        j=0;
        while(j<m && (p[j]=t[i+j]))
        {
            j++;
        }
        if(j=m)
        {
            return 1;
        }
    }
     return -1;
}

int main()
{
    int o;
    char t[100],p[100];
    printf("Enter the text:\n");
    scanf("%s",t);
    printf("Enter the Pattern:\n");
    scanf("%s",p);
    o=bruteforce(p,t);
    if(o!=-1)
    {
        printf("Matched\n");
    }
    else
    {
        printf("Not Matched\n");
    }
    return 0;
}
