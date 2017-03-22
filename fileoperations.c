#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
char buf;
char in[256];
int fd=open("players.txt",O_RDWR | S_IREAD | S_IWRITE);
if(fd==-1)
{
printf("Error");
return 1;
}
printf("Players.txt Opened\n");
printf("\n");
while(read(fd,&buf,1))
{
printf("%c",buf);
}
int size=lseek(fd,0,SEEK_END);
printf("Size of file %d\n",size);
printf("\n");
int pos;
lseek(fd,0,0);
printf("Print the byte to print : ");
scanf("%d",&pos);
lseek(fd,pos-1,0);
int c=0;
while(1)
{
char pre;
read(fd,&pre,1);
c++;
if(pre=='\n'&&c!=1)
break;
else if(pre=='\n'&&c==1)
continue;
printf("%c",pre);
}
printf("\n");
close(fd);
printf("Enter 5 more names to be added");
fd=open("players.txt",O_RDWR | S_IREAD | S_IWRITE);
if(fd==-1)
{
printf("Error\n");
return 1;
}
else
printf("\nFileOpened\n");
int i=1;
lseek(fd,0,SEEK_END);
char ch='\n';
getchar();
while(i<=5)
{
printf("Enter name %d",i);
gets(in);
write(fd,in,strlen(in));
write(fd,&ch,1);
i++;
}
lseek(fd,0,0);
while(read(fd,&buf,1))
{
printf("%c",buf);
}
int size2=lseek(fd,0,SEEK_END);
printf("The size of file after inserting 5 names is %d\n",size2);
return 0;
}
