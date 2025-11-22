#include <stdio.h>
#include<stdlib.h>
int stk[80];
int top=0;
int ele,p,n;
void push()
{
    int ele;
    if(top==n)
    {
    printf("Stack is full");
    return;
    }
    else
    { 
    printf("enter the element to be inserted");
    scanf("%d",&ele);
    top++;
    stk[top]=ele;
    }
}
int pop()
{
    int p;
    if(top==0)
    { 
        printf("Stack is empty");
        return 0;
    }
    else 
    {
        p=stk[top];
        top--;
        return p;
    }
}
void display()
{
    int i;
    if(top==0)
    {
        printf("stack is empty");
        return;
    }
    else 
    {
        for(i=top;i>=1;i--)
        printf("%d",stk[i]);
    }
}
int main() 
{
    void push();
    int pop();
    void display();
    int choice=0,n;
    printf("enter the size");
    scanf("%d",&n);
        printf("1.push\n");       
        printf("2.pop\n");
         printf("3.display\n");
        printf("4.exit\n");
        printf("enter the choice");
        scanf("%d",&choice);
        switch(choice)
        {
         case 1:  push();
         break;
         case 2: pop();
         printf("element deleted is %d",p);
         break;
         case 3: display();
         break;
         case 4: exit(0);
         break;
        }
}