#include <stdio.h>
#include <string.h>

char stack[20], s1[20], s2[20];
int top, i;

int main()
{
    top = -1;
    printf("Enter the String\n");
    scanf("%s", s1);
    printf("String 1: %s\n", s1);
    for(i=0; s1[i]!='\0'; i++)
    {
        top++;
        stack[top]=s1[i];
    }
    printf("Stack: %s\n", stack);
    for(i=0;top!=-1;i++)
    {
        s2[i]=stack[top];
        top--;
    }
    printf("String 2: %s\n", s2);
    if(strcmp(s1,s2)!=0)
    {
        printf("%s is not a palindrome!!\n",s1);
    }
    else
    {
        printf("%s is a palindrome!!\n", s1);
    }
    return 0;
}
