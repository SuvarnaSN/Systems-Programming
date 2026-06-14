#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFSIZE 1000
int main(int argc, char *argv[])
{
    int file1WriteDescriptor, file2ReadDescriptor;
    ssize_t data;
    
    char buffer[BUFSIZE];
    if(strcmp(argv[1] , argv[2]) == 0){
        printf("Error both source and destination files are the same");
        exit(-1);
    }
    
    // copy contents of file 2 in file 1

    // 1. opening file 1
    file2ReadDescriptor = open(argv[2], O_RDONLY);

    // checking if there is an error while opening file 2 for reading 
    if(file2ReadDescriptor == -1){
        printf("Error occured while opening file 2");
        exit(-1);
    }
    // opening file 1 for writing
    file1WriteDescriptor = open(argv[1], O_CREAT|O_WRONLY|O_APPEND , 0700);
    
    while(( data = read(file2ReadDescriptor, buffer, BUFSIZE) ) > 0)
    {
        // printf("%d", data);
        
        if(write(file1WriteDescriptor, buffer, data) != data){
            printf("Write error");
        }
    }
     

    close(file2ReadDescriptor);
    close(file1WriteDescriptor);

    
    return 0;
}