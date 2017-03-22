#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
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
                printf("\nIN CHILD PROCESS\n");
                struct dirent*dpr=NULL;
                DIR*dp=NULL;
                dp=opendir("/home/iros39");
                if(dp!=NULL)
                {
                        while(dpr=readdir(dp))
                        {
                                printf("%s\n",dpr->d_name);
                        }
                }
        }
        else if(fret>0)
        {
                wait(&status);
                printf("\nProcess ended\n");
        }
        else
                printf("Error");
        return 0;
}
