# Compilation Instructions

If you're using a C file

gcc -o assignment Lab3.c     # This will compile the filename and return an executable with the executable name

./assignment                 # This will compile Lab3.c and output an executable called assignment

# My Files
## Lab3.c
We define a macro for the maximum size of a string called MAX_STRING_SIZE and give it a value of 4096

### main()
  1. We take the number of elements (n) input for the main array of strings.
  2. We then pass n to a function readStrings to take individual string input.
  3. We store the input in a char** input_arr
  4. Once the input is obtained, we call insertionSort() function and pass input_arr and the size of the array i.e, n
  5. Then we free the input_arr.
     
### readStrings(int n)
  1.  We declare a double pointer variable array and a single pointer variable called element. array represents our complete array of strings and element is the value that a single array position will contain.
  2. We run the loop for the main array "array" from 0 to n-1.
  3. For each iteration of i from 0 to n-1, we allocate space using malloc to take string input from the user and call it "element". So, the pointer "element" points to the user input string. Maximum space allocated to the element pointer will be MAX_STRING_SIZE * size of each character.
  4. We then use malloc to allocate space for each array position array[i].
  5. Then we add the "element" that was taken from the user and add it to the array i.e at array[i] 
  6. After all the iterations are over, we return the main array "array" back to the main function.


     
### insertionSort(char ** inputarr, int n)
  1. We declare 2 single pointers temp and element.
  2. We run the loop from 1 to n-1 and in each iteration we consider inputarr[i] as the element to be sorted.
  3. The second loop of j runs from i-1 to 0, and for each j iteration we check if the first character of inputarr[j] is alphabetically greater than the element using strcmp  (strcmp returns a value greater than zero is returned when the first not-matching character in first string has a greater ASCII value than the corresponding character in second string).
  4. If strcmp returns a value greater than 0, it means inputarr[j] is greater and we swap inputarr[j] and element values.
  5. This process is done for each value of j.
  6. After each element (inputarr[i]) is sorted, we call output_arr(inputarr, n) function to print the sorted array.
     

### output_arr(char ** inputarr, int n)
  1. We print the final sorted array in this function.
     

# Output screenshots

![output1](https://github.com/SuvarnaSN/CS332-532/assets/156342036/4845b6f2-9d61-4439-aace-3592225a7748)
![output2](https://github.com/SuvarnaSN/CS332-532/assets/156342036/64faa8ad-19ad-408b-883f-e8c3dfe1df4f)


# Github link
https://github.com/SuvarnaSN/CS332-532/blob/main/Lab3/Lab3.c


# References
https://www.geeksforgeeks.org/strcmp-in-c/

https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/

https://www.geeksforgeeks.org/c-pointer-to-pointer-double-pointer/

