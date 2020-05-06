#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX], item, front, rear;

void insert()
{
    if(rear==MAX-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        rear++;
        queue[rear]=item;
    }
}
void Delete()
{
    int i;
    if(front>rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("%d deleted\n", queue[front++]);
    }
}
void display()
{
    int i;
    if(front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}

int main()
{
    int choice;
    rear=-1;
    front=0;
    for(;;)
    {
        printf("Enter your choice.\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the items to be inserted\n");
            scanf("%d",&item);
            insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}
