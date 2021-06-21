#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define PERROR_AND_EXIT(M) do { perror(M); exit(EXIT_FAILURE); } while(0)

static pid_t start_child(int wait_for_signal) {
    pid_t cpid = fork();
    if (cpid == -1) PERROR_AND_EXIT("fork");
    if (cpid > 0) return cpid; // the parent returns the child pid
    if (wait_for_signal&& pause()== -1) PERROR_AND_EXIT("pause"); // one child waits for a signal
    exit(123);                                                      // the child exits normally
}

static void wait_for_child() {
    int wsts;
    pid_t wpid= wait(&wsts); // wait blocking for any child to terminate
    if (wpid == -1) PERROR_AND_EXIT("wait");
    if (WIFEXITED(wsts))   printf("Child %d: exit=%d (status=0x%04X)\n", wpid, WEXITSTATUS(wsts), wsts);
    if (WIFSIGNALED(wsts)) printf("Child %d: signal=%d (status=0x%04X)\n", wpid, WTERMSIG(wsts), wsts);
}

int main() {
    pid_t cpid1 = start_child(0); // start child that exits with exit code
    pid_t cpid2 = start_child(1); // start child that waits for signal to terminate
    printf("Children started: %d (term with exit), %d (term with signal)\n", cpid1, cpid2);
    sleep(1);                     // let the children start so that both child processes exist
    if (kill(cpid2, SIGTERM) == -1) PERROR_AND_EXIT("kill"); // tell the child to terminate gracefully
    wait_for_child(); // waits blocking until some child terminates
    wait_for_child(); // waits blocking until some child terminates
}