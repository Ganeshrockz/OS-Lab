#include<stdio.h>
#define INT_MAX 10000
int at[10],bt[10],temp[10],wait[10],turn[10];
int visited[10];
int main()
{
int i,j,x,n;
printf("Enter no of processes : ");
scanf("%d",&n);
x=n;
int n1=n;
int c=1;
char proc[20][5];
while(n--)
{
printf("Process %d\n",c);
printf("Enter Process name : ");
scanf("%s",proc[c]);
printf("Enter arrival and burst time : ");
scanf("%d%d",&at[c],&bt[c]);
temp[c]=bt[c];
++c;
}
for(i=1;i<=x;i++)
{
visited[i]=0;
wait[i]=0;
}
int min1=1000;
int currprocess=1,tot=0;
while(1)
{
tot++;
bt[currprocess]-=1;
if(bt[currprocess]==0)
{
printf("%s\t%d\t%d\t%d\t%d\n",proc[currprocess],at[currprocess],temp[currprocess],wait[currprocess],temp[currprocess]+wait[currprocess]);
visited[currprocess]=1;
n1--;
if(n1==0)
break;
}
for(j=1;j<=x;j++)
{
if(j!=currprocess)
{
if(at[j]<tot&&visited[j]==0)
{
wait[j]++;
}
}
}
min1=1000;
for(j=1;j<=x;j++)
{
if(at[j]<=tot&&bt[j]<min1&&visited[j]==0)
{
currprocess=j;
min1=bt[j];
}
}
}
int totwait=0,totturn=0;
for(i=1;i<=x;i++)
{
totwait+=wait[i];
totturn+=wait[i]+temp[i];
}
printf("\nAverage wait time : %f\n",(float)totwait/x);
printf("\nAverage turn time : %f\n",(float)totturn/x);
return 0;
}
