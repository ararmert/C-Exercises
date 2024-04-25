#include <stdlib.h>
#include <sys/wait.h> // Necessary for waitpid
#include <signal.h>

// Handler for the SIGCHLD signal
void sigchld_handler(int signum) {
    // Wait for all child processes to prevent zombies
    while (waitpid(-1, NULL, WNOHANG) > 0); // waitpid waits for changes in child process status
    // -1 (child PID): wait for all child processes. NULL for writing exit status of child process.
    // WNOHANG as an option indicates that waitpid should not wait if there are no child processes that have finished when waitpid is called
    // >0 means the child process has been cleaned up. > 0 means the PID of the child process
}

int main() {
    // Install handler for SIGCHLD
    signal(SIGCHLD, sigchld_handler); // signal sent to parent when child process ends
    // sigchld_handler type is void *int
    return 0;
}
