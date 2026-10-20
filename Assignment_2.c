
#include <stdio.h>

void display(int s[100][3],int n)
{
    int i;
    for(i=0;i<=n;i++)
        printf("%d %d %d\n",s[i][0],s[i][1],s[i][2]);
}

void transpose(int s[100][3],int t[100][3],int n,int c)
{
    int i,j,k=1;
    t[0][0]=s[0][1];
    t[0][1]=s[0][0];
    t[0][2]=n;

    for(i=0;i<c;i++)
        for(j=1;j<=n;j++)
            if(s[j][1]==i){
                t[k][0]=s[j][1];
                t[k][1]=s[j][0];
                t[k][2]=s[j][2];
                k++;
            }
}

int main()
{
    int a[10][10],s[100][3],t[100][3];
    int r,c,i,j,k=1,n=0;

    printf("Enter rows and columns: ");
    scanf("%d%d",&r,&c);

    printf("Enter matrix:\n");
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]!=0){
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=a[i][j];
                k++;
                n++;
            }
        }

    s[0][0]=r;
    s[0][1]=c;
    s[0][2]=n;

    printf("Sparse matrix:\n");
    display(s,n);

    transpose(s,t,n,c);
    printf("Transpose:\n");
    display(t,n);

    return 0;
}
