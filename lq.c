#include<stdio.h>
#include<stdlib.h>
#define size 3
int q[size];
int ele,m,i;
int rear=0,front=0;
void insert(int ele)
{
    if(rear==size)
    {
        printf("queue is full");
        return;
    }
    else{
        rear++; 
        q[rear]=ele;
        if(front==0)
        front=1;
    }
}
int delete()
{
    int m;
    if(front==0)
    {
        printf("queue is empty");
        return 0;
    }
    else 
    {
        m=q[front];
        if(front==rear)
        {
            front=0;
            rear=0;
        }
        else 
        front++;
        printf("element deleted is %d",m);
    }
}
void display()
{
    if(front==0)
    {
        printf("queue is empty");
    }
    else 
    {
        for(i=front;i<=rear;i++)
        {
            printf("%d\n",q[i]);
        }
    }
}
void main()
{
    int choice,ele,m;
    while(1)
    {
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.display\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter the element to be inserted");
            scanf("%d",&ele);
            insert(ele);
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
        }

    }
}