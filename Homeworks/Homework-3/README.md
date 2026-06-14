ompilation instructions
gcc -o homework3 HW_3.c ->This complies the file and saves as executable

./homework3 ->displays the contents of directory which we are present working in

./homework3 -L 1024 ->Displays the files in the directory with size greater than or equal to 1024 bytes

./homework3 -L 1024 ../HW_2 ->Displays the files in the directory "HW_2" with size greater than or equal to 1024 bytes

./homework3 -s jpg 1 ->Displays the files who has the substring of "jpg" in it.

./homework3 -s jpg 1 -L 1024 ->displays the files with size more than 1024 bytes and has substring "jpg" in it

./homework3 -L 1024 -e "ls -l" -> lists all files with size >= 1024 bytes in the current directory, and execute the command "ls -l" on each file (ignore directories)

$./homework3 -L 1024 -s jpg 3 -e "wc -l" -> lists all files that have the substring “jpg” in their filename with depth <=3 relative to the current directory and size >= 1024, and execute the command "wc -l" on each file (ignore directories)

#HW_3.c

Description
This program recursively lists the contents of a directory, with options to specify the maximum depth, filter by file size, and search for files by name pattern. It also provides the ability to display detailed information for each file, including size, permissions

Functions
Description
This program recursively lists the contents of a directory , with options to specify the maximum depth, filter by file size, and search for files by name pattern. It also provides the ability to display detailed information for each file ,including size, permissions.

##Functions

main()
->entry point of the program. ->Parses command line arguments to determine options for directory listing. ->Calls the “list_directory” function to start the directory traversal.

switchcase for all options and i used optarg function pointers.

for each case we call respective functions funcForv(), funcForL, funcFors(), funcFort().

->recursively lists the contents of a directory. ->parameters are Path->the path of the directory to list Depth->current depth level in the directory hierarchy. Max_depth->maximum depth level to traverse


funcForE()

funcFore()


Output Screenshots

![L,s,-e](https://github.com/SuvarnaSN/CS332-532/assets/156342036/950e8eb7-62c9-46db-ae71-d664cd3711cf)

![L,e](https://github.com/SuvarnaSN/CS332-532/assets/156342036/db999764-ffb6-4822-9f33-ebb5fedb5bc2)

Github 
https://github.com/SuvarnaSN/CS332-532/edit/main/Homework-3
