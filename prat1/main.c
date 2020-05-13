#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 1000
#include <math.h>

struct stack
{
    int top;
    char items[max];
}s;

int pos=0;
char infix[1000], postfix[1000];
void convert();
void push(char);
double pop();
int empty();
int stackfull();
int precedence(char);

void convert()
{
    int i;
    char symbol, temp;
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
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
                temp=pop();
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
    temp=pop();
    postfix[pos++]=temp;
}
return 0;
}
void push(char ele)
{
    if(stackfull())
    {
        printf("Stack overflow\n");
    }
    else
    {
        s.items[++s.top]=ele;
    }
}
double pop()
{
    if(empty())
        printf("Stack underflow\n");
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
    if(s.top==max-1)
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
        printf("Invalid Input\n");
        break;
    }
}

int main()
{
    s.top=-1;
    printf("Enter the infix Expression\n");
    gets(infix);
    convert();
    printf("Postfix Expression is:\n");
    puts(postfix);
    return 0;
}
