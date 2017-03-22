#include<stdio.h>
#include<string.h>
int main()
{
int i,n,tot=0,x,count=0,time1;
int wait=0,turn=0,at[10],bt[10],temp[10];
printf("Enter no of processes : ");
scanf("%d",&n);
x=n;
char proc[10][5];
for(i=1;i<=n;i++)
{
printf("Process %d\n",i);
printf("Enter Process name : ");
scanf("%s",proc[i]);
printf("Enter arrival and burst time : ");
scanf("%d%d",&at[i],&bt[i]);
temp[i]=bt[i];
}
printf("Enter time quantum : ");
scanf("%d",&time1);
printf("Process\tArrival\tBurst\tWait\tTurnaround\n");
for(tot=0,i=1;x!=0;)
{
if(temp[i]<=time1&&temp[i]>0)
{
tot+=temp[i];
temp[i]=0;
count=1;
}
else if(temp[i]>0)
{
temp[i]-=time1;
tot+=time1;
}
if(temp[i]==0&&count==1)
{
x--;
printf("%s\t%d\t%d\t%d\t%d\n",proc[i],at[i],bt[i],tot-at[i],tot-at[i]-bt[i]);
wait+=tot-at[i]-bt[i];
turn+=tot-at[i];
count=0;
}
if(i==n)
i=1;
else if(at[i]<=tot)
i++;
else
i=1;
}
printf("Average wait time : %f\n",(float)wait/n);
printf("Average turnaround time : %f\n",(float)turn/n);
return 0;
}
