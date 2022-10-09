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

  // connecting to a message queue. 
  int q_id = msgget(3333, 0777|IPC_CREAT);
  printf("message queue %d connected\n", q_id);

  // receive a message from the queue
  msgrcv(q_id, &msg, sizeof(msg.mtext), 1, 0);
  printf("message '%s' received from the queue %d\n", msg.mtext, q_id);

return 0;
}
