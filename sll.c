#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct node{
    int stud_id;
    int sem;
    char stud_name[80];
    struct node *next;
};
 struct node *NEW,*START=NULL,*TEMP,*PREV;
void main()
{
    int s,id,choice=0;
char name[80];
while(1)
{
    printf("1.Insert");
    printf("2.Delete");
    printf("3.Display");
    printf("4.Exit");
    printf("enter the choice");
    scanf("%d",&choice);
switch (choice)
{
 case 1: insert();
 break;
 case 2: delete();
 break;
 case 3: display();
 break;
 case 4: exit(0);
 break;
}
}
}
struct node* create()
{
    int sem,s,id,stud_id;
    char name[80],stud_name[80];
    struct node *NEW;
    NEW=(struct node*)malloc(sizeof(struct node));
    printf("enter the info:");
    scanf("%d%s%d",&id,&name,&s);
    NEW->sem=s;
    NEW->stud_id=id;
    strcpy(NEW->stud_name,name);
    NEW->next=NULL;
return NEW;
}
 void insert()
{
   struct node* NEW= create();
    if(START==NULL)
    {
        START=NEW;
        TEMP=NEW;
    }
    else 
    {
        NEW->next=START;
        START=NEW;
        }
}

    
 void delete()
{
struct node *START,*NEW,*TEMP,*PREV;
int id,ele;
printf("enter the element to be deleted");
scanf("%d",&id);
if(START==NULL)
{
    printf("NO LIST FOUND");
    exit(0);
}
else
{
if(id==START->stud_id)
{    
TEMP=START;
START=START->next;
free(TEMP);
    }
else
{
    TEMP=START;
    while((TEMP!=NULL)&&(id!=TEMP->stud_id))
    {
        PREV=TEMP;
        TEMP=TEMP->next;
    }
if(TEMP==NULL)
{
printf("NO SUCH ID FOUND");
exit;
    }
    else
    {
        ele=TEMP->stud_id;
        PREV->next=TEMP->next;
    }
    }
}
}

 void display()
{
    struct node *START,*PREV,*TEMP;
    if(START==NULL)
{
printf("NO LIST FOUND");
exit(0);
}
else
{
    TEMP=START;
    while(TEMP!=NULL)
    {
        printf("%d%s%d->",TEMP->stud_id,TEMP->stud_name,TEMP->sem);
        TEMP=TEMP->next;
    }
    printf("\n\n");
}
}


