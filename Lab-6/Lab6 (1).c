// https://www.bytellect.com/resources/sorting-in-c-with-the-qsort-function-bytellect001.pdf
// https://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/

# include<stdio.h>
# include<stdlib.h>
# include<string.h>

# define LINESIZE 1024
# define TOTAL_ROWS 22520

struct listing {
    int id,	host_id,  price,	minimum_nights,	number_of_reviews, calculated_host_listings_count, availability_365;
    float latitude, longitude;
    char * host_name, *neighbourhood_group, *neighbourhood, *room_type;


};

struct listing getfields(char* line){
    struct listing item;

    item.id                  = atoi(strtok(line, ","));
    item.host_id             = atoi(strtok(NULL, ","));
    item.host_name           = strdup(strtok(NULL, ","));
    item.neighbourhood_group = strdup(strtok(NULL, ","));
    item.neighbourhood       = strdup(strtok(NULL, ","));
    item.latitude            = atof(strtok(NULL, ","));
    item.longitude           = atof(strtok(NULL, ","));
    item.room_type           = strdup(strtok(NULL, ","));
    item.price               = atoi(strtok(NULL, ","));
    item.minimum_nights      = atoi(strtok(NULL, ","));
    item.number_of_reviews   = atoi(strtok(NULL, ","));
    item.calculated_host_listings_count = atoi(strtok(NULL, ","));
    item.availability_365    = atoi(strtok(NULL, ","));
   
    return item;
};

void displayStruct(struct listing listItem){

    printf("ID : %d\n", listItem.id);
    printf("Host ID : %d\n", listItem.host_id);
    printf("Host Name : %s\n", listItem.host_name);
    printf("Neighbourhood Group : %s\n", listItem.neighbourhood_group);
    printf("Neighbourhood : %s\n", listItem.neighbourhood);
    printf("latitude : %f\n", listItem.latitude);
    printf("longitude : %f\n", listItem.longitude);
    printf("room_type : %s\n", listItem.room_type);
    printf("price : %d\n", listItem.price);
    printf("minimum_nights : %d\n", listItem.minimum_nights);
    printf("number_of_reviews : %d\n", listItem.number_of_reviews);
    printf("calculated_host_listings_count : %d\n", listItem.calculated_host_listings_count);
    printf("availability_365 : %d\n", listItem.availability_365);
    printf("\n");

    
}

int compareUsingHostname(const void *x, const void *y){

    // cast void pointer to char * because host_name is struct listing. extra * before (struct listing) is for deferencing and getting the value.
    // char * x1 = ((struct listing *) x) -> host_name;
    // char * y1 = ((struct listing *) y) -> host_name;
    // return strcmp(x1, y1);

    const struct listing *item_x = (const struct listing *) x;
    const struct listing *item_y = (const struct listing *) y;

    return strcmp(item_x->host_name, item_y->host_name);


}



int compareUsingPrice(const void *x_price, const void *y_price){

    int xprice = ((struct listing *) x_price) -> price;
    int yprice = ((struct listing *) y_price) -> price;

    
    return (xprice - yprice);
}

void writeToAFile_hostName(struct listing *listItems, FILE *outFile_hostname, int count){

    // fprintf(outFile_hostname, "host_id, host_name, neighbourhood_group, neighbourhood, latitude,longitude, room_type, price, minimum_nights,
    //      number_of_reviews, calculated_host_listings_count, availability_365\n");

    qsort(listItems, TOTAL_ROWS, sizeof(listItems[0]), compareUsingHostname);
    for(int i=1; i< count; i++){
        fprintf(outFile_hostname, "%d, %d, %s, %s, %s, %f, %f, %s, %d, %d, %d, %d, %d \n", listItems[i].id, 
        listItems[i].host_id, listItems[i].host_name, listItems[i].neighbourhood_group, listItems[i].neighbourhood, 
        listItems[i].latitude,listItems[i].longitude, listItems[i].room_type, listItems[i].price, listItems[i].minimum_nights,
        listItems[i].number_of_reviews, listItems[i].calculated_host_listings_count, listItems[i].availability_365);
    }

}

void writeToAFile_price(struct listing *listItems, FILE *outFile_price, int count){

    
    qsort(listItems, TOTAL_ROWS, sizeof(listItems[0]), compareUsingPrice);
    for(int i=1; i< count; i++){

        fprintf(outFile_price, "%d, %d, %s, %s, %s, %f, %f, %s, %d, %d, %d, %d, %d \n", listItems[i].id, 
        listItems[i].host_id, listItems[i].host_name, listItems[i].neighbourhood_group, listItems[i].neighbourhood, 
        listItems[i].latitude,listItems[i].longitude, listItems[i].room_type, listItems[i].price, listItems[i].minimum_nights,
        listItems[i].number_of_reviews, listItems[i].calculated_host_listings_count, listItems[i].availability_365);
    }
}


int main(int argc, char** argv){
   
    struct listing list_items[22555];
    struct listing list_items_copy[22555];
    FILE *fptr;
    FILE *outFile_hostname;
    FILE *outFile_price;
    char line[LINESIZE];
    int i, count = 0;


    fptr = fopen("listings.csv", "r");
    if(fptr == NULL){
        printf("Error opening the file \n");
        return 1;
    }

    
    // store all data in the array. 
    // fgets reads a line from the specified string and stores in line. It stops when either (n-1) characters are read, the newline char 
    // is read or eof is reached.
    while(fgets(line, LINESIZE, fptr) != NULL){
       
        list_items[count] = getfields(line);
        count++;
    }

     
    //I am sorting the list_items here using qsort() from C library. params = address of 1stelement of array, total elements in the array, size(bytes), address to a C function.

    

    outFile_hostname = fopen("outFile_hostname.csv", "w");
    outFile_price = fopen("outFile_price.csv", "w");

    printf("1\n");
    fprintf(outFile_hostname, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s \n", "id", 
    "host_id", "host_name", "neighbourhood_group", "neighbourhood", 
    "latitude", "longitude", "room_type", "price", "minimum_nights",
    "number_of_reviews", "calculated_host_listings_count", "availability_365");

    printf("2\n");
    fprintf(outFile_price, "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s \n", "id", 
    "host_id", "host_name", "neighbourhood_group", "neighbourhood", 
    "latitude", "longitude", "room_type", "price", "minimum_nights",
    "number_of_reviews", "calculated_host_listings_count", "availability_365");

    // for(i=0; i<count; i++){
    //     displayStruct(list_items[i]);        
    // }
    
    // copy listitems
    for(int i=0; i < count; i++){
        list_items_copy[i] = list_items[i];
    }
    writeToAFile_hostName(list_items,  outFile_hostname, TOTAL_ROWS);

    
    writeToAFile_price(list_items_copy,  outFile_price, count);

    fclose(fptr);
    fclose(outFile_hostname);
    fclose(outFile_price);
}

