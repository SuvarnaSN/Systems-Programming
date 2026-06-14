#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>

pid_t pid;
int status;
bool sigstpFlag = false;
bool sigint = false;


void signalhandler(int signal) {

        
    if(signal == SIGQUIT){
        printf("Terminating Parent Process because 'Ctrl\\' is recieved. \n");
        exit(0);
    }

    if(signal == SIGTSTP && sigstpFlag == false){
        
        printf("\nChild Process is suspended \n");
        sigstpFlag = true;
        return;
    }

    if (pid > 0 && sigint == false) {
        printf("\nSignal received. Killing child process.\n");
        sigint = true;
        kill(pid, SIGKILL); // Kill the child process
    }


}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <command> [args]\n", argv[0]);
        exit(-1);
    }

    signal(SIGINT,  signalhandler); // Ctrl + C
    signal(SIGTSTP, signalhandler); // Ctrl + Z
    signal(SIGQUIT, signalhandler); // Ctrl + \

    pid = fork(); // create child process
    if (pid == 0) { /* this is child process */
        execvp(argv[1], &argv[1]);
        perror("execvp");
        exit(-1);

    } else if (pid > 0) { /* this is the parent process */
        
        pid_t pid_child = waitpid(pid, &status, 0);
        if (pid_child == -1) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }

        if (WIFEXITED(status)) { /* child process terminated normally */
            printf("Child process status after exit  = %d\n", WEXITSTATUS(status));
        } else { 

            // printf("Child process did not terminate normally!\n");
            
            if (WIFSIGNALED(status)) {
                printf("Child process terminated status after exit: %d\n", WTERMSIG(status));
            }
        }

       

    } else { /* we have an error */
        perror("fork"); /* use perror to print the system error message */
        exit(EXIT_FAILURE);
    }

    for(;;){
        pause();
    }
    printf("[%ld]: Exit program .....\n", (long)getpid());

    return 0;
}
