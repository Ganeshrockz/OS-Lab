#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
int shmid;
char*shmptr;
int i;
if(fork()==0)
{
printf("Im Child.......\n");
sleep(2);
if((shmid=shmget(2041,32,0666))==-1)
{
printf("Error in shmget......");
exit(1);
}
shmptr=shmat(shmid,0,0);
if(shmptr==(char*)-1)
{
printf("Error in shmat......");
exit(2);
}
for(i=0;i<26;i++)
putchar(shmptr[i]);
putchar('\n');
}
else
{
printf("In parent.......\n");
if((shmid=shmget(2041,32,0666|IPC_CREAT))==-1)
{
printf("Error in shmget...");
exit(1);
}
shmptr=shmat(shmid,0,0);
if(shmptr==(char*)-1)
{
printf("Error in shmat");
exit(1);
}
for(i=0;i<26;i++)
shmptr[i]='a'+i;
for(i=0;i<26;i++)
putchar(shmptr[i]);
putchar('\n');
printf("Parent Waiting....\n");
wait();
shmdt(NULL);
if(shmctl(shmid,IPC_RMID,NULL)==-1)
{
printf("Error in shmctl...");
exit(1);
}
}
return 0;
}
