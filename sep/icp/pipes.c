#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define PERROR_AND_EXIT(M) do { perror(M); exit(EXIT_FAILURE); } while(0)
#define MESSAGE "blocking pipe example message...\n"
#define MSIZE 10

int main() {
    
    // pipe eröffnen
    int fd[2];
    if (pipe(fd) == -1) PERROR_AND_EXIT("pipe");
    
    // fork child process
    pid_t cpid = fork();
    if (cpid == -1) PERROR_AND_EXIT("fork");

    if (cpid > 0) { // parent process
        
        // close descriptor for writing in child process
        if (close(fd[1]) == -1) PERROR_AND_EXIT("close");

        // read message from the pipe
        int n;
        do {
            char msg[MSIZE];
            n = read(fd[0], msg, MSIZE);
            if (n == -1) PERROR_AND_EXIT("read");
            write(STDOUT_FILENO, msg, n);
        } while (n > 0);

        if (close(fd[0]) == -1) PERROR_AND_EXIT("close");
        if (wait(NULL) == -1) PERROR_AND_EXIT("wait");

    } else { // child process

        // close descriptor for reading in child process
        if (close(fd[0]) == -1) PERROR_AND_EXIT("close");

        // write to queue
        if (write(fd[1], MESSAGE, sizeof(MESSAGE)) == -1) PERROR_AND_EXIT("write");

    }
}