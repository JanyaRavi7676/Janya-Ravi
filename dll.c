#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct node
{
    char name[80];
float marks;
int id,sem;
struct node *rlink,*llink;
};
 struct node *start=NULL,*new,*temp,*prev;
struct node* create()
{
    struct node *new;
    char name[80];
    int id,sem;
    float marks;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the name");
    scanf("%s",name);
    printf("enter the marks");
    scanf("%f",&marks);
    printf("enter the id");
    scanf("%d",&id);
    printf("enter the sem");
    scanf("%d",&sem);
    strcpy(new->name,name);
    new->id=id;
    new->sem=sem;
    new->marks=marks;
    new->rlink=new->llink=NULL;
return new;
}
void insert_front()
{
    struct node* new=create();
    if(start==NULL)
    {
        start=new;
    }
    else
    {
      new->rlink=start;
      start->llink=new;
      start=new;
    }
}
void insert_rear()
{
   struct node* new= create();
    if(start==NULL)
    {
        start=new;
    }
    else
    {
        temp=start;
        while(temp->rlink!=NULL)
        {
            temp=temp->rlink;
        }
        new->llink=temp;
        temp->rlink=new;
    }
}
void insert_info(int id)
{
    if(start==NULL)
    {
        printf("list is empty");
    }
    else{
      struct node* new= create();
        if(start->id==id)
        {
            new->rlink=start;
            start->llink=new;
            start=new;
        }
        else{
            temp=start;
            while((temp->rlink!=NULL)&&(temp->id!=id))
            {
                temp=temp->rlink;
            }
            if(temp->rlink==NULL && temp->id!=id)
            {
                printf("no info found");
            }
            else
            {
                temp->llink->rlink=new;
                new->llink=temp->llink;
                new->rlink=temp;
                temp->llink=new;
            }
        }
    }
}
void delete_info(int id)
{
    if(start==NULL)
    {
        printf("list is empty");
    }
    else{
         temp=start;
         while((temp->rlink!=NULL)&&(temp->id!=id))
         {
            temp=temp->rlink;
         }
         if(temp->rlink==NULL && temp->id!=id)
         {
            printf("no info found");
         }
         else if(temp->id==start->id && temp->rlink==NULL)
         {
            printf("deleted name is %s",temp->name);
            free(start);
            start=NULL;
         }
         else if (temp->id==start->id)
         {
           temp->rlink->llink=NULL;;
           start=temp->rlink;
           printf("deleted name is %s",temp->name);
           free(temp);
         }
         else if(temp->id==id && temp->rlink==NULL)
         {
            temp->llink->rlink=NULL;
            printf("deleted name is %s",temp->name);
            free(temp);
         }
         else {
            temp->llink->rlink=temp->rlink;
            temp->rlink->llink=temp->llink;
            printf("deleted name is %s",temp->name);
            free(temp);
         }
         
    }
}
void display()
{
    if(start==NULL)
    {
        printf("list is empty");
    }
    else{
        temp=start;
        while(temp!=NULL)
        {
            printf("student name:%s->",temp->name);
            printf("student id:%d->",temp->id);
            printf("student sem:%d->",temp->sem);
            printf("student marks:%f->",temp->marks);
            temp=temp->rlink;
        }
    }
}
void main()
{
    int id,ch;
    while(1)
    {
        printf("1.insert_front\n");
        printf("2.insert_rear\n");
        printf("3.insert_info\n");
        printf("4.delete_front\n");
        printf("5.display\n");
        printf("enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert_front();
            break;
            case 2: insert_rear();
            break;
            case 3:printf("entyer student id");
            scanf("%d",&id);
             insert_info(id);
            break;
            case 4:printf("enter id");
            scanf("%d",&id);
             delete_info(id);
            break;
            case 5:display();
            break;
        }
    }
}