
#include <stdio.h>
#define N 10

void read(int a[N][N],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&a[i][j]);
}

void display(int a[N][N],int r,int c)
{
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
}

void add(int a[N][N],int b[N][N],int r,int c)
{
    int i,j,x[N][N];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++) x[i][j]=a[i][j]+b[i][j];
    display(x,r,c);
}

void subtract(int a[N][N],int b[N][N],int r,int c)
{
    int i,j,x[N][N];
    for(i=0;i<r;i++)
        for(j=0;j<c;j++) x[i][j]=a[i][j]-b[i][j];
    display(x,r,c);
}

void multiply(int a[N][N],int b[N][N],int x[N][N],
              int r,int c,int c2)
{
    int i,j,k;
    for(i=0;i<r;i++)
        for(j=0;j<c2;j++){
            x[i][j]=0;
            for(k=0;k<c;k++) x[i][j]+=a[i][k]*b[k][j];
        }
    display(x,r,c2);
}

void transpose(int a[N][N],int r,int c)
{
    int i,j;
    for(j=0;j<c;j++){
        for(i=0;i<r;i++) printf("%d ",a[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[N][N],b[N][N],r,c,r2,c2,ch;
    printf("Enter rows and columns of A: ");
    scanf("%d%d",&r,&c);
    printf("Enter A:\n"); read(a,r,c);

    printf("1.Add 2.Subtract 3.Multiply 4.Transpose A\n");
    scanf("%d",&ch);

    if(ch==4){ transpose(a,r,c); return 0; }

    printf("Enter rows and columns of B: ");
    scanf("%d%d",&r2,&c2);
    printf("Enter B:\n"); read(b,r2,c2);

    if(ch==1 && r==r2 && c==c2) add(a,b,r,c);
    else if(ch==2 && r==r2 && c==c2) subtract(a,b,r,c);
    else if(ch==3 && c==r2) multiply(a,b,a,r,c,c2);
    else printf("Incompatible dimensions\n");

    return 0;
}
