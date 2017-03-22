#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
int main()
{
int status;
char buf;
int fd=open("parfile.txt",O_RDWR|S_IREAD|S_IWRITE);
if(fd==-1)
{
printf("Error");
return 1;
}
char val[200];
int i;
char ch='\n';
for(i=1;i<=5;i++)
{
scanf("%s",val);
write(fd,val,strlen(val));
write(fd,&ch,1);
}
lseek(fd,0,0);
pid_t fret=fork();
if(fret==0)
{
printf("\nProcess in child\n");
while(read(fd,&buf,1))
{
printf("%c",buf);
}
}
else if(fret>0)
{
wait(&status);
printf("\nProcess ended\n");
}
return 0;
}
