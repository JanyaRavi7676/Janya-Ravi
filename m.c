#include<stdio.h>
int count;
void thanoi(int n,char source,char temp,char dest);
void main()
{
int n;
printf("Enter the number of disks\n");
scanf("%d",&n);
thanoi(n,'A','C','B');
printf("Number of moves=%d\n",count);
}
void thanoi(int n, char source, char dest, char temp)
{
if(n==0)
{
printf("No disk to move\n");
return;
}
if(n==1)
{
printf("move disk %d from %c to %c\n",n,source,dest);
count++;
return;
}
thanoi(n-1,source,temp,dest);
printf("move disk %d from %c to %c\n",n,source,dest);
count++;
thanoi(n-1,temp,dest,source);
}
