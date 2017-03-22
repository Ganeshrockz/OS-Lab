SERVER.C



#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
char c;
int shmid;
key_t key;
char*shm,*s;
key=ftok("server.c",'S');
shmid=shmget(key,30,IPC_CREAT|0666);
if(shmid<0)
{
printf("Error in shmget...\n");
exit(1);
}
if((shm=shmat(shmid,NULL,0))==(char*)-1)
{
printf("Error in shmat...");
exit(1);
}
s=shm;
for(c='a';c<='z';c++)
{
*s++=c;
}
*s=NULL;
while(*shm!='*')
sleep(1);
printf("In server...Info fetched by client....\n");
return 0;
}



CLIENT.C



#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
char c;
int shmid;
key_t key;
char*shm,*s;
key=ftok("server.c",'S');
shmid=shmget(key,30,0666);
if(shmid<0)
{
printf("Error in shmget...\n");
exit(1);
}
if((shm=shmat(shmid,NULL,0))==(char*)-1)
{
printf("Error in shmat...");
exit(1);
}
for(s=shm;(*s)!=NULL;s++)
{
putchar(*s);
}
putchar('\n');
*shm='*';
printf("Client Changed the state....\n");
return 0;
}
