#include <stdio.h>
#include <stdlib.h>
#define max 5

struct Cqueue
{
    int rear, front, count;
    int items[max];
};

void insert(struct Cqueue *q, int item);
void Delete(struct Cqueue *q);
void display(struct Cqueue *q);


int main()
{
    int choice, item;
    struct Cqueue q;
    q.rear=-1;
    q.front=0;
    q.count=0;
    for(;;)
    {
        printf("Enter the choice\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the elements to be inserted\n");
            scanf("%d\n",&item);
            insert(&q,item);
            break;
        case 2:
            Delete(&q);
            break;
        case 3:
            display(&q);
            break;
        default:
            exit(0);
            break;
        }
    }
    return 0;
}
void insert(struct Cqueue *q, int item)
{
    if(q->count==max)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->rear=(q->rear++)%max;
        q->items[q->rear]=item;
        q->count++;
    }
}
void Delete(struct Cqueue *q)
{
    if(q->count==0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d deleted\n", q->items[q->front]);
        q->front=(q->front++)%max;
    }
        if(q->front>q->rear)
        {
            q->front=0;
            q->rear=-1;
        }
}
void display(struct Cqueue *q)
{
    int i;
    if(q->count==0)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("contents of the Queue is :\n");
        for(i=1;i<=q->count;i++)
        {
            printf("%d\n",q->items[i]);
        }
    }
}
