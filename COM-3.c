#include<stdio.h>
#include<conio.h>
struct node{
int arrival;
int burst;
struct node *next;
};
int main()
{
int n,i,j,k,c,d,e,arrival[10];
struct node *temp,*ptr;
printf("enter the no of processes");
scanf("%d",&n);
for(i=0;i<=n;i++)
{
printf("enter the arrival time");
scanf("%d",&arrival[i]);
}
for(c=0;c<(n-1);c++)
{
for(d=c+1;d<n;d++)
{
if (arrival[c]>arrival[d])
{
e=arrival[d];
arrival[d]=arrival[c];
arrival[c]=e;
}
}
}
for(i=1;i<=n;i++)
{
temp=(struct node*)malloc(sizeof(struct node*));
temp->arrival=arrival[i];
printf("enter the burst time for process",a[i]);
scanf("%d",&temp->burst);
temp=temp->next;
}
}

