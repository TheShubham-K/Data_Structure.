#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

struct Cqueue
{
    int items[SIZE];
    int rear, front,count;
};
void insert(struct Cqueue *q, int item);
void Cqdelete(struct Cqueue *q);
void display(struct Cqueue *q);

int main()
{
    int choice;
    struct Cqueue q;
    q.rear=-1;
    q.front=0;
    q.count=0;
    for(;;)
    {
        int item;
        printf("Enter your choice\n");
        printf("1.insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the items to be inserted\n");
            scanf("%d",&item);
            insert(&q,item);
            break;
        case 2:
            Cqdelete(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}
void insert(struct Cqueue *q, int item)
{
    if(q->count == SIZE)
    {
        printf("Circular Queue is full\n");
    }
    else
    {
        q->rear=(q->rear++)%SIZE;
        q->items[q->rear]=item;
        q->count++;
    }
}
void Cqdelete(struct Cqueue *q)
{
    int deleted;
    if(q->count==0)
    {
        printf("Circular queue is empty\n");
    }
    else
    {
        deleted=q->items[q->front];
        printf("%d deleted\n", deleted);
        q->front=(q->front+1)%SIZE;
        q->count--;
    }
}
void display(struct Cqueue *q)
{
    int i, j;
    if(q->count==0)
    {
        printf("Circular queue is empty\n");
    }
    else
    {
        printf("Elements in the queue are:\n");
        for(i=1;i<=q->count;i++)
        {
            printf("%d\n",q->items[q->front]);
            q->front=(q->front++)%SIZE;
        }
    }
}
