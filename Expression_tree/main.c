#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define max 100
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
        printf("Memory not Allocated!!\n");
    }
    return(X);
}

NODE create_tree(char postfix[])
{
    NODE temp, st[max];
    int i,k;
    char symbol;
    for(i=k=0;(symbol=postfix[i])!= '\0';i++)
    {
        symbol=postfix[i];
        temp=getnode();
        temp->info=symbol;
        temp->llink=temp->rlink=NULL;
        if(isalnum(symbol))
            st[k++]=temp;
        else
        {
            temp->rlink=st[--k];
            temp->llink=st[--k];
            st[k++]=temp;
        }
    }
    return(st[--k]);
}

float evaluate(NODE root)
{
    switch(root->info)
    {
    case '+':
        return(evaluate(root->llink)+evaluate(root->rlink));
        break;
    case '-':
        return(evaluate(root->llink)-evaluate(root->rlink));
        break;
    case '*':
        return(evaluate(root->llink)*evaluate(root->rlink));
        break;
    case '/':
        return(evaluate(root->llink)/evaluate(root->rlink));
        break;
    case '$':
    case '^':
        return(pow(evaluate(root->llink),evaluate(root->rlink)));
        break;
    default:
        return(root->info - '0');
    }
}

void inorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->llink);
    printf("%c\t", root->info);
    inorder(root->rlink);
    return;
}

int main()

{
    NODE root=NULL;
    char postfix[max];
    printf("Enter the Postfix Expression: \n");
    gets(postfix);
    root=create_tree(postfix);
    printf("Inorder: \n");
    inorder(root);
    printf("\nResult=%f\n", evaluate(root));
    return 0;
}
