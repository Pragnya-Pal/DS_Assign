
#include <stdio.h>
#define N 5

int id[N],front=-1,rear=-1;
char title[N][30];

void enqueue()
{
    if((rear+1)%N==front){
        printf("Queue full\n");
        return;
    }
    if(front==-1) front=0;
    rear=(rear+1)%N;
    printf("Enter job ID and title: ");
    scanf("%d%s",&id[rear],title[rear]);
}

void dequeue()
{
    if(front==-1){
        printf("Queue empty\n");
        return;
    }
    printf("Processed: %d %s\n",id[front],title[front]);
    if(front==rear) front=rear=-1;
    else front=(front+1)%N;
}

void display()
{
    int i;
    if(front==-1){
        printf("Queue empty\n");
        return;
    }
    i=front;
    while(1){
        printf("%d %s\n",id[i],title[i]);
        if(i==rear) break;
        i=(i+1)%N;
    }
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
