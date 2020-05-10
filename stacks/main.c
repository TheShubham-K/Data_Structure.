#include <stdio.h>
#define STACKSIZE 5

int top,s[50],item;
void push()
{
    if (top == STACKSIZE-1)
    {
        printf("stack overflow");
    }
    else
    {
        top++;
        s[top] = item;
    }
}
int pop()
{
    int item_deleted;
    if(top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        item_deleted = s[top];
        printf("item_deleted = %d\n", item_deleted);
        top--;
        return item_deleted;
    }
}
void display()
{
    int i ;
    if(top == -1)
    {
        printf("No Elements\n");
    }
    else
    {
        printf("Contents of the Stack are:\n");
        for(i=0;i<=top;i++)
        {
            printf("%d\n", s[i]);
        }
    }
}
int main()
{
    int item_deleted,choice;
    top--;
    for( ; ;)
    {
        printf("1.Push 2.Pop 3.Display 4.Exp\n");
        printf("Enter Choice:\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the elements to be inserted\n");
            scanf("%d", &item);
            push();
            break;
        case 2:
            item_deleted = pop();
            break;
        case 3:
            display();
            break;
        default :
            exit(0);
        }
    }
    return 0;
}
