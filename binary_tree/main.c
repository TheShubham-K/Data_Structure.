#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    NODE p, cur, prev;
    char d[10];
    int i;
    p=getnode();
    p->info=item;
    p->llink=p->rlink=NULL;
    if(root==NULL)
    {
        return p;
    }
    printf("Give the Direction Where you want to insert:\n");
    scanf("%s", d);
    toupper(d);
    prev= NULL;
    cur=root;
    for(i=0;i<strlen(p);i++)
    {
        if(cur==NULL)
            break;
        prev=cur;
        if(d[i]=='L'||d[i]=='l')
            cur=cur->llink;
        else
            cur=cur->rlink;
    }
    if(cur !=NULL || i !=strlen(d))
    {
        printf("Insertion is not possible!!\n");
        freenode(p);
        return root;
    }
    if(d[i-1]=='L'||d[i-1]=='l')
        prev->llink=p;
    else
        prev->rlink=p;
    return root;
}
void preorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d\t", root->info);
    preorder(root->llink);
    preorder(root->rlink);
    return;
}

void inorder(NODE root)
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
void postorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t", root->info);
    return;
}
int main()
{
    int item;
    printf("1.insert\n2.Pre_order\n3.In_order\n4.Post_order\n5.Exit\n");
    NODE root=NULL;
    for(;;)
    {
        int ch;
        printf("Enter your Choice:\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            root=insert(root, item);
            break;
        case 2:
            preorder(root);
            printf("\n");
            break;
        case 3:
            inorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}
