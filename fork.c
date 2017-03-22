#include<stdio.h>
#include<errno.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>
#define LEN 10
int main()
{
int i;
pid_t fret;
fret=fork();
if(fret==0)
{
int n=getpid();
int par=getppid();
printf("In child process\n\n");
printf("Child id");
printf(" %d\n\n",n);
printf("parentid");
printf(" %d\n\n",par);
}
else if(fret>0)
{
printf("In parent process\n\n");
int n=getpid();
printf("Parent Id");
printf(" %d\n\n",n);
}
else if(fret==-1)
{
printf("Error\n\n");
}
return 0;
}
