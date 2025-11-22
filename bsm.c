#include<stdio.h>
#include<string.h>
 int bsm(char s[],char p[],int n,int m)
{
    int i,j=0;
    for(i=0;i<=n-1;i++)
    {
        j=0;
        while(j<m && s[i+j]==p[j])
        {
            j++;
            if(j==m)
            {
                return i+1;
            }
        }
    
    }
    return -1;
}
int main()
{
    int n,m,i,j,c;
    char s[80],p[80];
    printf("enter the source:\n");
    gets(s);
    printf("enter the pattern string:\n");
    gets(p);
    n=strlen(s);
    m=strlen(p);
    c=bsm(s,p,n,m);
    printf("the index matching string is %d\n",c);

}