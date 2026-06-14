#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAXCOMMANDLENGTH 1000

int main(int argc, char** argv){

    pid_t pid1, pid2;
    int status;
    int pipefd[2];
    char* commandValue;
    FILE *ofp;

    while(true){

        printf("\nEnter command: ");

        // store the entered commands
        commandValue = (char *)malloc(sizeof(char) * MAXCOMMANDLENGTH);
        if (commandValue == NULL) {
            perror("Error allocating memory");
            return -1;
        }
        
        if (fgets(commandValue, MAXCOMMANDLENGTH, stdin) == NULL) {
            perror("Error reading command");
            free(commandValue);
            return -1;
        }

        // check if the last character is newline
        if(commandValue[strlen(commandValue) - 1] == '\n'){
            commandValue[strlen(commandValue) - 1] = '\0';
        }

        // check if command entered by user is quit
        if(strcmp(commandValue, "quit") == 0){
            printf("Exiting the program... Bye! \n");
            free(commandValue);
            break;
        }
        
        // execute the command
        ofp = popen(commandValue, "r");
        
        if (ofp == NULL) {
            perror("Error executing command");
            free(commandValue);
            continue; // Prompt user to enter another command
        }
        
        // display commands
        // printf("Output\n");
        char outputbuffer[MAXCOMMANDLENGTH];
        while(fgets(outputbuffer, sizeof(outputbuffer), ofp) != NULL){
            printf("%s", outputbuffer);
        }
        
        //closing the file pointer
        if(pclose(ofp) == -1){
            perror("Error closing the file pointer");
            free(commandValue);
            return -1;
        }

        free(commandValue);
    }

    return 0;
}
