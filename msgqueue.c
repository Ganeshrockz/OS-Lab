Shared memory with message queues

Server.c

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#define SIZE 120
struct msg
{
long type;
char msgtext[SIZE];
};
int main()
{
int id;
key_t key;
size_t len;
struct msg buf;
key=ftok("msgserver.c",'g');
if((id=msgget(key,IPC_CREAT | 0666))<0)
{
printf("Error..\n");
return 1;
}
buf.type=1;
printf("Enter Message : ");
scanf("%[^\n]",buf.msgtext);
len=strlen(buf.msgtext)+1;
if(msgsnd(id,&buf,len,IPC_NOWAIT)<0)
{
printf("Error in Sending.....\n");
return 1;
}
printf("\nMessage sent\n");
return 0;
}



Client.c

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#define SIZE 120
struct msg
{
long type;
char msgtext[SIZE];
};
int main()
{
int id;
key_t key;
size_t len;
struct msg buf;
key=ftok("msgserver.c",'g');
if((id=msgget(key,0666))<0)
{
printf("Error..\n");
return 1;
}
if(msgrcv(id,&buf,SIZE,1,0)<0)
{
printf("Error in receiving.....\n");
return 1;
}
printf("\nReceived message\n");
printf("\n%s\n",buf.msgtext);
return 0;
}
