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

void printCurrentDirectory(char* Directory, int depth){

    // pointer to read the directory
    DIR *directory;
    struct dirent *readptr;
    struct stat element;
    ssize_t size;
    char buf[100], target_buffer[100];
    int i, flag;
 
    directory = opendir(Directory); 

    // open the directory path
    if(directory == NULL){
        printf("Error in opening directory");
    }

    // depth = 0 for starting directory. 1 for the directory inside 0. 2 for dir inside 1
    if (depth == 0) {
        char *startdirectoryName = basename(getcwd(buf, sizeof(buf)));
        printf("%s\n", startdirectoryName);
        depth = depth +1;
    } 
    

    // read contents until its not NULL
    // printf("Directory = %s", Directory);
    while ((readptr = readdir(directory)) != NULL) {    // readdir is incrementing the pointer 
        
        
        if(lstat(readptr->d_name, &element) == 0)   // retrieve information about the file / dir
        {
            
            char PathForInnerDir[1024];
            
            if(depth != 0 && (strcmp(readptr->d_name, ".") != 0) && strcmp(readptr->d_name, ".."))
                snprintf(PathForInnerDir, sizeof(PathForInnerDir), "%s/%s", Directory, readptr->d_name);         
            
            if(depth == 0){
                snprintf(PathForInnerDir, sizeof(PathForInnerDir), "%s/%s", Directory, readptr->d_name); 
            }
            
            
            if(S_ISDIR(element.st_mode)){

                if(strcmp(".", readptr->d_name) == 0 || strcmp("..", readptr->d_name) == 0)
                    continue;
                
                for (i = 0; i < depth*4; i++) {
                    printf(" ");
                }
                printf("%s\n", readptr->d_name);

                chdir(PathForInnerDir);
               
                printCurrentDirectory(PathForInnerDir, depth+1);
            } 

            else if(S_ISREG(element.st_mode)){

                for (i = 0; i < depth*4; i++) {
                    printf(" ");
                }
                printf("%s\n", readptr->d_name);
                
            }
            
        } 
        
    }
    chdir("..");
    closedir(directory);

}

int main(int argc, char *argv[]) 
{

    int cmdOption, i, count=0;
    char currentDirectoryfromPath[1024];
    char cwd[1024];
    typedef void (*fp)(char *, int);
    int size, depth = 0, vdepth = 0, sdepth = 0, sdir_depth = 0;
    char *substring, *directory = "empty", *vdirectory;

    // option 1
    if(argc == 1){
        
        printCurrentDirectory(getcwd(cwd, sizeof(cwd)), depth);
       
    }

    return 0;
}
