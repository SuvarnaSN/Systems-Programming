#include<stdio.h>
int main(int argc, char** argv)
{
    int given_number;
    printf("Enter given_number value = ");
    scanf("%d", &given_number);
    if(given_number % 2 == 0){
        printf("The number is an even number\n");
    }
    else{
        printf("The number is an odd number\n");
    }
    return 0;
}
