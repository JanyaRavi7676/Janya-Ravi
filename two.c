#include <stdio.h>
int CQ[80],front=0,rear=0;
int n;

main()
{
   int choice=0,l;
      printf("enter the size of the circular Q\n");
      scanf("%d",&n);
      while(choice!=4)
      {
	 printf("1   INSERT  \n");
	 printf("2   DELETE  \n");
	 printf("3   DISPLAY \n");
	 printf("4   EXIT    \n");
	 printf("Enter the choice\n");
	 scanf("%d",&choice);
	 switch(choice)
	 {
	    case 1: INSERT();
		    printf("CQ after insertion \n");
		    DISPLAY();
		    break;
	    case 2: l=DELETE();
		    printf("DELETED element is %d\n",l);
		    printf("CQ after deletion\n");
		    DISPLAY();
		    break;
	    case 3: printf("Content of the CQ\n");
		    DISPLAY();
		    break;
	    case 4: exit(0);
	 }
      }
   }

INSERT()
{
   int ele,t;
       printf("Enter the element to be insert\n");
       scanf("%d",&ele);
       t=rear;
       if(rear == n)
	 rear=1;
       else
	 rear++
	 if(rear!=front)
	 CQ[rear]=ele;
       else
       {
	 printf("CQ is over flow\n");
	 rear=t;
       }
       if(front==0)
	 front=1;
   }

DELETE()
{
  int p;
      if(front == 0)
      {
	 printf("CQ is underflow\n");
	 return(0);
      }
      p=CQ[front];
      if(front==n)
	front=1;
      else
      {
	if(front==rear)
	{
	  front=0;
	  rear=0;
	}
	else
    { 
    QUEUE.front++;
     return(ele);
      }
}


DISPLAY()
{
   int i;
      if(QUEUE.front == 0)
      {
	 printf("Queue is empty \n");
	 return;
      }
      printf("FRONT -> ");
      for(i=QUEUE.front;i<=QUEUE.rear;i++)
	 printf("%d-> ",QUEUE.item[i]);
      printf("REAR\n");
}
