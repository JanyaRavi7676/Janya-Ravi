#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *lchild,*rchlid;
};
struct node *root=NULL;
struct node *new,*temp;
void create(int x)
{
new=(struct node *)malloc(sizeof(struct node));
new->info=x;
new->lchild=new->rchlid=NULL;
if(root==NULL)
{
root=new;
}
else
{
temp=root;
while(1)
{
if(x<temp->info)
{
if(temp->lchild==NULL)
{
temp->lchild=new;
break;
}
else
{
temp=temp->lchild;
}
}
else if(x>temp->info)
{
if(temp->rchlid==NULL)
{
temp->rchlid=new;
break;
}
else
{
temp=temp->rchlid;
}
}
else{
    printf("%d is already exists,Enter new data\n",x);
    scanf("%d",&x);
    create(x);
    break;
    }
    }
    }
    }
    void display(struct node *R)
    {
    if(R!=NULL)
    {
    display(R->lchild);
    printf("%d\t",R->info);
    display(R->rchlid);
    }
    }
    void preorder(struct node *R)
    {
    if(R!=NULL)
    {
    printf("%d\t",R->info);
    preorder(R->lchild);
    preorder(R->rchlid);
    }
    }
    void inorder(struct node *R)
    {
    if(R!=NULL)
    {
    inorder(R->lchild);
    printf("%d\t",R->info);
    inorder(R->rchlid);
    }
    }
    void postorder(struct node *R)
    {
    if(R!=NULL)
    {
    postorder(R->lchild);
    postorder(R->rchlid);
    printf("%d\t",R->info);
    }
}
void main()
{
int n,x,i,ch;
while(1)
{
printf("\n1.Create_Tree\n" );
    printf("2.Display\n");
    printf("3.Preorder traversal\n");
    printf("4.Inorder traversal\n");
printf("5.Postorder traversal\n");
printf("6.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter number of nodes to be created in tree\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Enter the data part of node %d\n",i);
scanf("%d",&x);
create(x);
}
break;
case 2: if(root==NULL)
{
printf("Tree is empty\n");
}
else
{
printf("Elements of Binary search tree are :\n");
display(root);
}
break;
case 3: if(root==NULL)
{
printf("Tree is empty\n");
}
else
{
printf("Preorder traversal is:\n");
preorder(root);
}
break;
case 4: if(root==NULL)
{
printf("Tree is empty\n");
}
else
{
printf("Inorder traversal is:\n");
inorder(root);
}
break;
case 5: if(root==NULL)
{
printf("Tree is empty\n");
}
else
{
printf("Postorder traversal is:\n");
postorder(root);
}
break;
case 6:exit(0);
break;
default:printf("Invalid choice\n");
break;
}
}
}
