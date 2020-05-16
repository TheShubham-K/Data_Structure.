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

NODE insert(NODE root, int item)
{
    NODE temp, cur, prev;
    temp=getnode();
    temp->info=item;
    temp->llink=temp->rlink=NULL;
    if(root==NULL)
    {
        return(temp);
    }
    prev=NULL;
    cur=root;
    while(cur!=NULL)
    {
        prev=cur;
        if(item==cur->info)
        {
            printf("Duplication not Allowed\n");
            freenode(temp);
            return(root);
        }
        if(item<cur->info)
        {
            cur=cur->llink;
        }
        else
        {
            cur=cur->rlink;
        }
    }
    if(temp<prev->info)
    {
        prev->llink=temp;
    }
    else
    {
        prev->rlink=temp;
    }
    return(root);
}

NODE inorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->llink);
    printf("%d\t", root->info);
    inorder(root->rlink);
    return;
}

NODE search(NODE root, int item)
{
    if(root==NULL)
    {
        return(root);
    }
    while(root!=NULL)
    {
        if(item==root->info)
            break;
        if(item<root->info)
        {
            root=root->llink;
        }
        else
        {
            root=root->rlink;
        }
    }
    if(root==NULL)
    {
        printf("Key not Found\n");
        return(root);
    }
    printf("Key Found\n");
    return(root);
}
void MAX(NODE root)
{
    NODE cur;
    if(root==NULL)
    {
        return(root);
    }
    cur=root;
    while(cur->rlink!=NULL)
    {
        cur=cur->rlink;
    }
    printf("MAXIMUM is %d", cur->info);
}

int main()
{
    NODE root=NULL;
    int choice, item, key;
    printf("1.INSERT\n2.INORDER\n3.MAX\n4.SEARCH\n5.EXIT\n");
    for(;;)
    {
        printf("Enter your Choice:\n");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Enter the item to inserted.\n");
            scanf("%d", &item);
            root=insert(root, item);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            MAX(root);
            printf("\n");
            break;
        case 4:
            printf("ENTER THE ITEM TO BE SEARCHED\n");
            scanf("%d", &key);
            root=search(root, key);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}
