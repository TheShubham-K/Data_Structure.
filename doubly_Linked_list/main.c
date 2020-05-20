#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *llink;
    struct node *rlink;
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
NODE insert_front(NODE head, int item)
{
    NODE temp, cur;
    temp=getnode();
    temp->info=item;
    if(head->rlink==NULL)
    {
        head->rlink=temp;
        temp->llink=head;
        temp->rlink=NULL;
        return(head);
    }
    else
    {
        cur=head->rlink;
        temp->llink=head;
        head->rlink=temp;
        temp->rlink=cur;
        cur->llink=temp;
    }
    return(head);
}

NODE Delete_rear(NODE head)
{
    NODE prev, cur;
    if(head->rlink==NULL)
    {
        printf("LIST IS EMPTY!!\n");
        return head;
    }
    else
    {
        cur=head->rlink;
        while(cur->rlink!=NULL)
        {
            cur=cur->rlink;
        }
        prev=cur->llink;
        printf("%d is deleted\n", cur->info);
        freenode(cur);
        prev->rlink=NULL;
        return(head);
    }
}

NODE display(NODE head)
{
    NODE temp;
    if(head->rlink==NULL)
    {
        printf("List is Empty!!\n");
        return;
    }
    else
    {
        temp=head->rlink;
        printf("Contents of the Doublley Linked List is: \n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->info);
            temp=temp->rlink;
        }
        printf("\n");
    }
}
int main()
{
    int ch, item;
    NODE head;
    head=getnode();
    head->info=0;
    head->llink=head->rlink=NULL;
    printf("1.Insert_Front\n2.Delete_Rear\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter your choice.\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter the item to be inserted.\n");
                scanf("%d", &item);
                head=insert_front(head, item);
                break;
            case 2:
                head=Delete_rear(head);
                break;
            case 3:
                display(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Input\n");
        }
    }
    return 0;
}
