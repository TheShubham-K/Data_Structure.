#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *rlink;
    struct node *llink;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE X;
    X=(NODE)malloc(sizeof(struct node));
    if(X==NULL)
    {
        printf("Memory is not available\n");
    }
    return(X);
}

void freenode(NODE *X)
{
    free(X);
}

NODE insert_rear(int item,NODE head)
{
    NODE temp,cur;
    temp=getnode();
    temp->info=item;
    cur=head->llink;
    temp->llink=cur;
    cur->rlink=temp;
    temp->rlink=head;
    head->llink=temp;
    return head;
}

NODE delete_front(NODE head)
{
    NODE cur,temp;
    if(head->rlink==head)
    {
        printf("List is Empty\n");
        return head;
    }
    cur=head->rlink;
    temp=cur->rlink;
    printf("Deleted Node = %d\n",cur->info);
    freenode(cur);
    head->rlink=temp;
    temp->llink=head;
    return head;
}

void display(NODE head)
{
    NODE cur;
    if(head->rlink==head)
    {
        printf("List is Empty\n");
        return;
    }
    printf("Contents of the Circular Doubly Linked List are:\n");
    cur=head->rlink;
    while(cur!=head)
    {
        printf("%d\t",cur->info);
        cur=cur->rlink;
    }
    printf("\n");
}
NODE insert_right(int item, int key, NODE head)
{
    NODE cur, temp;
    temp = getnode();
    temp->info = item;
    for(cur = head->rlink; cur!=head; cur = cur->rlink)
    {
        if(cur->info == key)
        {
            cur->rlink->llink = temp;
            temp->rlink = cur->rlink;
            cur->rlink = temp;
            temp->llink = cur;
            break;
        }
    }
    if(cur == head)
    {
        printf("Key Element not found!!");
        freenode(temp);
    }
    return head;
}

int main()
{
    int choice, item, key;
    NODE head = getnode();
    head->rlink = head->llink = head;
    while(1)
    {
        printf("\n1. Insert rear\t 2. Delete front\t 3. Insert right\t 4. Display\t 5.Exit\n");
        printf("Enter the choice...");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the element to insert :");
                scanf("%d",&item);
                head = insert_rear(item, head);
                break;
            case 2:
                head = delete_front(head);
                break;
            case 3:
                printf("\nEnter the element to insert :");
                scanf("%d",&item);
                printf("\nEnter the key element :");
                scanf("%d",&key);
                head = insert_right(item, key, head);
                break;
            case 4:
                display(head);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
    return 0;
}
