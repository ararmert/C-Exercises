#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#define SEMNAME "/sysprak"

int main(int argc, char *argv[]) {
    
    sem_t *sem = sem_open(SEMNAME, O_CREAT | O_EXCL , 0660 , 1);
    if (errno != 0) { 
        printf (" Error : %d\n" , errno ); 
    }
    
    pid_t pid = fork ();
    if (pid == -1) { // fork error
     sem_close(sem);
     sem_unlink(SEMNAME);
     perror ("Failed to fork");
     } else if(pid == 0) { //Child process
         sem_wait(sem); //Blocking
         for(int i=0; i < 5; i++) {
            sleep (1); 
            printf ( "%d\n", i);
        }
        sem_post(sem); // Release
     } else { // Parent process 
        int wstatus;
        sleep(2);
        sem_trywait(sem); // Acquire ( blocking )
        
        printf("Now it 's my turn\n");
        sem_post(sem); // Release
        
        wait(&wstatus); 
        sem_close(sem);// CLeanup
        sem_unlink(SEMNAME); // Cleanup
    }
    return 0;
    
    
    
    //sem_wait() decrements (locks) the semaphore pointed to by sem.  If the semaphore's value is greater than zero, then the decrement proceeds, and the function returns, immediately.   If the  semaphore  currently  has the value zero, then the call blocks until either it becomes possible to perform the decrement (i.e., the semaphore value rises above zero), or a signal handler interrupts the call. sem_trywait() is the same as sem_wait(), except that if the decrement cannot be immediately performed, then call returns an error (errno set to EAGAIN) instead of blocking.
    
    //sem_trywait(sem) iken: 0
//Now it 's my turn
//1
//2
//3
//4
    //sem_wait(sem) iken 0 1 2 3 4 Now it's my turn
    


    
}
