#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

struct stack
{
    int top;
    char items[MAX];
}s;

char infix[100], postfix[100];
int pos=0;
void convert();
void push(char);
int empty();
int stackfull();
char pop();
int precedence(char);

int main()
{
    s.top=-1;
    printf("Enter the infix Expression:\n");
    gets(infix);
    convert();
    printf("postfix Expression\n");
    puts(postfix);
    return 0;
}
void convert()
{
    int i;
    char symbol, temp;
    for(i=0;infix[i]!='\0';i++)
    {
        symbol = infix[i];
        switch(symbol)
        {
        case '(':
            push(symbol);
            break;
        case ')':
            while((temp=pop())!='(')
                    postfix[pos++]=temp++;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '$':
            while(!empty()&&precedence(s.items[s.top])>=precedence(symbol))
            {
                temp = pop();
                postfix[pos]=temp;
                pos++;
            }
            push(symbol);
            break;
        default:
            postfix[pos++]=symbol;
            break;
        }
    }
    while(!empty())
    {
        temp = pop();
        postfix[pos++]=temp;
    }
    return 0;
}
void push(char ele)
{
    if(stackfull())
    {
        printf("stack Full!!\n");
    }
    else
        s.items[++s.top]=ele;
}
char pop()
{
    if(empty())
        printf("stack empty!!\n");
    else
        return(s.items[s.top--]);
}
int empty()
{
    if(s.top==-1)
        return 1;
    else
        return 0;
}
int stackfull()
{
    if(s.top==MAX-1)
        return 1;
    else
        return 0;
}
int precedence(char symbol)
{
    switch(symbol)
    {
    case '$':
        return 3;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '(':
    case ')':
        return 0;
        break;
    default:
        printf("Invalid input\n");
    }
}
