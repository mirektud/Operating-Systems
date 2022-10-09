#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

struct msg_buf {
 long mtype;
 char mtext[128];
} msg;

int main(){

 int running = 1;

 // connecting to a message queue.
 int q_id = msgget(3333, 0777|IPC_CREAT);
 printf("Message queue %d is connected\n", q_id);

while(running){
 // receive a message from the queue
 msgrcv(q_id, &msg, sizeof(msg.mtext), 1, 0);
 printf("New message is received from the queue %d: %s\n", q_id, msg.mtext);

 if(strncmp(msg.mtext, "end", 3) == 0){
 running=0;
 }
}
return 0;
}
