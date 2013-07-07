/**
 * testString.c -- Test string methods.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-07-07 [Sunday, 188]
 */

#include <stdio.h>
#include <string.h> // strcat
#include <stdlib.h> // malloc

#define  ps(x) printf("%s\n", (x))
#define  pi(x) printf("%ld\n", (x))

size_t stringLength(const char* string)
{
    size_t length = 0;
    while(*(string++)) {
        length++;
    }
    return length;
}

size_t stringArrayLength(const char string[])
{
    size_t length = 0;
    while(*(string++)) {
        length++;
    }
    return length;
}

char* blanks(int number)
{
    char* spaces = (char*) malloc(number + 1);
    printf("%p\n", spaces);

    int i;
    for (i = 0; i<number; i++) {
        spaces[i] = ' ';
    }
    spaces[number] = '\0';
    printf("%p\n", spaces);
    return spaces;
}

char* blanks_e(int number)
{
    char* spaces = (char*) malloc(number + 1);
    printf("%p\n", spaces);

    int i;
    for (i = 0; i<number; i++) {
        *(spaces++) = ' '; // this is bad, will cause error
    }
    spaces[number] = '\0';
    printf("%p\n", spaces);
    return spaces;
}


int main(int argc, char* argv[])
{

    char *bl = blanks(2);
    free(bl);
//    bl = blanks_e(2);
//    free(bl); // this will cause run time error

    // strcat
/* unsigned char* error = "ERROR: ";
    warning: initializing 'unsigned char *' with an expression of type 'char [8]'
    converts between pointers to integer types with different sign [-Wpointer-sign]
*/

    char* error = "ERROR: ";
    char* errorMessage = "Not enough memory";

    char errorArr[] = "ERROR: ";
    char errorMessageArr[] = "Not enough memory";

    pi(stringLength(error));
    pi(stringArrayLength(error));

    // mormal case
    char* buffer = (char*)malloc(strlen(error)+strlen(errorMessage)+1);
    strcpy(buffer,error);
    strcat(buffer, errorMessage);
    ps("-------Normal case");
    printf("%s\n", buffer);
    printf("%s\n", error);
    printf("%s\n", errorMessage);

/*    ps("-------Error case 1");
    strcat(errorArr, errorMessageArr);
    ps(errorArr); // Abort trap: 6
*/
    // error case
    ps("-------Error case");
    strcat(error, errorMessage);  // Bus error: 10
    printf("%s\n", error);
    printf("%s\n", errorMessage);



    return 0;
}
