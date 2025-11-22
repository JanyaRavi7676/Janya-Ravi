#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define size 8
int s[size],top=0,n=10;
void main()
{
    void push(int x);
    int pop();
    char exp[80];
    int op1,op2,op3,i=0,m;
    printf("enter the epression");
    gets(exp);
    while(exp[i]!='\0')
    {
        if(isdigit(exp[i]))
        push(exp[i]-'0');
        else
        {
            op2=pop();
            op1=pop();
            switch(exp[i])
            {
                case '+' : op3=op2+op1;
                break;
                case '-' : op3=op1-op2;
                break;
                case '*' : op3=op2*op1;
                break;
                case '/' : op3=op1/op2;
                break;
            }
            push(op3);
                }
            i++;
        }
        if(top<0)
        printf("invalid expression");
        else
        printf("the result is %d",s[top]);
    }
void push(int x)
{
    if(top==size)
    {
        printf("stack is full");
        exit(0);
    }
else
{
s[top++]=x;
}
}
int pop()
{ 
    int m;
    if(top==0)
    {
        printf("stack is empty");
        exit(0);
    }
    else
    {
      m=s[top];
      top--;
      return m;
    }
}
