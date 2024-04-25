#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main (void) {
    int x = 5;
    pid_t pid;
    
    if ((pid = fork()) < 0) {
        fprintf(stderr, "Error by fork().\n");
    } else if (pid == 0) { //Child process
        
        
        
        printf("In the child process with the pid %i: \n", getpid());
        printf("My PID = %i\n", getpid());
        printf("My Parent-PID = %i\n", getppid());
        printf("Add 1: x + 1 = %i\n\n", ++x);
        
    } else { //Eltern
       
        
        printf("In the parent process with the pid %i: \n", getpid());
        printf("My PID = %i\n", getpid());
        printf("My Parent-ID = %i\n", getppid());
        printf("Subtract 1: x -1 = %i\n\n", --x);
        
        
        }
        
    return 0;
}
        
// In the provided code, the fork() function creates a new process by duplicating the existing process. After the fork() call, there are two identical processes: the parent process and the child process. Both processes start executing from the line immediately after the fork() call, but there is no guarantee about the order in which they will be executed by the operating system. However, in this specific case, it appears that the parent process is evaluated first in terms of output because of how the operating system schedules the execution of processes. The parent process and the child process run concurrently, but the exact order in which they execute their code statements can be influenced by factors such as the CPU scheduling algorithm used by the operating system, the current system load, and other system-specific conditions. It's essential to note that the order of execution may vary each time the program is run, and it's not deterministic. Sometimes the child process may be evaluated first, and sometimes the parent process may be evaluated first. This behavior is inherent to the nature of concurrent execution in a multiprocessing environment.
