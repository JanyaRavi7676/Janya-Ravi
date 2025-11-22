#include<stdio.h>
#include<stdlib.h>
#define size 4
int cq[size];
int ele,m,i;
int rear=0,front=0;
void insert(int ele)
{
    int temp;
    temp=rear;
    if(rear==size)
    rear=1;
    else
     rear++;
    if(front==rear)
    {
        printf("queue is full");
        rear=temp;
    }
    else {
          cq[rear]=ele;
          if(front==0)
          front=1;
    }

}
int delete()
{
    if(front==0)
    {
        printf("queue is empty");
        return 0;
    }
    else{
        m=cq[front];
        if(front==size)
        {
            front=1;
        }
        else{
            if(front==rear)
            {
                front=0;
                rear=0;
            }
            else front++;
        }
        return m;
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
            if(front>rear)
            {
                for(i=front;i<size;i++)
                printf("%d\t",cq[i]);
                for(i=0;i<rear;i++)
                printf("%d\t",cq[i]);
            }
            else
            for(i=front;i<rear;i++)
            printf("%d\t",cq[i]);
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
    