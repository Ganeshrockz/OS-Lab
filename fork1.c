#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<dirent.h>
#include<errno.h>
int main()
{
int status;
char val[200];
pid_t fret=vfork();
if(fret==0)
{
printf("In child Process\n");
printf("Enter the value : ");
scanf("%s",val);
_exit(1);
}
else if(fret>0)
{
wait(&status);
printf("Entered value in child is %s",val);
printf("\n\nProcess terminated\n\n");
}
else
printf("error");
return 0;
}
