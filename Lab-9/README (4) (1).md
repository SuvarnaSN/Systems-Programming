Compilation Instructions
If you're using a C file

gcc -o lab9 ./Lab9.c # This will compile the filename and return an executable with the executable name ./lab9 # This will compile Lab9.c and output an executable called lab9
./lab9 ./hw1 10000   # this command to run the file.

My Files
Lab9.c

main()
We check for the number of arguments passed in the terminal if they are more than 2. Here we expect the user to pass the command as ./lab9 ./hw1 10000 hence number of argments more than 2. 

Next we use signal function to call the function signalhandler() for CTRL C, CTRL Z and CTRL \. 
We create the child process using fork() method.
If the pid value is 0, we perform execvp function.
If pid > 0, we use waitpid to make the parent process wait until the child process.

signalhandler()
This function takes signal as input and if CTRL + \ was received signal becomes SIGQUIT and the parent process is terminated and exit the program.
If not then we check if the signal recieved as input is CTRL + Z . If yes then signal value becomes SIGTSTP and the child process is suspended and control returned back to the main.
For CTRL + C , we check if pid is greater than 0 and if yes we kill the child process. 

Output Screenshots

![output](https://github.com/SuvarnaSN/CS332-532/assets/156342036/86772ba1-f548-4c04-ae9e-9ff054be0935)

Github link
https://github.com/SuvarnaSN/CS332-532/tree/main/Lab9
