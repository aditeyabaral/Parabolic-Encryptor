#include "header.h"

sum = 0;
/*
If we do not provide a declaration to the sum variable, it will lead to type casting as an integer. 
Although we do want it as an integer, this shouldn't be done to avoid type mismatches and possible loss of information.
*/


void secret()
{
    int s = INT_MAX/100;
    srand(time(0));
    int r = rand();
    int v = (r % (2000 - 1000)) + 2000;
    if (s>INT_MAX/v)
        printf("Overflow\n");
    else
        sum = s*v;

    /*
    The algorithm in the secret() function is capable of resulting in integer overflow based on the random value,
    and hence some characters in the text do not get encrypted. The algorithm needs to be redesigned such that no overflow
    can occur irrespective of the value randomly generated. 
    */
}


int parabola(int c)
{
    double x = sqrt(4*sum*c);
    return x;

    /*
    This problem carries over from the secret() function. If the value generated for sum is too large, it will
    result in an overflow, causing it to take a negative value greater than INT_MIN. But this value is extremely small,
    and the square root of this value will be zero as it's a domain error. Hence the original string will NOT be decrypted since the sum value
    determines the decryption distance.

    sqrt() also returns a double, and we are returning an integer to the calling function since the distance has to 
    be an integer
    */
}

void encrypt(char *str,char *enstr)
{
    secret();
    int l = strlen(str);    // If the length of str is more than 10^10, it will seg fault here
    int i = 0;
    while(i<l)
    {
        if(str[i]!=' ')
            enstr[i] = (str[i] + parabola(i));
        else
            enstr[i] = ' ';
        i++;
    }

    /*
    A '\0' needs to be appended at the end of the encrypted string to mark the end of the string.
    Without this delimiter, printing the string might result in an overflow.
    */
}

int inv_parabola(int c)
{
    double x = -1*sqrt(4*sum*c);
    return x;

    /*
    This problem carries over from the secret() function. If the value generated for sum is too large, it will
    result in an overflow, causing it to take a negative value greater than INT_MIN. But this value is extremely small,
    and the square root of this value will be zero as it's a domain error. Hence the original string will NOT be decrypted since the sum value
    determines the decryption distance.

    sqrt() also returns a double, and we are returning an integer to the calling function since the distance has to 
    be an integer
    */
}

void decrypt()
{
    char destr[100000];
    char temp[100000];
    int i = 0;
    char c = '0';   //c is an unused variable. It can be removed

    FILE *fp = fopen("Encrypted.txt","r");
    
    /*
    No check is performed to see if the file exists. The later sections of this function will crash if the file is 
    not present. Hence we need to add in a check to ensure the file exists and the pointer fp did not return NULL.
    */

    while(1)
    {
        if(i==0)
        {
            fscanf(fp,"%s\n",temp);
            sum = atoi(temp);
            printf("Key: %d\n",sum);
            i++;
            continue;
        }
        else
        {
            fscanf(fp,"%[^\n]s",temp);
            int l = strlen(temp);
            int j = 0;
            while(j<l)
            {
                if(temp[j]==' ')
                    destr[j] = ' ';
                else if(temp[j]=='\n')
                    destr[j] = '\n';
                else
                    destr[j] = (char)((int)temp[j] + inv_parabola(j));
                j++;
            }
            destr[j] = '\0';
        }
        if(feof(fp))
        	break;
    }

    printf("The decrypted string is:\n%s\n",destr);

    /*
    fp wasn't closed after the file reading operation.
    This must always be done to ensure the buffered data gets flushed
    */
    
    free(temp); 
    free(destr);
    // temp and destr are static arrays. We have attempted to free them. This cannot be done
}

void write_to_file(char*s)
{
    FILE* fp = fopen("Encrypted.txt","w");
    fprintf(fp,"%d\n%s",sum,s);
    fclose(fp);
}
