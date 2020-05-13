#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

struct pqueue
{
    int items[SIZE];
    int rear, front;
};
void insert(struct pqueue *q, int ele)
{
    int j;
    if(q->rear==SIZE-1)
        printf("Priority Queue is Full\n");
    else
    {
        j=q->rear;
        while(j>=q->front && ele < q->items[j])
        {
            q->items[j+1] = q->items[j];
            j--;
        }
        q->items[j+1]= ele;
        q->rear++;
    }
}
void pqdelete(struct pqueue *q)
{
   int deleted;

   if(q->front > q->rear)
   {
       printf("Priority Queue is Empty");
   }
   else
   {
       printf("%d Deleted\n", q->items[q->front++]);
   }
   if(q->front > q->rear)
   {
       q->front = 0;
       q-> rear = -1;
   }
}
void display(struct pqueue *q)
{
    int i;
    if(q->front > q->rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i=q->front;i<=q->rear;i++)
        {
            printf("%d\n", q->items[i]);
        }
    }
}
int main()
{
    int choice;
    struct pqueue q;
    q.rear = -1;
    q.front = 0;
    for(;;)
    {
        int item;
        printf("Enter your choice\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the items to be inserted\n");
            scanf("%d",&item);
            insert(&q, item);
            break;
        case 2:
            pqdelete(&q);
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
