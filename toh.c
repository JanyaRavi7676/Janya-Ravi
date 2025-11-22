#include<stdio.h>
 void toh(int n, char A,char B,char C);
int count=0;
void main()
{
    int n;
    char x,y,z;
    printf("enter the value of n");
    scanf("%d",&n);
    toh(n,x,y,z);
    printf("number of moves is %d",count);
}
 void toh(int n,char x,char y,char z)
{
if(n==0)
{
    printf("no disks to move");
return;
}
if(n==1)
{
    printf("disk %d is moved from %c to %c",n,x,y);
    count++;
    return;
}
 toh(n-1,x,z,y);
 printf("move disk %d from %c to %c",n,x,y);
 count++;
 toh(n-1,z,y,x);
}