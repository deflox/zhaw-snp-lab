#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

#define PERROR_AND_EXIT(M) do { perror(M); exit(EXIT_FAILURE); } while(0)
#define QNAME "/demo"// the name must start on a slash
#define MSIZE 10

int main() {
    int q = 0, cpid = 0, n = 0, wpid = 0;

    // attributes of the queue
    struct mq_attr a = { .mq_maxmsg = 10, .mq_msgsize = MSIZE };

    // erstelle queue
    if ((q = mq_open(QNAME, O_CREAT|O_RDWR|O_NONBLOCK|O_EXCL, 0666, &a)) == -1) PERROR_AND_EXIT("mq_open");

    // führe fork durch
    if ((cpid = fork()) == -1) PERROR_AND_EXIT("fork");

    if (cpid > 0) { // parent: shares queue descriptor with child

        if (mq_unlink(QNAME) == -1) PERROR_AND_EXIT("mq_unlink"); // remove it from the filesystem again
        char msg[MSIZE+1]; // buffer allows for final '\0' to allow interpretation as string
        while(wpid == 0) { // read messages while the child process has not yet terminated
            sleep(1);        // poll interval for non-blocking mq_receive() and non-blocking waitpid()
            while ((n = mq_receive(q, msg, MSIZE, NULL)) > 0) { // read while there are messages
                msg[n] = '\0'; // prepare for printf
                printf("Message: '%s'\n", msg);
            }
            if (n == -1 && errno != EAGAIN) PERROR_AND_EXIT("mq_receive"); // non-blocking read handling
            if ((wpid = waitpid(cpid, NULL, WNOHANG)) == -1) PERROR_AND_EXIT("waitpid"); // non-blocking
        }
        
        if (mq_close(q) == -1) PERROR_AND_EXIT("mq_close"); // close when completed

    } else { // child: shares queue descriptor with parent
        if (mq_send(q, "Hello", sizeof("Hello"), 1) == -1) PERROR_AND_EXIT("mq_send");
        sleep(2);
        if (mq_send(q, "Queue", sizeof("Queue"), 1) == -1) PERROR_AND_EXIT("mq_send");
    }
}