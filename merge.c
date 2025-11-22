#include<stdio.h>
#include<stdlib.h>
void merge(int a[200],int low,int mid,int high)
{
    int i,j,k,b[200],h;
    i=h=low;
    j=mid+1;
    while(h<=mid && j<=high)
    {
        if(a[h]<=a[j])
            b[i++]=a[h++];
        
        else
         
           b[i++]=a[j++]; 
        
    }
    if(h>mid)
    {
        for(k=j;k<=high;k++)
        b[i++]=a[k++];
    }
    else
    {
        for(k=h;k<=mid;k++)
        b[i++]=a[k++];
    }
    for(k=low;k<=high;k++)
    
        a[k]=b[k];
    
}
void divide(int a[],int low,int high)
{
    int i,n;
    if(low<high)
    {
        int mid=(low+high)/2;
        divide(a,low,mid);
        divide(a,mid+1,high);
        merge(a,low,mid,high);
    }
    
}
int main()
{
    int low,high,mid,a[200],b[200],i,j,k,n;
    printf("enter the value of n");
    scanf("%d",&n);
    low=1;
    high=n;
    printf("the unsorted elements are\n");
    for(i=low;i<=high;i++)
    {
        a[i]=rand()%100;
        printf("%d\t",a[i]);
    }
    divide(a, low, high);
    printf("the sorted elements are:");
    for(i=low;i<=high;i++)
    {
      printf("%d\t",a[i]);
    }
}
