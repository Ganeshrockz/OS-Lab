#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int fd[2],fd1[2];
int i,j,k;
char s[10],a[10],b[10],d[10],e[10];
int as,status;
printf("Enter string : ");
scanf("%s",s);
pipe(fd);
pipe(fd1);
write(fd[1],s,sizeof(s));
pid_t f=vfork();
if(f==0)
{
read(fd[0],a,sizeof(a));
k=0;
i=0;
while(a[i]!='\0')
{
as=a[i];
as=as-97;
as=(as+3)%26;
as=as+97;
b[k++]=(char)as;
i++;
}
b[k]='\0';
printf("Encrypted string : %s\n",b);
write(fd1[1],b,sizeof(b));
_exit(1);
}
else
{
wait(&status);
read(fd1[0],d,sizeof(d));
printf("Encryted string in parent %s\n",d);
int k=0,l=0;
while(d[l]!='\0')
{
int as=d[l];
as=as-97;
if(as-3>=0)
as=(as-3)%26;
else
as=26-((as+1)%26);
as=as+97;
e[k++]=(char)as;
l++;
}
e[k]='\0';
printf("Decrypted string is %s\n",e);
}
return 0;
}
