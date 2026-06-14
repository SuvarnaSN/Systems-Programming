# Compilation Instructions


If you're using a C file

gcc -o assignment insertionsort.c # This will compile the filename and return an executable with the executable name

./assignment # this will compile Lab2.c and output an executable called assignment


# My Files
## insertionsort.c

### main()
1. The code prompts the user to enter 10 elements and stores it in an array inputarr[].
2. After the user enters 10 elements the code sorts the array in an ascending order using the following steps.
   1. We loop through the array using the iterator i from index 1 to n.
   2. We consider the each array item as "element". Insert the inputarr[i] in element variable.
   3. Then we use j iterator loop to run for each element before i from i-1 to 0.(Here we are trying to insert inputarr[i] into its correct position by comparing inputarr[i] with each element before i. So j runs from i-1 to 0 for every i.
   4. In every j iteration we check if the inputarr[j] is greater than the element and if yes we swap inputarr[j+1] and inputarr[j]
   5. We then print the sorted array.

# Output screenshots
![output1](https://github.com/SuvarnaSN/CS332-532/assets/156342036/7631c458-0205-47d1-8c07-cb43a5c74b77)



# Github link
https://github.com/SuvarnaSN/CS332-532/tree/main/Lab2


