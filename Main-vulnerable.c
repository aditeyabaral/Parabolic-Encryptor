#include "header.h"
int main()
{
    char* str = (char*)malloc(sizeof(char)*100);

    /*
    If the input size is larger than allocated size, it will result in a buffer overflow. 
    However, if the size if greater than 10^10, it will lead to segmentation faults in functions used later like strlen. 
    We should also use calloc to ensure the entire array has been initialized to null string.
    */
    
    
    // If str is NULL, then the program will crash everytime we try to access it. Hence we should check that before 
    // using it.
    
    gets(str);
    /* gets() is not safe since it is unbounded. Should be replaced with scanf */
    
    printf("Original text: \n%s\n\n",str);
    
    char* enstr = (char*)malloc(sizeof(char)*10);

    /*
    Since the encrypted string size is lesser than the input size, it will result in an overflow.
    The allocated size must be equal to or more than the input size. 
    */
    
    // If enstr is NULL, then the program will crash everytime we try to access it. Hence we should check that before 
    // using it.
    
    encrypt(str,enstr);
    write_to_file(enstr);

    printf("Key: %d\n",sum);
    printf("The encrypted string is:\n%s\n\n",enstr);
    decrypt();

    free(str);
    free(str);

    /*
    There are multiple free statements for the same pointer. There should only be one free statement.
    Also, dynamic array enstr has not been freed. This is going to result in a memory leak.
    */

    return 0;
}

