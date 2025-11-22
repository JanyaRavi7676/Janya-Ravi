#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 10
int s[size];
int top=0;
void main()
{
    char postfix[80];
    char infix[80];
    int i=0,j=0;
    void push(char ch);
    char pop();
    int priority(char ch);
    printf("enter the infix expression");
    gets(infix);
    push('#');
    while(infix[i]!='\0')
{
    if(isalnum(infix[i]))
    postfix[j++]=infix[i];
    else if(infix[i]=='(')
    push(infix[i]);
    else if(infix[i]==')')
    {
        while(infix[i]=='(')
        postfix[j++]=pop();
    }
    else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/')
    {
        while(priority(s[top])>=priority(infix[i]))
        postfix[j++]=pop();
        push(infix[i]);
    }
    else if(infix[i]=='$')
    push(infix[i]);
    else
    {
printf("illegal operator");
exit(0);
    }
    i++;
}
while(s[top]!='#')
postfix[j++]=pop();
postfix[j]='\0';
printf("the postfix expression is %s",postfix);
}
void push(char ch)
{
    if(top==size)
    {
        printf("stack is full ");
        exit(0);
    }
    else{
        top++;
        s[top]=ch;
        }
}
char pop()
{
    if(top==0)
    {
        printf("stack is full");
        exit(0);
    }
    else
    {
        int temp;
      temp=s[top];
      top--;
      return temp;
    }
}
int priority(char ch)
{
    if(ch=='('||ch=='#')
    return 1;
    if(ch=='+'||ch=='-')
    return 2;
    if(ch=='*'||ch=='/')
    return 3;
    if(ch=='$')
    return 4;
}