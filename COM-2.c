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
