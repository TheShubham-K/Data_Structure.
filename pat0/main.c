#include <stdio.h>
#include <stdlib.h>
#define max 5

struct node
{
    int info;
    struct node *link;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE X;
    X=(NODE)malloc(sizeof(struct node));
    if(X==NULL)
    {
        printf("Memory inSufficient\n");
    }
    return(X);
}
NODE freenode(NODE *X)
{
    free(X);
}

NODE inserrear(NODE last, int item)
{
    NODE temp;
    temp=getnode();
    temp->info=item;
    if(last==NULL)
    {
        return(last);
    }
    else
    {
        temp->link=last->link;
        last->link=temp;
    }
    return(last);
}
NODE deleterear(NODE last)
{
    NODE prev;
    if(last==NULL)
    {
        printf("list is Empty\n");
        return(NULL);
    }
    if(last->link==NULL)
    {
        printf("The deleted item is %d\n", last->info);
        freenode(last);
        return(NULL);
    }
    prev=last->link;
    while(prev->link!=last)
    {
        prev=prev->link;
    }
    prev->link=last->link;
    freenode(last);
    return(prev);
}
NODE display(NODE last)
{
    NODE temp;
    if(last==NULL)
    {
        printf("list is Empty\n");
        return(NULL);
    }
    else
    {
        printf("the contents of the list are\n");
        for(temp=last->link;temp!=last;temp=temp->link)
        {
            printf("%d\n",temp->info);
        }
        printf("%d\n",temp->info);
    }
}
int main()
{
    int ch, item;
    NODE last;
    printf("1.Insert rear\n2.Delete rear\n3.Display\n");
    for(;;)
    {
        printf("Enter your choice\n");
        scanf("%d\n",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the item\n");
            scanf("%d\n", &item);
            last=inserrear(last, item);
            break;
        case 2:
            last=deleterear(last);
            break;
        case 3:
            display(last);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
