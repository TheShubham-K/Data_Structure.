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
        printf("memory not Allocated");
    }
    return(X);
}
NODE freenode(NODE *X)
{
    free(X);
}

NODE insert_rear(NODE head,int item)
{
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    temp->link=NULL;
    if(head->link==NULL)
    {
        head->link=temp;
    }
    cur=head->link;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    cur->link=temp;
    temp->link=NULL;
    return(head);
}

NODE Delete_rear(NODE head)
{
    NODE prev,cur;
    if(head->link==NULL)
    {
        printf("List is Empty!!\n");
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
        printf("%d is deleted\n",cur->info);
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
        printf("List is empty!!\n");
        return;
    }
    else
    {
        temp=head->link;
        printf("contents are:\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->info);
            temp=temp->link;
        }
    }
}
int main()
{
    NODE head=getnode();
    head->info=NULL;
    head->link=NULL;
    int ch,item;
    printf("1.insert\n2.delete\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter your Choice..\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the item..\n");
            scanf("%d",&item);
            insert_rear(head,item);
            break;
        case 2:
            Delete_rear(head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            exit(0);
        default:
            printf("invalid input!!\n");
        }
    }
    return 0;
}
