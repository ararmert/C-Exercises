#include <stdio.h>
#include <signal.h>

void mysignalhandler(int signalKey) {
    switch(signalKey) {
        case SIGINT: // continue own code
            break;
    }
}


int main(int argc, char* argv[]) {
    signal(SIGINT, mysignalhandler); //use own Signal handler
    signal(SIGABORT, SIG_IGN); //ignore Signal

    //Regular signal handling
    signal(SIGINT, SIG_DFL); // default action associated with the signal occurs







}
