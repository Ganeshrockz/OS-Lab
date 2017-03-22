Addition of numbers with shared memory

GET.C


#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
int shmid;
key_t key;
char*shm,*s;
int a,b;
printf("Enter number a : ");
scanf("%d",&a);
printf("Enter number b : ");
scanf("%d",&b);
key=ftok("get.c",'G');
if((shmid=shmget(key,30,0666|IPC_CREAT))<0)
{
printf("Error in shmid..");
exit(1);
}
if((shm=shmat(shmid,NULL,0))==(char*)-1)
{
printf("Error in shmat");
exit(1);
}
s=shm;
*s++=(char)a;
*s++=(char)b;
*s=NULL;
while(*shm!='*')
sleep(1);
return 0;
}


PUT.C


#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
int shmid;
key_t key;
char*shm,*s;
key=ftok("get.c",'G');
if((shmid=shmget(key,30,0666|IPC_CREAT))<0)
{
printf("Error in shmid..");
exit(1);
}
if((shm=shmat(shmid,NULL,0))==(char*)-1)
{
printf("Error in shmat");
exit(1);
}
s=shm;
int a=(int)*s++;
int b=(int)*s++;
*shm='*';
printf("Addition is %d\n",a+b);
exit(0);
}
