
#include <stdio.h>

struct student {
    int roll;
    char name[20];
    float marks;
};

void display(struct student s[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d %s %.2f\n",s[i].roll,s[i].name,s[i].marks);
}

void insertionSort(struct student s[],int n)
{
    int i,j;
    struct student t;
    for(i=1;i<n;i++){
        t=s[i];
        j=i-1;
        while(j>=0 && s[j].roll>t.roll){
            s[j+1]=s[j];
            j--;
        }
        s[j+1]=t;
    }
}

void selectionSort(struct student s[],int n)
{
    int i,j,min;
    struct student t;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(s[j].roll<s[min].roll) min=j;
        t=s[i]; s[i]=s[min]; s[min]=t;
    }
}

void shellSort(struct student s[],int n)
{
    int gap,i,j;
    struct student t;
    for(gap=n/2;gap>0;gap/=2)
        for(i=gap;i<n;i++){
            t=s[i];
            for(j=i;j>=gap && s[j-gap].roll>t.roll;j-=gap)
                s[j]=s[j-gap];
            s[j]=t;
        }
}

void linearSearch(struct student s[],int n,int key)
{
    int i;
    for(i=0;i<n;i++)
        if(s[i].roll==key){
            printf("%d %s %.2f\n",s[i].roll,s[i].name,s[i].marks);
            return;
        }
    printf("Not found\n");
}

void binarySearch(struct student s[],int n,int key)
{
    int l=0,h=n-1,m;
    while(l<=h){
        m=(l+h)/2;
        if(s[m].roll==key){
            printf("%d %s %.2f\n",s[m].roll,s[m].name,s[m].marks);
            return;
        }
        if(s[m].roll<key) l=m+1;
        else h=m-1;
    }
    printf("Not found\n");
}

int main()
{
    struct student s[100];
    int n,i,ch,key;

    printf("Enter number of students: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Roll, name, marks: ");
        scanf("%d%s%f",&s[i].roll,s[i].name,&s[i].marks);
    }

    printf("1.Linear 2.Binary 3.Insertion 4.Selection 5.Shell\n");
    scanf("%d",&ch);

    if(ch==1){
        scanf("%d",&key);
        linearSearch(s,n,key);
    }
    else if(ch==2){
        insertionSort(s,n);
        scanf("%d",&key);
        binarySearch(s,n,key);
    }
    else if(ch==3) insertionSort(s,n);
    else if(ch==4) selectionSort(s,n);
    else if(ch==5) shellSort(s,n);

    if(ch>=3 && ch<=5) display(s,n);
    return 0;
}
