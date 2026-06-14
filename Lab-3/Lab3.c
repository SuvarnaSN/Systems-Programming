#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STRING_SIZE 4096
char** readStrings(int n){
    char** array;
    char* element;
    int i, j;
    
    array = (char**) malloc(n * sizeof(char *));  // whole array

    for(i=0; i<n; i++){ 
        element = (char*) malloc(sizeof(char) * (MAX_STRING_SIZE));  // to take string input
        printf("Enter string %d =", i);
        scanf("%s", element);  
        array[i] = (char*) malloc(strlen(element) * sizeof(char));  // space for the element within the array. Use strlen for char[] or char** variable and not sizeof
        strcpy(array[i], element);         
        
        
    }
    
    return array;
}


void output_arr(char ** inputarr, int n){
    printf("\nOutput = ");
    for(int j=0;j<n; j++)
        printf("%s ", inputarr[j]);
}

void insertionSort(char ** inputarr, int n){

    char* temp;
    char* element;
    for(int i=1; i<=n-1 ; i++){
        element = inputarr[i];
        int j = i-1;
        while(j>=0){   // j = 0, i=1

            if(strcmp(inputarr[j], element) > 0){  // first string's character has greater ascii value then swap
                
                temp = inputarr[j+1];
                inputarr[j+1] = inputarr[j];
                inputarr[j] = temp;
            }
            j--;
        }
       
    }
    output_arr(inputarr, n);

}

int main(int argc, char** argv){

    // Prompt the user to enter 10 array elements
    int  i, temp=0, element, j, n;
    
    printf("Enter number of elements of the array: ");
    scanf("%d",&n);
    
    char** input_arr = readStrings(n);
    
    insertionSort(input_arr, n);
    
    free(input_arr);
    return 0;
}