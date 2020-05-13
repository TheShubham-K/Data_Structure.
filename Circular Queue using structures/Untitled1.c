#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int items[SIZE];
int front=0;
int rear=-1;

void Insert();
void Delete();
void Display();

int isFull()
{
    if((front==rear+1)||(front==0 && rear==SIZE-1))
        return 1;
    else
        return 0;
}
int isEmpty()
{
    if(front==0)
        return 1;
    else
        return 0;
}
void Insert()
{
    int element;
    if(isFull())
        printf("Queue is full\n");
    else
    {
        printf("Enter the Elements\n");
        scanf("%d",&element);
        if(front==-1)
            front=0;
        rear=(rear+1)%SIZE;
        items[rear]=element;
    }
}
void Delete()
{
    int element;
    if(isEmpty())
        printf("Queue is empty\n");
    else
    {
        element = items[front];
        if(front==rear) {front = -1;rear=-1;}
        else
            front=(front+1)%SIZE;
        printf("Deleted elements %d\n",element);
    }
}
void Display()
{
   int i;
   if(isEmpty())
        printf("Queue is Empty\n");
   else
   {
       printf("Elements in the Queue\n");
       for(i=front;i!=rear;i=(i+1)%SIZE)
       {
           printf("%d",items[i]);
       }
       printf("%d\n",items[i]);
   }
}

int main()
{
    int choice;
    for(;;)
    {
        printf("Enter your choice:\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}
