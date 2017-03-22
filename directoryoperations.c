#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
int main()
{
char a[100];
printf("Enter dir name : ");
scanf("%s",a);
mkdir(a,S_IRWXU);
chdir(a);
printf("Directory changed to %s\n\n",a);
char b[100];
printf("Enter name of directory to be created : ");
scanf("%s",b);
mkdir(b,S_IRWXU);
printf("Directory B created\n\n");
char c[100];
printf("Enter name of directory : ");
scanf("%s",c);
printf("Directory moved\n\n");
struct dirent*dpr=NULL;
DIR *dp=NULL;
chdir("/home/iros39");
dp=opendir("/home/iros39");
if(dp!=NULL)
{
while(dpr=readdir(dp))
{
printf("%s\n",dpr->d_name);
}
}
return 0;
}
