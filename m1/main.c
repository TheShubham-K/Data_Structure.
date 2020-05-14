#include <stdio.h>
#include <stdlib.h>

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
        printf("Memory Insufficient\n");
    }
    return (X);
}

NODE freenode(NODE *X)
{
    free(X);
}

NODE insert_front(NODE head, int item)
{
    NODE temp;
    temp=getnode();
    temp->info=item;
    temp->link=head->link;
    head->link=temp;
    return(head);
}

NODE delete_rear(NODE head)
{
    NODE cur, prev;
    if(head->link==NULL)
    {
        printf("list is Empty\n");
    }
    else
    {
        prev=head;
        cur=head->link;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        printf("%d deleted\n ", cur->info);
        freenode(cur);
        prev->link=NULL;
    }
    return(head);
}
NODE display(NODE head)
{
    NODE temp;
    if(head->link==NULL)
    {
        printf("list is Empty\n");
        return;
    }
    else
    {
        printf("contents of the list are: \n");
        temp=head->link;
        while(temp!=NULL)
        {
            printf("%d \n", temp->info);
            temp=temp->link;
        }
    }
    printf("\n");
}
int main()
{
    int choice, item;
    NODE head;
    head=getnode();
    head->link=NULL;
    for(;;)
    {
        printf("Enter your choice\n1.insert_frontq1a\n2.delete_rear\n3.display\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the elements to be inserted\n");
            scanf("%d", &item);
            head=insert_front(head, item);
            break;
        case 2:
            head=delete_rear(head);
            break;
        case 3:
            display(head);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
