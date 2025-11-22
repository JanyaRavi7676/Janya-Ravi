#include<stdio.h>
#include<stdlib.h>
#define size 3
int pq[3][size],ele,p;
int rear[3]={-1,-1,-1};
int front[3]={-1,-1,-1};
void enqueue()
{
    int ele,p;
    printf("enter the priority");
    scanf("%d",&p);
    printf("enter the element");
    scanf("%d",&ele);
    if(rear[p]==size-1)
    {
        printf("queue is full");
        return;
    }
    else
    {
    pq[p][rear[p]++]=ele;
     if(front[p]==-1)
    front[p]=0;
    }
}
int dequeue()
{
    int m;
    for(p=0;p<=2;p++)
    {
        if(front[p]==-1)
        {
            printf("queue is empty");
            return 0;
        }
        else
        {
            m=pq[p][front[p]];
            if(front[p]==rear[p])
            {
                front[p]=-1;
                rear[p]=-1;
            }
            else 
            front[p]++;
            return m;
            printf("element deleted is %d",m);
        }
        }
    }
    void display()
    {
        int i;
        for(p=0;p<=2;p++)
        {
            if(front[p]==-1)
            {
                printf("queue is empty");
                return;
            }
            else
            {
                for(i=0;i<=rear[p];i++)
                printf("%d\t",pq[p][i]);

            }
        }
    }
int main()
{
    int m,choice=0;
    while(1)
    {
    printf("1.ENQUEUE\n");
    printf("2.DEQUEUE\n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n");
    printf("Enter the choice");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: enqueue();
        break;
        case 2: dequeue();
        break;
        case 3: display();
        break;
        case 4: exit(0);
        break;

    }
}
}