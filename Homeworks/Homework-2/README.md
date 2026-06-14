# compilation instructions 
gcc -o homework2 HW_2.c
->This complies the file and saves as executable

./homework2
->displays the contents of directory which we are present working in

./homework2 -v ../HW_2
->Displays the contents of HW_2 with date,time and the size of files 

./homework2 -L 1024
->Displays the files in the directory with size greater than or equal to 1024 bytes

./homework2 -L 1024 ../HW_2
->Displays the files in the directory "HW_2" with size greater than or equal to 1024 bytes

./homework2 -s jpg 1
->Displays the files who has the substring of "jpg" in it.

./homework2 -s jpg 1 -L 1024
->displays the files with size more than 1024 bytes and has substring "jpg" in it

./homework2 -L 1024 -s jpg 1
->displays the files with size more than 1024 bytes and has substring "jpg" in it

./search -v -s jpg 1 -L 1024
->displays the files in the directory HW_2 with size more than 1024 bytes and has substring "jpg" in it

#HW_2.c
## Description
This program recursively lists the contents of a directory, with options to specify the maximum depth, filter by file size, and search for files by name pattern. It also provides the ability to display detailed information for each file, including size, permissions, and last access time.

## Functions

## Description
This program recursively lists the contents of a directory , with options to specify the maximum depth, filter by file size, and search for files by name pattern. It also provides the ability to display detailed information for each file ,including size, permissions ,and last access time.

##Functions
### main()
->entry point of the program.
->Parses command line arguments to determine options for directory listing.
->Calls the “list_directory” function to start the directory traversal.

switchcase for all options and i used optarg function pointers.

for each case we call respective functions 
funcForv(), funcForL, funcFors(), funcFort().

->recursively lists the contents of a directory.
->parameters are 
Path->the path of the directory to list
Depth->current depth level in the directory hierarchy.
Max_depth->maximum depth level to traverse 

### void funcFors(char * fileDirectory, char * substring, int depth)

### void funcForL(char * fileDirectory)

1. We read the LDirectory using readdir and check for not NULL
2. while this is true, using snprintf we form the path of the file.
3. If the file is a regular file, and we check if the size >=1024 bytes and if yes we print name of the file and size.
4. If the file is a directory, we go inside the directory using chdir and use recursion to print inner directories.


### void funcForv(char * fileDirectory)

we open the directory.
read the directory until its not NULL
 using lstat
we check for the stat output if it is -1 then we    print error
if its a regular file, we print filename, size, mode, and time.
if its a directory file, we go inside the directory using chdir and using recursion we print all the files.
We then close the directory.

### void printCurrentDirectory(char* Directory, int depth)

If directory is null, print error
If depth = 0, which means the root, we print the start directory. So we get the basename of the path. and increment the depth to print files and directories.

Using a while loop for each file we check the depth and for depth = 0, we print with 1 tab space.
When we encounter a directory we go inside the directory and print the contents.

We call symbolic link function to check for symbolic links.

we go to the parent directory outside the while loop and close the directory.

### void SymboliclinkHandling(char* PathForInnerDir, char* d_name)

1. We form the path of the file using snprintf.
2. we get the size_target path and put in switch case. 
3. If the size_target is -1 then we print Error.
4. otherwise, we add \0 to targetFilePath at the end and printed symbolicfilename-> targetFilePath"

### void funcFort(char * fileDirectory)

## Output Screenshots
![1_hw2](https://github.com/SuvarnaSN/CS332-532/assets/156342036/c7301cc1-cb23-499e-9792-3db4323ca07b)
![2_-L 1024](https://github.com/SuvarnaSN/CS332-532/assets/156342036/8b673e1a-b3ab-4ccc-be9f-40a3cdc265d2)
![-s ](https://github.com/SuvarnaSN/CS332-532/assets/156342036/031f1db7-d08b-435a-86cc-55bc97988d6a)


---------------------------------------------------------------------------------------------------------

#github link: https://github.com/SuvarnaSN/CS332-532/edit/main/Homework-2/README.md


- 
