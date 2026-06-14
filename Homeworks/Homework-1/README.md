# Compilation Instructions


If you're using a C file

gcc -o hw HW_1.c # This will compile the filename and return an executable with the executable name

./hw # this will run HW_1.c and output an executable called assignment


# My Files
## HW_1.c

## Functions
### main()
    1. The main function is written to take a positive integer as input and it is passed to numberTransformer() function.
    2. This function calls the UABNumber() function and awaits a boolean 0 or 1 from UABNumber(). After which the main() prints True if the UABNumber function returns the string True else prints False.
    3. The main function takes a number as input from the user and stores it in n3 variable. It then passes n3 as a parameter to reverseNum()
    4. The main function takes 5 array integers as input and passes the array to the function smallerThanIndex() which then accepts the count of integers in the array whose value is smaller than index and prints the total count.
    5. The main function accepts 6 integers from the user as input and stores it in an array. It then passes this array to the arrayDetails() function.

### numberTransformer()
    1. This function accepts n value as a parameter and returns a string to the main function.
    2. This function prints "numberTransformer".
    3. This function calls another function called isnumPrime. If the isnumPrime() function returns 1, then it returns "Go Blazers" string to main().
    4. If false, then the numberTransformer function calls isNumPowerOf2() function. 
        If the isNumPowerOf2() returns 0, then it calls another function called findnearestPrime() and passes the num value (input value). The output of findnearestPrime() function is added to num and the final sum is returned to main() as a string using sprintf function.
    5. If the isNumPowerOf2() returns 1, the next function divisibleBy3and5() is called. 
       If divisibleBy3and5() returns 0, then the numberTransformer() function returns the value "UAB CS 332&532".
    6. If the divisibleBy3and5() function returns 1, then the numberTransformer() function calls the function divisibleBy3(). If the divisibleBy3() function returns 0 then the numberTransformer() returns the string "CS" to main.

    ### isnumPrime()
        1. This function takes n as input from numberTransformer() function and initalises flag value to 1 and iterator i value to 2. The flag value 1 indicates that n is prime and flag value 0 indicates not prime. 
        2. For each value of i from 2 to num-1, this function checks if there is any i that is divisible by num. If yes, then flag is made 0 and we break out of the loop because the number n is no longer prime.
        3. If we do not find any value that is divisible by num in the range of 2 to num-1, then the flag remains 1 and the number is determined as prime.
        4. flag value is now retured to numberTransformer() function.

        Example 1:  num = 3, i=2 , flag =1
                Iteration 1 : num = 3 ; 2<3 Yes => 3%2 != 0 => i=3 
                Iteration 2 : num = 3 ; 3<3 NO  => flag = 1 =>  returns 1 
                Since num = 3 which is prime, we determine that 3 is prime and return 1.

    ### isNumPowerOf2()
        1. This function accepts num from numberTransformer() function and returns 0 if the number is a power of 2. Otherwise it returns 1.
        2. If num > 0, we have a while loop that keeps a track of the quotient and runs until the quotient is not equal to 1. Inside the while loop, we check if the remainder of num/2 is 0. If yes then the quotient becomes the new num. If at any point, the remainder is non-zero, we return 1.Else we return 0.
        

        Example 1:  num = 6, count = 0
                    Iteration 1 : num = 6 ; 6!=1 => 6%2 = 0 => num = 3 
                    Iteration 2 : num = 3 ; 3!=1 => 3%2 != 0 => else part returns 1 
                    Since num = 6 which is odd, we determine that 6 is not a power of 2 and return 1.

        Example 2:  num = 8 , count = 0
                    Iteration 1 : num = 8 ; 8!=1 => 8%2 = 0 ; num = 8/2 = 4
                    Iteration 2 : num = 4 ; 4!=1 => 4%2 = 0 ; num = 4/2 = 2
                    Iteration 3 : num = 2 ; 2!=1 => 2%2 = 0 ; num = 2/2 = 1
                    Since num = 1 we determine that 8 is a power of 2 and return 0.

    ### findnearestPrime()
        1. For each value of i from num to 1, we call the function isnumPrime and pass i as a parameter to check if i is prime.
        2. The first i that determines to be primenumber is returned back to numberTransformer() function as integer.

    ### divisibleBy3and5()
        1. This function takes num as input from numberTransformer() and checks if num is divisible by 3 and 5. 
            If the remainder of num/3 and num/5 is 0, then we return 0
            Else , we return 1 

    ### divisibleBy3()
        1. This function takes num as input from numberTransformer() and checks if sum of digits of num is divisible by 3
        2. We first initialise the sum to zero. Then we pull out each digit from num by doing num % 10.
        3. We now add the digit to sum and compute the new sum.
        4. The new num becomes the quotient of num/10.
        5. We continue this process until num!=0.

### UABNumber()   
    1. We take an integer n2 as input and initialise divisorSum = 0
    2. We loop from i =1 to i = n2-1, and check if n2%i = 0. If yes, we add i to the divisorSum
    3. If the divisorSum = n2 (input number) then we return True else return False.

### reverseNum()
    1. We take an integer n3 as input from main(), initialise rem = 0, reversednumber = 0
    2. We then run the loop until n3!=0, pull out each digit from the right by doing n3%10.
    3. Then we find reversedNumber by the formula reversednumber * 10 + rem. 
    4. n3 becomes the quotient of n3/10 in each iteration that is the remaining number leaving the digit that was pulled out;
    5. The reversednumber is then returned back to main()

### smallerThanIndex()
    1. This function takes an array of 5 numbers as input (inputarr[5]) and initialises count value to 0.
    2. We then loop through the array and check for each i if the inputarr[i] is less than i. If this condition becomes true, we increment the count.i here indicates the index of the array and inputarr[i] is the value inside that array index. Count returns the total count where the actual number inside that array position is less than the index of that position.
    3. Count value is returned to main()

### arrayDetails()
    1. This function takes in an array of 6 integers as input. It initialises sum = 0 and uses a union array called output_array.
    2. We find the minimum_value, minimum_index, mean, maximum_value, maximum_index and we add it to this union array.
    3. Then the array is returned to main().

### squareOfSumOfDigits()
    1. This function takes in an num as input. It initialises sum = 0 and returns an int called sumSquare.
    2. We loop until num!=0 and pull out each digit from the right. We then add the digit to sum. The new num becomes the remaining number towards the left
    leaving the digit that was pulled out.
    3. We then multiply sum * sum .
    4. Using sprintf function we return the Square of sum as a string to main()
    5. We then return the string output.

# Output screenshots
![Alt text](output_1.jpg)
![Alt text](output_2.png)
![Alt text](output_3.png)
![Alt text](output_4.png)

# Github link
https://github.com/SuvarnaSN/CS332-532/tree/main/Homework

# References
https://www.tutorialspoint.com/cprogramming/c_type_casting.htm
https://www.playerzero.ai/lib/how-can-i-convert-an-int-to-a-string-in-c
https://www.quora.com/How-do-I-convert-int-to-string-C
https://www.programiz.com/c-programming/examples/reverse-number
https://www.tutorialspoint.com/cprogramming/c_type_casting.htm
https://www.playerzero.ai/lib/how-can-i-convert-an-int-to-a-string-in-c
https://www.quora.com/How-do-I-convert-int-to-string-C
https://www.programiz.com/c-programming/examples/reverse-number
https://www.geeksforgeeks.org/c-program-to-find-whether-a-no-is-power-of-two/
https://www.geeksforgeeks.org/sprintf-in-c/






