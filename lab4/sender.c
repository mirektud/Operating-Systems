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

  // create a message queue. 
  int q_id = msgget(3333, 0777|IPC_CREAT);
  printf("Message queue nr: '%d' is created\n",q_id);

  // create a message to send
  msg.mtype = 1; // set the type of message
  sprintf(msg.mtext,"Hello World!");
  printf("Message '%s' is created\n", msg.mtext);

  // send the message to the queue
  msgsnd(q_id, &msg, sizeof(msg.mtext), 0); 
  printf("Message  %s sent to the message queue nr: '%d'\n", msg.mtext, q_id);
return 0;
}
