#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct stack
{
    int top;
    char items[MAX];
};

void push(int item, struct stack *s)
{
    if(s->top == MAX-1)
    {
        printf("stack overflow\n");
    }
    else
    {
        (s->top)++;
        s->items[s->top]=item;
        printf("Item %d is pushed\n", item);
    }
}
void pop(struct stack *s)
{
    int item;
    if(s->top == -1)
    {
        printf("stack is empty\n");
    }
    else
    {
        item=s->items[s->top];
        (s->top)--;
        printf("%d is deleted\n", item);
    }
}
void display(struct stack *s)
{
    int t=s->top;
    if (s->top==-1)
    {
        printf("stack contains no elements\n");
    }
    else
    {
        printf("stack elements are\n");
        while(t>-1)
        {
            printf("%d\n",s->items[t--]);
        }
        printf("\n");
    }
}

int main()
{
    struct stack s;
    int item, choice;
    s.top = -1;
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the elements to be inserted\n");
            scanf("%d",&item);
            push(item,&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
