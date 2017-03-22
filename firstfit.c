#include<stdio.h>
int main()
{
int n;
printf("Enter no of holes : ");
scanf("%d",&n);
int i,h[n+1],s[n+1];
int visi[n+1];
for(i=1;i<=n;i++)
{
printf("Enter size of hole %d : ",i);
scanf("%d",&h[i]);
s[i]=h[i];
visi[i]=0;
}
int m;
printf("Enter number of processes : ");
scanf("%d",&m);
int p[m+1];
for(i=1;i<=m;i++)
{
printf("Enter size of process %d : ",i);
scanf("%d",&p[i]);
}
int j;
printf("Hole\tAllocation\tRemaining size\n");
for(i=1;i<=m;i++)
{
for(j=1;j<=n;j++)
{
if(h[j]>0)
{
if(p[i]<=h[j]&&visi[j]==0)
{
h[j]-=p[i];
visi[j]=1;
break;
}
}
}
}
for(i=1;i<=n;i++)
{
printf("%d\t%d\t%d\n",i,s[i]-h[i],h[i]);
}
return 0;
}
