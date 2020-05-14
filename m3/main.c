#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define max 100

struct stack
{
    int top;
    double a[max];
};

void push(char symb, struct stack *s);
double pop(struct stack *s);
double compute(double op1,double op2, char symbol);

int main()
{
    struct stack s;
    int i;
    char postfix[1000],symbol;
    double op1,op2,res=0;
    s.top=-1;
    printf("Enter the postfix expression\n");
    gets(postfix);
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol = postfix[i];
        if(isdigit(symbol))
        {
            push(symbol, &s);
        }
        else
        {
            op2=pop(&s);
            op1=pop(&s);
            res=compute(op1,op2,symbol);
            s.a[++s.top]=res;
        }
    }
    res=pop(&s);
    printf("Result = %f", res);
    return 0;
}
void push(char symb, struct stack *s)
{
    if(s->top==max-1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->a[++s->top]=symb-'0';
        printf("%d",s->top);
    }
}
double pop(struct stack *s)
{
    if(s->top==-1)
    {
        printf("Stack Underflow\n");
    }
    else{
        int ele;
        ele=s->a[s->top];
        s->top--;
        printf("%d",s->top);
        return ele;
    }
}
double compute(double op1,double op2, char symbol)
{
    switch(symbol)
    {
    case '+':
        return(op1+op2);
        break;
    case '-':
        return(op1-op2);
        break;
    case '*':
        return(op1*op2);
        break;
    case '/':
        return(op1/op2);
        break;
    case '$':
        return(pow(op1,op2));
        break;
    default:
        printf("Invalid Input\n");
    }
}
