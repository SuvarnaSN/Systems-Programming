Compilation Instructions
---------------------------
If you're using a C file

cat file1

cat file2

gcc -Wall -o assignment lab4.c      # This will compile the filename and return an executable with the executable name

./assignment file1 file2      # This will compile Lab3.c and output an executable called assignment

cat file1

cat file2



My Files
-----------
Lab4.c
We define a macro for the maximum size of a buffer called BUFSIZE and give it a value of 1000

main()
1. We declare two file descriptors of integer type (file1WriteDescriptor, file2ReadDescriptor) for file1 and file2. We aim to append the contents of file2 into file1.
2. We have to check if the arguments passed in the terminal contain the same file as argument 2 and argument 3 .(Example : ./assignment file1 file1) we print an error if this scenario occurs and exit the program.
3. We then open the file2 in read only mode.
4. Next we check if there is an error while opening file 2 for reading and exit if the condition holds true.
5. Next we declare the open file1 in read, append and write mode (file1WriteDescriptor)
6. Then using a while loop we iterate through chunks of data with size being BUFSIZE from file2 and read those chunks from file2.
7. After reading we append the data chunk to file1.
8. Then we close both file1 and file2.

Output screenshots
-------------------
![output-1](https://github.com/SuvarnaSN/CS332-532/assets/156342036/3bc90543-f4af-4ae6-8c29-21bea79b9657)



Github link
----------------

https://github.com/SuvarnaSN/CS332-532/tree/main/Lab4



