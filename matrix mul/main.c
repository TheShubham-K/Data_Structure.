#include <stdio.h>
#include <stdlib.h>


void read(int a[20][20],int n,int m)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void product(int a[20][20],int b[20][20],int c[20][20],int m,int n,int q)
{
    int i,j,k;
    for(i=0;i<m;i++)
    {
        for(j=0;j<q;j++)
        {
            c[i][j]=0;
            for(k=0;k<n;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
}

void display(int a[20][20],int m,int n)
{
    int i,j;
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
        }
    }
}

int main()
{
    int a[20][20],b[20][20],c[20][20],m,n,p,q;
    printf("Enter the order of matrix A:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the order of matrix B:\n");
    scanf("%d%d",&p,&q);
    if(n==p)
    {
        printf("\nEnter the Elements of Matrix A:\n");
        read(a,m,n);
        printf("\nEnter the Elements of Matrix B:\n");
        read(b,p,q);
        printf("Product of the matrices A and B is: \n");
        product(a,b,c,m,n,q);
        display(c,m,q);
    }
    else
    {
        printf("\nMatrix Multiplication is Incompatible!!\n");
    }
    return 0;
}
