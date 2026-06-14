## Compilation Instructions

If you're using a C file

gcc -o assignment ./Lab6.c # This will compile the filename and return an executable with the executable name
./assignment # This will compile Lab5.c and output an executable called assignment

## My Files
Lab6.c

#### main()

1. Open listings.csv in read mode. Then check if the file ptr is NULL and print file not found if the condition becomes true.
2. Else, iterate through the csv file and fetch the data row-wise using getfields() function and store it in the list_items struct listing object. Each element has one row value.
3. We open 2 files called outFile_hostname.csv and outFile_price.csv using file pointers outFile_hostname and outFile_price in write mode.
4. We initialize/add headers to the first row of both the CSV files using fprintf.
5. We create a copy of list_items to list_items_copy. We use list_items to sort the csv data using host_name and list_items_copy to sort the CSV data using price.
6. Then we close all the file pointers.
-------------------------------------------------------------------------------------------------------------------------------------------
#### getfields(char* line)

1. We declare an item of type struct listing item.id, item.host_id, item.host_name, item.neighbourhood_group, item.neighborhood, item.latitude, item.longitude, item.room_type, 
    item.price, item.minimum_nights, item.number_of_reviews, item.calculated_host_listings_count, item.availability_365.
2. We then return the item.
------------------------------------------------------------------------------------------------------------------------------------------------

#### writeToAFile_hostName(list_items, outFile_hostname, TOTAL_ROWS)

1. We use qsort to sort the sort the hostname and change the order of rows as per the aphabetical order of hostname value by calling compareUsingHostname().
2. After this, we write to the outFile_hostname using fprintf.
   
------------------------------------------------------------------------------------------------------------------------------------------------
#### compareUsingHostname(const void *x, const void *y)

1. We take the hostnames as input, compare them using strcmp, and return the earlier string alphabetically.
------------------------------------------------------------------------------------------------------------------------------------------------

#### writeToAFile_price(struct listing *listItems, FILE *outFile_price, int count)

1. We use qsort to sort the hostname and change the order of rows as per the alphabetical order of hostname value by calling compareUsingPrice().
2. After this, we write to the outFile_hostname using fprintf.
------------------------------------------------------------------------------------------------------------------------------------------------

#### compareUsingPrice(const void *x_price, const void *y_price)

1. Compare the prices and sort from lowest to highest price.
------------------------------------------------------------------------------------------------------------------------------------------------

## Output Screenshots
![output-1](https://github.com/SuvarnaSN/CS332-532/assets/156342036/8433806e-2966-4f01-ace2-07b1b56d8c8c)
![output-2](https://github.com/SuvarnaSN/CS332-532/assets/156342036/aa892a40-dcaf-400a-a385-c5eff4813edf)

## Github link
https://github.com/SuvarnaSN/CS332-532/tree/main/Lab5

