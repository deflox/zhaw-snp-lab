#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#define PERROR_AND_EXIT(M) do { perror(M); exit(EXIT_FAILURE); } while(0)

static void handler(int sig, siginfo_t *siginfo, void *context) {
    printf("caught(%d): source=%d, this=%d\n", sig, siginfo->si_pid, getpid());
    raise(SIGTERM); // send SIGTERM to itself (identical to kill(getpid(), SIGTERM))
}

static void set_handler(int sig, void (*handler)(int, siginfo_t *, void *)) {
    struct sigaction a = { 0 };
    a.sa_flags = SA_SIGINFO;  // handler variant with additional signal infosignature
    a.sa_sigaction = handler; // the handler to be registered
    if (sigfillset(&a.sa_mask) == -1) PERROR_AND_EXIT("sigfillset");  // block all Signals
    if (sigaction(sig, &a, NULL) == -1) PERROR_AND_EXIT("sigaction"); // register handler
}

static pid_t start_child() {
    pid_t cpid = fork();
    if (cpid == -1) PERROR_AND_EXIT("fork");
    if (cpid > 0) return cpid; // parent returns cpid
    set_handler(SIGUSR1, handler); // child...
    if (pause() == -1) PERROR_AND_EXIT("pause");
    exit(EXIT_FAILURE);
}

int main() {
    pid_t cpid = start_child(); // start child that waits for signal to terminate
    printf("parent=%d, child=%d\n", getpid(), cpid);
    sleep(1);                   // give time to the child to start
    if (kill(cpid, SIGUSR1) == -1) PERROR_AND_EXIT("kill"); // send signal to child
    int ws;
    if (wait(&ws) == -1) PERROR_AND_EXIT("wait");
    if (WIFEXITED(ws))   printf("child exit=%d (status=0x%04X)\n", WEXITSTATUS(ws), ws);
    if (WIFSIGNALED(ws)) printf("child signal=%d (status=0x%04X)\n", WTERMSIG(ws), ws);
}