#include<stdio.h>
#include<string.h>
char proc[10][5];
void sort(int*at,int*bt,int n)
{
int i,j,temp1;
char temp[20];
for(i=1;i<=n;i++)
{
for(j=i+1;j<=n;j++)
{
if(at[i]>at[j])
{
temp1=at[i];
at[i]=at[j];
at[j]=temp1;
temp1=bt[i];
bt[i]=bt[j];
bt[j]=temp1;
strcpy(temp,proc[i]);
strcpy(proc[i],proc[j]);
strcpy(proc[j],temp);
}
}
}
}
int main()
{
int i,j,t,n;
printf("Enter no of processes : ");
scanf("%d",&t);
n=t;
int c=1;
int at[t+1],bt[t+1],wt[t+1],turn[t+1];
while(t--)
{
printf("\nProcess %d\n",c);
printf("Enter Process name : ");
scanf("%s",proc[c]);
printf("Enter arrival time and burst time : ");
scanf("%d%d",&at[c],&bt[c]);
++c;
}
int contime;
printf("Enter context switch time : ");
scanf("%d",&contime);
sort(at,bt,n);
int totwait=0;
int totturn=0;
wt[1]=0;
turn[1]=bt[1];
for(i=2;i<=n;i++)
{
if(at[i]<wt[i-1]+at[i-1]+bt[i-1])
wt[i]=wt[i-1]+at[i-1]+bt[i-1]-at[i]+contime;
else
wt[i]=contime;
totwait+=wt[i];
turn[i]=wt[i]+bt[i];
totturn+=turn[i];
}
printf("\nScheduling.......\n");
printf("\nProcess\tArrival\tBurst\tWait\tTurnaround\n");
for(i=1;i<=n;i++)
{
printf("%s\t%d\t%d\t%d\t%d\n",proc[i],at[i],bt[i],wt[i],turn[i]);
}
printf("Average wait time : %f\n",(float)totwait/n);
printf("Average turnaround : %f\n",(float)totturn/n);
return 0;
}
