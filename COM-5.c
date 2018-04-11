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
    struct node *temp;
int i,e,n,d,k=0,ft=0,fw=0;
printf("enter the no of processes:::");
scanf("%d",&n);
o=ptr=q=g=temp=(struct node*)malloc(sizeof(struct node));
printf("enter the arrival time");
scanf("%d",&temp->arrival);
printf("enter the burst time");
scanf("%d",&temp->burst);
temp->totalBurst=temp->burst;
temp->next=NULL;
for(i=1;i<n;i++)
{
temp->next=(struct node*)malloc(sizeof(struct node));
temp=temp->next;
printf("enter the arrival time");
scanf("%d",&temp->arrival);
printf("enter the burst time");
scanf("%d",&temp->burst);
temp->totalBurst=temp->burst;
temp->next=NULL;
}
for(i=0;i<n;i++)
{
save=ptr->next;
p=ptr;
while(save!=NULL)
{
p=ptr;
if(p->arrival>save->arrival)
{
e=save->arrival;
save->arrival=p->arrival;
p->arrival=e;
e=save->burst;
save->burst=p->burst;
p->burst=e;
p->totalBurst=p->burst;
save->totalBurst=save->burst;
}
save=save->next;
}
ptr=ptr->next;
}
q=g;
k=q->arrival;
int r=0;

while(k<200)
{
    parent=q->next;
    c=q;
    if(parent!=NULL)
    {
    while(parent->arrival<=k&&r!=1)
    {
    if(parent->burst<q->burst)
    {
        c=parent;

    }
    parent=parent->next;
    if(parent==NULL)
    {
        r=1;
        break;
    }
    }
    }
c->burst--;
if(c->burst==0)
{
    printf("Process executed at:%d\n",k+1);
printf("Turn Around time of Process:%d\n",k-c->arrival+1);
ft+=k-c->arrival+1;
printf("Waiting Time:%d\n",k-c->arrival-c->totalBurst+1);
fw+=k-c->arrival-c->totalBurst+1;
if(o==c)
{
    q=q->next;
    g=q;
    o=q;
}
else
{
while(o!=c)
{
     y=o;
     o=o->next;
}
 y->next=y->next->next;
}
printf("\n");
}
k++;
}
printf("Avg. Waiting Time:%d",ceil(fw/n));
printf("Avg. TurnAroundTime:%d",ceil(ft/n));
}
