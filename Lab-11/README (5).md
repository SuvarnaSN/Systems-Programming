Compilation Instructions
-------------------------------
If you're using a C file

gcc -o assignment ./pthread_sum.c # This will compile the filename and return an executable with the executable name ./assignment # This will compile pthread_sum.c and output an executable called assignment

./assignment 1000 4

My Files
-------------------------------------------------------------------------------------------------------

pthread_sum.c
--------------------------------------------------------------------------------------------------------------------------------------------

We defined global variables like MAX_THREADS value initialised is 100 and pthread_mutex_t variable mutex and its value is PTHREAD_MUTEX_INITIALIZER.

We then initialized a structure named ThreadVariables and within that structure, we declared variables like pointer a and sum which are double, N, and sum variables of type int and long int variable "tid".


void *compute()
-------------------------------------------------------------------------------------------------------
1. We declared a pointer variable called threadVar of type ThreadVariables.
2. We declared variables myStart, myEnd, myN, i, tid of type long and pointer a of type double.
3. myStart and myEnd variables point to the starting and ending values of the thread chunk.
4. myN represents the total values present in that chunk. Eg 1000/4 = 250
5. We calculate the partial sums of the chunks in this function for each thread and lock the mutex before adding it to the sum so that the sum variable is no overwirtten or accessed by 2 threads at the same time.
6. After adding the sum we unlock the mutex.
7. We then return NULL.

   
main()
--------------------------------------------------------------------------------------------------------
1. We first check if argc variable is not 3. If yes, we tell the user that the final element for calculating sum and the number of threads values are missing in the input.
2. We then take N and size from the input command from the terminal. Eg in case of input command ./assignment 1000 4 , N = 1000 and size = 4
3. We declare a variable called threadVariables of the structure type i.e of ThreadVariables type.
4. Then we declare a dynamic array a of type double.
5. We check if a is NULL. If it is NULL then we print that the memory is not allocated and we exit the program.
6. Else we keep adding numbers from 1 to the number N that we got from the user.
7. We calculate N % size and store it as rem and we calculate eachThreadSize by dividing N by size.
8. We then run a loop from 0 to size-1 times that is for size no of threads (4 in our case) we initialise the threadVariables and create a thread by passing threadVariables to compute function and the chunk of thread values between 1 to 1000.
9. After the partial sum is calculated for the all the threads, we join threads.
10. We then declare total_sum as 0 and then we add the threadVariable sum to the total sum and print the value.


Output Screenshots
----------------------------------------------------------------------------------------------------------
![output-1](https://github.com/SuvarnaSN/CS332-532/assets/156342036/3ed368aa-2632-4064-a287-5089cb1aaaa4)


Github link
https://github.com/SuvarnaSN/CS332-532/edit/main/Lab-11


