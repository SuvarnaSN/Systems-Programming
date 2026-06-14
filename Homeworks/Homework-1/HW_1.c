#include <stdio.h>
#include <stdbool.h>
#include <math.h>

union output_array{
    float f;
    int i;
};


int isnumPrime(int num){

    int i = 2, flag = 1;
    
   
    while(i< num){
        
        if(num % i == 0){
           
            flag = 0;
            break;


        }
        i++;
    } 
    return flag;
}

int isNumPowerOf2(int num)
{
    int temp, count=0;
    if(num>0)
    {
        while(num != 1)
        {
            
            if(num % 2 == 0)
            {
                num = num/2;
                
            }
            else{
                // not a power of 2
                return 1;
            }
            
        }
        // power of 2
        return 0;
    }
    else{
        // printf("\nnegative no");
        return 1;
    }
}



int findnearestPrime(int num){
    int i;
    for(i=num; i>0; i--){
        if(isnumPrime(i)){
            return i;
        }
    }
}

int divisibleBy3(int num){
    // 0 indicates divisible by 3 - True
    int digit, sum = 0;
    
    while(num != 0){
        digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }
   
    if(sum % 3 == 0){
        return 0;
    }
    else{
        return 1;
    }
}

int divisibleBy3and5(int num){
    if(num%3 == 0 && num%5 == 0){
        return 0;
    }
    else{
        return 1;
    }
}

int squareOfSumOfDigits(int num){
    int digit, sum = 0, sumSquare;
    
    while(num != 0){
        digit = num % 10;
        sum = sum + digit;
        num = num / 10;
    }
    
    sumSquare = sum * sum;
    return sumSquare;
}

char * numberTransformer(int num){
    
   
    static char str[20];
    int sum = 0;
    printf("Number Transformer ");
    if(isnumPrime(num) && (num != 3 && num !=5))
    {
        return "Go Blazers";
    }  
    else if(isNumPowerOf2(num) == 0){
        // n + nearest prime less than n
        
        int nearestPrimeNumber = findnearestPrime(num);
          
        sum =  nearestPrimeNumber + num;
        sprintf(str, "%d", sum);
        
        return str;
    }
    else if(divisibleBy3and5(num) == 0){
        return "UAB CS 332&532";
    }
    else if(divisibleBy3(num) == 0){
        return "CS";
    }
    else{  

        sprintf(str, "%d", squareOfSumOfDigits(num));        
        return str; 
    }
    
    
}

char* UABNumber(){

    // 0 = True , 1 = False
    int n2, divisorSum = 0, arr[50];
    static char str[20];
    printf("\n 2. UABNumber ");
    printf("\nEnter an integer = ");
    scanf("%d",&n2);
    for(int i=1; i<n2; i++){
        if(n2%i==0){
            
            divisorSum += i;
        }
    }
    
    if(divisorSum == n2){
        return "True";
    }
    else{
        return "False";
    }  

}

int reverseNum(int n3){
    int rem = 0, reversednumber = 0; 
    while(n3!=0){
        rem = n3 % 10;
        reversednumber = reversednumber * 10 + rem;
        n3 /= 10;
    }
    return reversednumber;
}

int smallerThanIndex(int inputarr[5]){
    int i,  count = 0;
    for(i=0;i<5;i++){
        if(inputarr[i] < i){
            count = count+1;
        }
    }
    return count;
}

void arrayDetails(int ip_arr[6]){
    
    int i, min_value, min_index, max_value, max_index, size;
    float sum = 0, mean, rounded_mean;
    union output_array output_arr[6];     

    // 1. min value
    min_value = ip_arr[0];    
    for(i=0; i<6; i++){
        if(ip_arr[i] < min_value){
            min_value = ip_arr[i];
        }
    }
    output_arr[0].i = min_value;

    // 2. min_index
    i=0;
    while(i<6){ 
        
        if(ip_arr[i] == min_value){
            min_index = i;
            break;
        }
        else{
            i++;
        }
    }
    output_arr[1].i = min_index;

    // 3. mean
    sum = 0;
    for(i=0; i<6;i++){
        sum = sum + ip_arr[i];
    }
    mean = (float)sum/6;
    output_arr[2].f = mean;

    // 4. max value
    max_value = ip_arr[0];    
    for(i=0; i<6; i++){
        if(ip_arr[i] > max_value){
            max_value = ip_arr[i];
        }
    }
    output_arr[3].i = max_value;
    
    // 5. max_index
    i=0;
    while(i<6){
        if(ip_arr[i] == max_value){
            max_index = i;
            break;
        }
        else{
            i++;
        }
    }
    
    output_arr[4].i = max_index;

    printf("\n");
    printf("%d,", output_arr[0].i);
    printf("%d,", output_arr[1].i);
    printf("%.2f,", output_arr[2].f);
    printf("%d,", output_arr[3].i);
    printf("%d", output_arr[4].i);

}


int main(){

    int n, n3, arr[5], i, it;
    int arr2[6];
    printf("Enter a positive integer for numberTransformer = ");
    scanf("%d", &n);
    
    // 1.
    char* value = numberTransformer(n);
    printf("\n%s", value);

    // 2.
    char* boolValue = UABNumber();    
    if(boolValue == "True"){
        printf("\nTrue");
    }
    else{
        printf("\nFalse");
    }
    
    // 3.
    printf("\n3. reverseNum "); 
    printf("\nEnter n3 = ");
    scanf("%d", &n3);    
    printf("%d", reverseNum(n3));


    // 4.
    printf("\n4. smallerThanIndex "); 
    printf("\nEnter 5 array integers = ");
    for(i=0; i<5; i++){
        scanf("%d", &arr[i]);
    }
    int Count = smallerThanIndex(arr);
    printf("\n%d", Count);
    

    // 5.
    printf("\n5. arrayDetails "); 
    printf("\nEnter 6 array integers = ");
    for(it=0; it<6; it++){
        scanf("%d", &arr2[it]);
    }
    arrayDetails(arr2);
    return 0;
}