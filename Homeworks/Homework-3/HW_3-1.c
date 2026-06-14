// printCurrentDirectory https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/
// https://www.quora.com/How-do-I-print-type-of-variable-in-c
// https://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
// https://man7.org/linux/man-pages/man3/opendir.3.html
// https://cboard.cprogramming.com/c-programming/72671-displaying-file-permissions.html
// https://www.geeksforgeeks.org/function-pointer-in-c/
// https://kb.iu.edu/d/abbe
// https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm



# include <stdio.h>
# include <string.h>
# include <dirent.h>
# include <unistd.h> 
# include <sys/stat.h>
# include <sys/types.h>
# include <libgen.h>
# include <stdlib.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include<sys/wait.h>
# include <stdbool.h>
# define MAX_ARGS 10
# define MAX_NOOFFILES 1000


bool isL = false;
bool isV = false;
bool isS = false;
bool isT = false;
bool is_e = false;
bool is_E = false;

char *substring = NULL;
char *cmdtoken;
char *unixCommand;
char tarCommandForE[1024];
char *tarFilename = NULL;
char  cwd[1024];
char *file_list[MAX_NOOFFILES];


typedef void (*functptr)(char *, struct stat *, int);
char* fileType = NULL;
functptr fp = NULL;

int size = 0;
int depth = 0, arr_index = 0;
int file_count = 0;
int *file_count_pter = &file_count;
int fileCount = 0;

void funcFore(char *filePath){

    int i=0, status;

    // unixcmd = "ls -l"
    pid_t pid = fork();
    if(pid == 0){
       

        // Tokenize user input
        char *commandArgs[1024];                // Assuming a maximum of 10 arguments
        char *token = strtok(unixCommand, " ");
        int i = 0;

        while (token != NULL && i < 9) {

            commandArgs[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        commandArgs[i++] = filePath;
        commandArgs[i] = NULL;

        execvp(commandArgs[0], commandArgs);

    }
    else if(pid > 0){
        wait(&status);
    }
    else{
        perror("Fork failed");
        exit(-1);
    }
}

void funcForE(char *filePath){


    // if tar_command contains the string "tar cvf jpg.tar file1.jpg file2.jpg", then system(tar_command) will execute the 
    // tar command with the specified options (cvf stands for create, verbose, and file respectively), creating a tar archive named jpg.tar containing file1.jpg and file2.jpg.
    
    char tarCommandForE_copy[1024];
    pid_t pid = fork();


    printf("Entered funcForE");
    snprintf(tarCommandForE_copy, sizeof(tarCommandForE_copy), "tar cvf %s", tarFilename);


    for(int i=0; i < file_count; i++){
        strcat(tarCommandForE_copy, " ");
        strcat(tarCommandForE_copy, file_list[i]);
        // printf("filelist[i] = %s", file_list[i]);
    }
   
    if(pid == 0){
       

        // Tokenize user input
        char *commandArgs[1024];                // Assuming a maximum of 10 arguments
        char *token = strtok(unixCommand, " ");
        int i = 0;

        while (token != NULL && i < 9) {

            commandArgs[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        commandArgs[i++] = filePath;
        commandArgs[i] = NULL;

        execvp(commandArgs[0], commandArgs);

    }
    else if(pid > 0){
        wait(&status);
    }
    else{
        perror("Fork failed");
        exit(-1);
    }
    
    if(output != 0){
        printf("Error");
    }

   
}


// void funcForE(char *filePath) {
//     char tarCommandForE[1024]; // Adjust the buffer size accordingly
//     printf("Entered funcForE\n");
    
//     // Check if tarFilename is correctly set
//     char tarFilename[] = "archive.tar"; // Example filename, replace with your filename
    
//     snprintf(tarCommandForE, sizeof(tarCommandForE), "tar cvf %s", tarFilename);

//     for(int i = 0; i < file_count; i++) {
//         strcat(tarCommandForE, " ");
//         strcat(tarCommandForE, file_list[i]);
//         printf("Added file %s to tar command\n", file_list[i]); // Debugging
//     }

//     printf("Executing command: %s\n", tarCommandForE); // Debugging
//     int result = system(tarCommandForE);

//     if (result != 0) {
//         printf("Error: Failed to create the tar\n");
//     }
// }



void displayFileDetails(char *filePath, struct stat *element, int depth){

   
    // printf("displayfile details entered");
    // if L and if the file size is greater than or equal to the specified size
    if (isL && (element->st_size >= size)) {
       
        if((isS && (strstr(basename(filePath), substring))) && ((is_e == true) && (unixCommand != NULL))) // L,s and -e
        {
            funcFore(filePath);
        }

        else if((isS && (strstr(basename(filePath), substring))) && ((is_E == true) && (unixCommand != NULL))) // L,s and -E
        {
            printf("E entered");
            funcForE(filePath);
        }

        // Check if the substring is present in the file path
        else if (isS && strstr(basename(filePath), substring) && is_E == false && is_e == false) {  // L and s

            for (int i = 0; i < depth*4; i++) {
                printf(" ");
            }
            printf("%s\n", basename(filePath));             

        } 
        // else if((is_e == true) && (unixCommand != NULL))            // L and e
        // {
        //     funcFore(filePath);
        // }

        // else if((is_E == true) && (unixCommand != NULL))            // L and E
        // {
        //     funcForE(filePath);
        // }


       

        else if (isS == false && isL == true) {   // only L

            
            for (int i = 0; i < depth*4; i++) {
                printf(" ");
            }
            // printf("%s -> %ld\n", basename(filePath), element->st_size);            
            printf("%s\n", basename(filePath));
        }   
    }

    // If -L option is not specified 
    else if (isL == false) {

        // printf("strstr(basename(filePath), substring) = %s \n", strstr(basename(filePath), substring));
        // Check if the substring is present in the file path

        if((isS && strstr(basename(filePath), substring)) && ((is_e == true) && (unixCommand != NULL))) // L,s and -e
        {
            funcFore(filePath);
        }

        else if((isS  && strstr(basename(filePath), substring)) && ((is_E == true) && (unixCommand != NULL))) // s and -E
        {
            printf("E true. substring = %s", substring);
            funcForE(filePath);
        }

        else if ((isS) && (strstr(basename(filePath), substring))) {
            
            for (int i = 0; i < depth * 4; i++) {
                printf(" ");
            }
            printf("%s\n", basename(filePath)); // Print only the last part of the file path

        } 
        
        else if (substring == NULL) {
            for (int i = 0; i < depth * 4; i++) {
                printf(" ");
            }
            printf("%s\n", basename(filePath)); // Print only the last part of the file path
        }
    }

    // If the file size is smaller than the specified size and -L option is specified
    else if(isL == false && isS == false ) {
        // Print the file name with proper indentation
        
        for (int i = 0; i < depth * 4; i++) {
            printf(" ");
        }
        printf("%s\n", basename(filePath)); // Print only the last part of the file path
    }
}



void SymboliclinkHandling(char* PathForInnerDir, char* d_name){

    char targFilePath[1000];
    char filepath[1024];   
    ssize_t size_target;
    struct stat targetData, symblinkData;

    snprintf(filepath, sizeof(filepath), "%s/%s", PathForInnerDir, d_name);
    // printf("1. %s, %s, %s\n", PathForInnerDir, d_name, filepath);

    //check if symbolink present F_OK = existence check
    if(access(filepath, F_OK) == 0){
        
        printf("%s", filepath);
        // read the target 
        size_target = readlink(filepath, targFilePath, sizeof(targFilePath) - 1);
        switch(size_target){
            case -1:
                printf("Error");
                break;
            
            default:
                targFilePath[size_target] = '\0';  // end with null
                printf("%s -> (%s)\n ", d_name, targFilePath);
                break;
        }
    }
}

void printCurrentDirectory(char* Directory, int depth) {

    DIR *directory;
    struct dirent *readptr;
    struct stat element;
    char PathForInnerDir[1024];
    int i;

    directory = opendir(Directory); 
    arr_index = 0;
    if(directory == NULL) {
        printf("Error in opening directory %s\n", Directory);
        return;
    }

    // Print the directory name if depth is 0
    if (depth == 0) {
        printf("%s\n", basename(Directory));
        depth++;
    } 

    // Read contents until it's not NULL
    while ((readptr = readdir(directory)) != NULL) { 
        
        if(strcmp(readptr->d_name, ".") == 0 || strcmp(readptr->d_name, "..") == 0)
            continue;

        snprintf(PathForInnerDir, sizeof(PathForInnerDir), "%s/%s", Directory, readptr->d_name);  
   

        if(lstat(PathForInnerDir, &element) == 0) {

            if(S_ISDIR(element.st_mode)) {

                for (i = 0; i < depth*4; i++) {
                    printf(" ");
                }
                printf("%s \n", readptr->d_name);
            
                printCurrentDirectory(PathForInnerDir, depth + 1); // Recursively call to handle nested directories
                
            } 
            else if(S_ISREG(element.st_mode)){

                fp(PathForInnerDir, &element, depth);

            }

            else if(S_ISLNK(element.st_mode)){ 
                
               
                SymboliclinkHandling(Directory, readptr->d_name);
                continue;

            }
        } 
    }
    closedir(directory);
}


int main(int argc, char *argv[]) 
{

    int cmdOption, i, count=0;
    char currentDirectoryfromPath[1024];
    char buf[100],filePath[1000];    
    char * startDirectory = NULL;
    const char s[2] = " ";

    // The getopt() function is a builtin function in C and is used to parse command line arguments.-v in any Linux command means verbose.
    while((cmdOption = getopt(argc, argv, "vL:s:t:e:E:")) != -1)
    {
        
        switch(cmdOption)
        {
            

            case 'v':  
                    isV = true;                    
                    break;

            case 'L': 
                    isL = true;

                    size = atoi(optarg);                     
                    break;

            case 's': 
                    isS = true;
                    substring = optarg;
                    depth = atoi(argv[optind]);
                    optind++;
                    
                    break;

            case 't': 
                    isT = true;
                    fileType = optarg;
                    break;

            case 'e':
                    is_e = true;
                    unixCommand = optarg; 
                    
                    arr_index = 0;
                    break;
            
            case 'E':
                    is_E = true;
                    
                    strcpy(tarCommandForE, optarg);                 // tar cvf jpg.tar
                    // printf("tarCommandForE = %s\n", tarCommandForE);
                    // strcpy(tarCommandForE_copy, tarCommandForE);

                    // snprintf(tarCommandForE, sizeof(tarCommandForE), "%s", tarCommandForE);
                    
                    // printf("tarCommandForE = %s\n", tarCommandForE);
                    break;

            case ':':  
                printf("Error! value needed for the option\n");  
                break; 

            case '?':  
                printf("Error! unknown option "); 
                break;   
            

        }

        
    }

    if(optind < argc){        
        // incase of ./hw2 ./projects
        
        startDirectory = argv[optind];
        
    }
    else{
        // incase of ./hw2
        startDirectory = getcwd(buf, sizeof(buf)); 
      
    }
   
    
    fp = &displayFileDetails;
   
    // printf("%s", basename(startDirectory));
  
    printCurrentDirectory(startDirectory, 0);
    return 0;
}


