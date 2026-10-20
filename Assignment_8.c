
#include <stdio.h>

int id[100],front=0,rear=-1;
char title[100][30];

void enqueue()
{
    if(rear==99){
        printf("Queue full\n");
        return;
    }
    rear++;
    printf("Enter job ID and title: ");
    scanf("%d%s",&id[rear],title[rear]);
}

void dequeue()
{
    if(front>rear) printf("Queue empty\n");
    else{
        printf("Processed: %d %s\n",id[front],title[front]);
        front++;
    }
}

void display()
{
    int i;
    for(i=front;i<=rear;i++)
        printf("%d %s\n",id[i],title[i]);
}

int main()
{
    int ch;
    while(1){
        printf("1.Add 2.Process 3.Display 4.Exit\n");
        scanf("%d",&ch);
        if(ch==1) enqueue();
        else if(ch==2) dequeue();
        else if(ch==3) display();
        else if(ch==4) break;
    }
    return 0;
}
