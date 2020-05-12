#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct queue
{
    int rear, front;
    int queue[MAX];
};

void insert(struct queue *q, int item)
{
    if(q->rear==MAX-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear++;
        q->queue[q->rear]=item;
    }
}

void Delete(struct queue *q)
{
    if(q->front>q->rear)
        printf("Queue is empty\n");
    else
        printf("%d deleted", q->queue[q->front++]);
}

void display(struct queue *q)
{
    int i;
    if(q->front>q->rear)
        printf("Queue is empty\n");
    else
    {
        for(i=q->front;i<=q->rear;i++)
            printf("%d\n",q->queue[i]);
    }
}

int main()
{
    int choice;
    struct queue q;
    q.rear = -1;
    q.front = 0;
    for(;;)
    {
        int item;
        printf("Enter your Choice\n");
        printf("1.Enter\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the items to be inserted.\n");
            scanf("%d",&item);
            insert(&q, item);
            break;
        case 2:
            Delete(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("invalid input\n");
        }
    }
    return 0;
}
