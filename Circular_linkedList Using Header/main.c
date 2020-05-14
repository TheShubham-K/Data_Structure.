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
        printf("Memory not Allocated\n");
    }
    return(X);
}
NODE freenode(NODE *X)
{
    free(X);
}

NODE insert_rear(NODE head, int item)
{
    NODE temp, cur;
    temp=getnode();
    temp->info=item;
    cur=head->link;
    while(cur->link!=head)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=head;
    return(head);
}
NODE delete_rear(NODE head)
{
    NODE cur, prev;
    if(head->link==head)
    {
        printf("List is Empty\n");
        return;
    }
    prev=head;
    cur=head->link;
    while(cur->link!=head)
    {
        prev=cur;
        cur=cur->link;
    }
    printf("%d is deleted\n", cur->info);
    freenode(cur);
    prev->link=head;
    return(head);
}
NODE display(NODE head)
{
    NODE temp;
    if(head->link==head)
    {
        printf("List is Empty\n");
        return(NULL);
    }
    temp=head->link;
    printf("Contents of the list are:\n");
    while(temp->link!=head)
    {
        printf("%d\n", temp->info);
        temp=temp->link;
    }
    printf("%d", temp->info);
}
int main()
{
    NODE head;
    head=getnode();
    head->info=NULL;
    head->link=head;
    int ch,item;
    printf("1.insert_rear\n2.delete_rear\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter your Choice: \n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter the item to inserted\n");
            scanf("%d", &item);
            head=insert_rear(head, item);
            break;
        case 2:
            delete_rear(head);
            break;
        case 3:
            display(head);
            printf("\n");
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid Input\n");

        }
    }
    return 0;
}
