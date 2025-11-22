#include<stdio.h>
int bs( int a[10],int key,int low, int high);
void main()
{
    int a[10],low,high,mid,key,i,n;
    printf("enter the size ");
    scanf("%d",&n);
    printf("enter elements");
    for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
    printf("enter the key element");
    scanf("%d",&key);
    low=0;
    high=n;
    bs(a,key,low,high);
}
int bs(int a[10], int key,int low,int high)
{
   int mid=(low+high)/2;
   if(key==a[mid])
   {
    printf("element %d is found at %d position",a[mid],mid);
   }
   if(key<a[mid])
    return bs(a, key, low,mid-1);
    else 
    return bs(a,key,mid+1,high);
}