#include <stdio.h> #include <stdlib.h>

struct node
{
    int id;
    char name[20];
    int sem;
    struct node *link;
};
typedef struct node *NODE;

int count=0;
NODE getnode()
{
    NODE x;
    x=(NODE)malloc(sizeof(struct node));
    if(x==NULL)
        printf("Memory not available");
    return(x);
}

NODE insert(int pos,NODE first)
{
    NODE temp,cur;
    int i;
    if(pos>count+1)
        {
            printf("Invalid position\n");
            return(first);
        }
    temp=getnode();
    printf("Enter id:");
    scanf("%d",&temp->id);
    printf("Enter name:");
    scanf("%s",temp->name);
    printf("Enter semester:");
    scanf("%d",&temp->sem);
    cur=first;
    if(first==NULL)
        {
            count++;
            return(temp);
        }
    else if(pos==0||pos==1)
        {
            count++;
            first->link=temp;
            return(first);
        }
    else
        {
            for(i=2;i<pos;i++)
                cur=cur->link;
            temp->link=cur->link;
            cur->link=temp;
            count++;
            return(first);
        }
}

NODE delete_front(NODE first)
{
    NODE cur;
    if(first==NULL)
        {
            printf("List is empty\n");
            return(first);
        }
    if(first->link==NULL)
        {
            printf("Deleted is %d\n",first->id);
            free(first);
            return(NULL);
        }
        cur=first->link;
        printf("Deleted is %d\n",first->id);
        free(first);
        return(cur);
}

void display(NODE first)
{
    NODE cur;
    if(first==NULL)
        {
            printf("List is empty\n");
            return;
        }
    printf("Contents are\n");
    cur=first;
    while(cur!=NULL)
        {
            printf("ID:%d\n",cur->id);
            printf("Name:%s\n",cur->name);
            printf("Semester:%d\n",cur->sem);
            cur=cur->link;
        }
}

int main()
{
    NODE first=NULL;
    int ch,pos;
    for(;;)
    {
        printf("1.Insert 2.Delete front 3.Display\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the position:");
                scanf("%d",&pos);
                first=insert(pos,first);
                break;
            case 2:
                delete_front(first);
                break;
            case 3:
                display(first);
                break;
            default:
                exit(0);
        }
    }
}
