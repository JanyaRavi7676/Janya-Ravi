#include<stdio.h>
int ss(int n, int a[])
{
    int i,j,min;
    for(i=1;i<=n-1;i++)
    {
        min=i;
        for(j=i+1;j=n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        swap(a[min],a[i]);
    }
}

void main()
{
    int n,a[80],min,i,j;
    printf("enter the value of n:\n");
    scanf("%d\n",&n);
    for(i=0;i<n;i++)
    scanf("%d\n",&a[i]);
    ss(n,a);
    printf("the array after swapping is\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}