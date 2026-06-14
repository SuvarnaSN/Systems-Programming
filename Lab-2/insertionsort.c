#include<stdio.h>
int main(int argc, char** argv){

    // Prompt the user to enter 10 array elements
    int inputarr[10], i, temp=0, element, j, n=10;
    printf("Enter 10 elements: ");
    for(i=0;i<n;i++){
        scanf("%d", &inputarr[i]);
    }
    
    // sorting the array in ascending order
    for(i=1; i<=n-1;i++){
        
        element = inputarr[i];
        for(j=i-1; j>=0; j--){
            if(inputarr[j] > element){
                // printf("\ninputarr[j] = %d and element = %d", inputarr[j], element);
                temp = inputarr[j+1];
                inputarr[j+1] = inputarr[j];
                inputarr[j] = temp;
                
            }
        }
        
    }
    printf("\nSorted array after insertion sort is = ");
    // print the array
    for(i=0; i<n; i++){
        printf("%d ", inputarr[i]);
    }
    return 0;
}