Compilation Instructions
---------------------------------------
If you're using a C file

gcc -o lab12 Lab12.c       # This will compile the filename and return an executable with the executable name ./lab12 # This will compile Lab12.c and output an executable called lab12

./lab12

Enter command: ls *.c

Lab12.c
pager.c
pager2.c
pipe0.c
pipe1.c
pipe2.c

Enter command: ls -l pipe[1-3].c

-rw-r--r-- 1 root root 2073 Apr  2 17:30 pipe1.c
-rw-r--r-- 1 root root 2747 Apr  2 21:03 pipe2.c

Enter command: ls pipe*.c | sort

pipe0.c
pipe1.c
pipe2.c

Enter command: ls pipe?.c | sort > files.out

Enter command: cat files.out

pipe0.c
pipe1.c
pipe2.c

Enter command: quit

Exiting the program... Bye! 

My Files
------------------------------------------------------------
lab12.c
------
We defined global variables called MAXCOMMANDLENGTH whose value is initialised to 1000.

main()
In main() function we do the following tasks.
1. We declared pid_t type variables for processes pid1 and pid2, a filepointer ofp, and integer variables status and an array to store the pipe called pipefd[2].
2. We run an infinite loop and we keep asking the user to enter a command until the user enters "quit". If the user enters "quit" as the command we break out of the loop.
3. If not, we create the dynamic array to store the commands entered by the user, store it in commandValue char* variable and check if it is NULL. If any command is NULL we print out the error message and stop.
4. If the user enters a proper command, we replace \n with \0, because every command entered is a string and it will end with \n.
5. We then use the popen function, to execute the command entered by the user. The output of popen is stored in the pointer ofp.
6. We then fetch values from ofp and put it in output buffer and print the output back to the user.
7. We check if the ofp value becomes -1. If yes, we free the commandValue string and return -1.


Output Screenshots


![Lab-12 output](https://github.com/SuvarnaSN/CS332-532/assets/156342036/ef8518c4-2258-43cb-9de1-4d89ba71be95)


Github link 
https://github.com/SuvarnaSN/CS332-532/edit/main/Lab-12
