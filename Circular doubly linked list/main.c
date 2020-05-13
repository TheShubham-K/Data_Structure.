#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *llink, *rlink;
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
    cur=head->rlink;
    temp->llink=head;
    head->rlink=temp;
    temp->rlink=cur;
    cur->llink=temp;
    return head;
}
NODE delete_rear(NODE head)
{
    NODE prev,cur;
    if(head->rlink==head)
    {
        printf("List is Empty!!\n");
        return head;
    }
    cur=head->rlink;
    prev=cur->llink;
    printf("%d is deleted\n",cur->info);
    freenode(cur);
    head->llink=prev;
    prev->rlink=head;
    return head;
}
NODE display(NODE head)
{
    NODE temp;
    if(head->rlink==head)
    {
        printf("List is Empty!!\n");
        return;
    }
    else
    {
        printf("Contents are: \n");
        temp=head->rlink;
        while(temp!=head)
        {
            printf("%d\n",temp->info);
            temp=temp->rlink;
        }
        printf("\n");
    }
}
int main()
{
    int ch,item;
    NODE head;
    head=getnode();
    head->info=0;
    head->llink=head->rlink=head;
    printf("1.Insert_front\n2.Delete_rear\n3.Display\n4.Exit\n");
    for(;;)
    {
        printf("Enter your choice.\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("Enter the item to be inserted.\n");
            scanf("%d",&item);
            head=insert_front(item,head);
            break;
        case 2:
            head=delete_rear(head);
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
