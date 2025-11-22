#include<stdio.h>
main()
{
    int n,factorial;
    printf("Enter the number:");
    scanf("%d",&n);
factorial=fact(n);
printf("The factorial of the entered number is %d",fact);
}
fact(m)
int m;
{ 
    int f;
    if(m<=1)
    return 1;
    else
    f=m*fact(m);

}

