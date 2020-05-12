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
        printf("Memory not Allocated");
    }
    return(X);
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
    temp->link=NULL;
    if(head->link==NULL)
    {
        head->link=temp;

    }
    else
    {
        temp->link=head->link;
        head->link=temp;
    }
    return(head);
}
NODE delete_rear(NODE head)
{
    NODE cur, prev;
    if(head->link==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        cur=head->link;
        prev=head;
        while(cur->link!=NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        printf("%d is deleted \n",cur->info);
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
    printf("Contents of the list are: \n");
    temp=head->link;
    while(temp!=NULL)
    {
        printf("%d\n", temp->info);
        temp=temp->link;
    }
}
int main()
{
    int ch, item,item_deleted;
    NODE head;
    head=getnode();
    head->link=NULL;
    printf("1.Inser_front\n2.Delete_rear\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter your Choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d",&item);
            insert_front(head, item);
            break;
        case 2:
            item_deleted=delete_rear(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid input\n");
        }
    }
    return 0;
}
