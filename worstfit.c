#include<stdio.h>
#include<string.h>
void sort(int*p,char s[10][10],int n)
{
int i,j,t;
char temp[20];
for(i=1;i<=n;i++)
{
for(j=i+1;j<=n;j++)
{
if(p[i]<p[j])
{
t=p[i];
p[i]=p[j];
p[j]=t;
strcpy(temp,s[i]);
strcpy(s[i],s[j]);
strcpy(s[j],temp);
}
}
}
}
int main()
{
int n;
printf("Enter no of holes : ");
scanf("%d",&n);
int i,h[n+1],s[n+1];
int visi[n+1];
char s1[10][10];
for(i=1;i<=n;i++)
{
printf("Enter name of hole %d : ",i);
scanf("%s",s1[i]);
printf("Enter size of hole %d : ",i);
scanf("%d",&h[i]);
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
sort(h,s1,n);
for(i=1;i<=n;i++)
{
s[i]=h[i];
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
printf("%s\t%d\t%d\n",s1[i],s[i]-h[i],h[i]);
}
return 0;
}
