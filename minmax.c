#include<stdio.h>
#include<stdlib.h>
void mm(int a[],int i,int j,int *max,int *min)
{
    int mid,max1,min1;
    if(i==j)
    {
        *max=a[i];
        *min=a[i];
    }
    else if(i==j-1)
    {
        if(a[i]<a[j])
        {
            *max=a[j];
            *min=a[i];
        }
        else
        {
            *max=a[i];
            *min=a[j];
        }
    }
    else
    {
        mid=(i+j)/2;
        mm(a,i,mid,&max1,&min1);
        mm(a,mid+1,j,&max1,&min1);
        if(*max<max1)
        {
            *max=max1;
        }
        if(*min>min1)
        {
            *min=min1;
        }
    }
}
void main()
{
    int i=0,j,max,min,a[100],n;
    printf("enter the size of array\n");
    scanf("%d",&n);
    max=a[0];
    min=a[0];
    j=n;
    printf("the elements are:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d\t",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    mm(a,0,n-1,&max,&min);
    printf("the max element is %d\n",max);
    printf("the min element is %d\n",min);
}