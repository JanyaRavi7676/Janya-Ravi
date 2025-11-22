#include<stdio.h>
#include<stdlib.h>
struct node *last=NULL;
struct node *new,*temp,*prev;
struct node
{
int info;
struct node *link;
};
void create_node()
{
int info;
new=(struct node *)malloc(sizeof(struct node));
new->link=NULL;
printf("Enter the data to be inserted\n");
scanf("%d",&info);
new->info=info;
}
void insert_front()
{
create_node();
if(last==NULL)
{
last=new;
new->link=new;
}
else
{
new->link=last->link;
last->link=new;
}
}
void insert_rear()
{
create_node();
if(last==NULL)
{
last=new;
new->link=new;
}
else
{
new->link=last->link;
last->link=new;
last=new;
}
}
void insert_info(int info)
{
27
if(last==NULL)
{
printf("Circular linked list is empty\n");
}
else
{
create_node();
if(last==NULL)
{
last=new;
new->link=new;
}
else
{
temp=last->link;
while(temp->info!=info && temp!=last)
{
prev=temp;
temp=temp->link;
}
if(temp==last&&temp->info!=info)
{
printf("Information not present\n");
}
else if(temp->info==info && temp==last->link)
{
new->link=last->link;
last->link=new;
}
else
{
prev->link=new;
new->link=temp;
}
}
}
}
void delete_front()
{
if(last==NULL)
{
printf("Circular linked list is empty\n");
}
else if(last->link==last)
{
printf("%d is deleted\n",last->info);
free(last);
last=NULL;
}
else
{
temp=last->link;
last->link=temp->link;
printf("%d is deleted\n",temp->info);
free(temp);
}
}
void delete_rear() {
if(last==NULL)
{
printf("Circular linked list is empty\n");
}
else if(last->link==last)
{
printf("%d is deleted\n",last->info);
free(last);
last=NULL;
}
else {
temp=last->link;
while(temp!=last) {
prev=temp;
temp=temp->link;
}
prev->link=last->link;
last=prev;
printf("%d is deleted\n",temp->info);
free(temp);
}
}
void delete_info(int info) {
if(last==NULL
)
{
printf("Circular linked list is empty\n");
}
else if(last->info==info && last->link==last)
{
printf("%d is deleted\n",last->info);
free(last);
last=NULL;
}
else {
temp=last->link;
while(temp->info!=info && temp!=last)
{
prev=temp;
temp=temp->link;
}
if(temp->info!=info && temp==last)
{
printf("Information not present\n");
}
else if(temp->info==info && temp==last)
{
prev->link=temp->link;
last=prev;
printf("%d is deleted\n",temp->info);
free(temp);
}
else if(temp->info==info && temp==last->link)
{
last->link=temp->link;
printf("%d is deleted\n",temp->info);
free(temp);
}
else
{
prev->link=temp->link;
printf("%d is deleted\n",temp->info);
free(temp);
}
}
}
void display()
{
if(last==NULL)
{
printf("Circular linked list is empty\n");
}
else
{
temp=last->link;
while(temp!=last)
{
printf("%d\t",temp->info);
temp=temp->link;
}
printf("%d",temp->info);
}
}
void main()
{
int info,ch;
while(1)
{
printf("\n1.Insert at front end\n 2.Insert at rear end\n 3.Insert based 
on information\n 4.Delete at front\n 5.Delete at rear\n 6.Delete based on 
information\n 7.Display\n 8.Exit\n");
printf("Enter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:insert_front();
break;
case 2:insert_rear();
break;
case 3: printf("Enter the information\n");
scanf("%d",&info);
insert_info(info);
break;
case 4:delete_front();
break;
case 5:delete_rear();
break;
case 6: printf("Enter the information\n");
scanf("%d",&info);
delete_info(info);
break;
case 7:display();
break;
case 8:Exit(0);
break;
default:printf("Invalid choice\n");
break;
}
}
}
}