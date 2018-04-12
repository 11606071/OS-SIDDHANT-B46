#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
struct node{
int arrival;
int burst;
int totalBurst;
struct node *next;
}*temp,*ptr,*p,*save,*q,*g,*o,*y,*parent,*c;
int main()
{
    struct node *temp;                                                                                                            //O(1)
int i,e,n,d,k=0,ft=0,fw=0;                                                                                                                   //O(1)
printf("enter the no of processes:::");           							//O(1)
scanf("%d",&n);										//O(1)
o=ptr=q=g=temp=(struct node*)malloc(sizeof(struct node));                                                //O(1)
printf("enter the arrival time");                                                                                                //O(1)
scanf("%d",&temp->arrival);									//O(1)
printf("enter the burst time");									//O(1)
scanf("%d",&temp->burst);  									//O(1)
temp->totalBurst=temp->burst;								//O(1)
temp->next=NULL;										//O(1)
for(i=1;i<n;i++)										//O(n)
{
temp->next=(struct node*)malloc(sizeof(struct node)); 					//O(n)
temp=temp->next;										//O(n)
printf("enter the arrival time");								//O(n)
scanf("%d",&temp->arrival);									//O(n)
printf("enter the burst time");									//O(n)
scanf("%d",&temp->burst);									//O(n)
temp->totalBurst=temp->burst;								//O(n)
temp->next=NULL;										//O(n)
}
for(i=0;i<n;i++)
{
p=ptr;												//O(n)
while(save!=NULL)
{
p=ptr;										//O(n*n)
if(p->arrival>save->arrival)							//O(n*n)
{
e=save->arrival;								//O(n*n)
save->arrival=p->arrival;							//O(n*n)
p->arrival=e;									//O(n*n)
e=save->burst;									//O(n*n)
save->burst=p->burst;								//O(n*n)
p->burst=e;									//O(n*n)
p->totalBurst=p->burst;							//O(n*n)
save->totalBurst=save->burst;						//O(n*n)
}
save=save->next;								//O(n*n)
}
ptr=ptr->next;									//O(n)
}
q=g;										//O(1)
k=q->arrival;									//O(1)
int r=0;										//O(1)
while(k<200)
{
    parent=q->next;								//O(n)
    c=q;										//O(n)
    if(parent!=NULL)
    {
    while(parent->arrival<=k&&r!=1)						//O(n)
    {
    if(parent->burst<q->burst)							//O(n*n)
    {
        c=parent;									//O(n*n
    }
    parent=parent->next;							//O(n*n)
    if(parent==NULL)								//O(n*n)
    {
        r=1;									//O(n*n)
        break;									//O(n*n)
    }
    }
    }
c->burst--; 								//O(n)
if(c->burst==0)
{
    printf("Process executed at:%d\n",k+1);				//O(n)
ft+=k-c->arrival+1;
printf("Turn Around time of Process:%d\n",k-c->arrival+1);
fw+=k-c->arrival-c->totalBurst + 1; 	//O(n)
printf("Waiting Time:%d\n",k-c->arrival-c->totalBurst+1);		//O(n)
if(o==c)
{
    q=q->next;								//O(n)
    g=q;									//O(n)
    o=q;									//O(n)
}
else
{
while(o!=c)								//O(n)
{
     y=o;								//O(n*n)
     o=o->next;								//O(n*n)
}
 y->next=y->next->next;						//O(n)
}
printf("\n");								//O(n)
}
k++;									//	O(n)
}
printf("avg.waiting  time  :%d",ceil(fw/n));
printf("avg.turnaroundtime:%d",ceil(fw/n));
}
