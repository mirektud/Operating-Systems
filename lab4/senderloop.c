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
 char buffer[256];
 int running = 1;
 
 // create a message queue.
 int q_id = msgget(3333, 0777|IPC_CREAT);
 printf("Message queue nr: %d is created\n", q_id);

while(running){
// create a message to send
 msg.mtype = 1; // set the type of message
 printf("\nEnter some text: ");
 fgets(buffer, 256, stdin);
 strcpy(msg.mtext, buffer);
 printf("New message is created: %s", msg.mtext);

// send the message to the queue
 msgsnd(q_id, &msg, sizeof(msg.mtext), 0);
 printf("New message is sent to the message queue nr: %d", q_id);
 
 if(strncmp(msg.mtext, "end", 3) == 0){
 running=0;
 }
 
}
return 0;
}
