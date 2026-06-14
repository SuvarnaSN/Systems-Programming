Compilation Instructions
---------------------------
If you're using a C file

gcc -o assignment ./Lab5.c      # This will compile the filename and return an executable with the executable name

./assignment                    # This will compile Lab5.c and output an executable called assignment


My Files
-----------

Lab5.c

### main()
1. We check if the argv command has a single argument.
2. If yes, we call the function printCurrentDirectory and pass the current working directory and the depth. Depth is 0 for the current working directory and the depth increases as we traverse inside the directory and go to inner directories.

### printCurrentDirectory(char* Directory, int depth)
1. We open the directory using opendir function.
2. If directory is not found, we print Error.
3. The readptr points to each file we traverse in the while loop.
4. We traverse inside the directory until the pointer becomes NULL and no more files or directories are left to be printed.
5. Then we use lstat function to retrieve information about the file or directory.
6. Inside the while loop, we create an array called PathForInnerDir[1024] and we form the path of each file using snprintf by appending the directory link and the filename and separating them by a /.
7. For each element that we encounter using readptr we check if the element is a directory or a file.

**** directory ****
8. If the element is a directory, we check if its parent or the root directory and we ignore them.
9. We traverse further if we encounter either of those two and for the second iteration if we find a directory that is not the parent or the root, then we print the directory by adding 4spaces to the left of it.
10. After printing, we go inside the directory using chdir().
11. We then call the function printCurrentDirectory again using the new path that was formed for the inner directory encountered earlier.

**** file ****
12. If the element is a regular file, we add the appropriate indentation by adding 4 spaces to the left and we print the filename.
13. After the while loop condition becomes false, we go back to the root and check if there are any other files left in the parent directory and print them.


14. Here in this code we are following depth first search algorithm.
15. We traverse through inner directories and print the files in it and then go to its parent and print the remaining files in the parent.




Output screenshots
-------------------
![1](https://github.com/SuvarnaSN/CS332-532/assets/156342036/45b39261-b12a-4a03-b6a2-293b0f8540ba)


Github link
----------------

https://github.com/SuvarnaSN/CS332-532/tree/main/Lab5



