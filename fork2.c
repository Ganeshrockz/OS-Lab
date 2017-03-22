#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
int main()
{
int status,n;
char v[20];
printf("Enter value : ");
scanf("%s",v);
pid_t fret=fork();
if(fret==0)
{
printf("Entered value in parent is %s",v);
}
else if(fret>0)
{
wait(&status);
printf("\nProcess terminated\n");
}
return 0;
}
