#include "header.h"
int main()
{
    char* str = (char*)calloc(100000,sizeof(char));

    // A large size has been used and calloc has been used to initialise all locations to null string

    if(str==NULL)
    {
    	printf("\nMemory allocation error, exiting.\n");
    	exit(0);
    }
    // The program will only be executed further if str is not NULL here, else it will terminate execution.
    
    scanf("%100000[^\n]s",str);     // gets() has been replaced with scanf since it is safe

    printf("Original text: \n%s\n\n",str);
    
    char* enstr = (char*)calloc(100000,sizeof(char));

    // The allocated size has been set to the input size and calloc has been used to initialize it to null string.

    if(enstr==NULL)
    {
    	printf("\nMemory allocation error, exiting.\n");
    	exit(0);
    }
    // The program will only be executed further if enstr is not NULL here, else it will terminate execution.
    
    encrypt(str,enstr);
    write_to_file(enstr);
    
    printf("Key: %d\n",sum);
    printf("The encrypted string is:\n%s\n\n",enstr);
    decrypt();

    free(str);      // str has been freed only once
    free(enstr);    // enstr has been freed, preventing a memory leak
    return 0;
}

