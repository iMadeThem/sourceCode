/**
 * testSortWithPtrf.c -- Sort string using pointer to function.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-07-07 [Sunday, 188]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // tolower

int compare(const char *str1, const char *str2)
{
    return strcmp(str1, str2);
}

// remember to free the returned pointer after use
char *toLower(const char *str)
{
    char *buf = (char *)malloc(strlen(str) + 1);
    char *begin = buf; // store the beginning address of buffer, that will be returned to caller

    while(*str) {
        *buf++ = tolower(*str++);
    }

    *buf = '\0';
    return begin;
}

int compareIgnoreCase(const char *str1, const char *str2)
{
    char *buf1 = toLower(str1);
    char *buf2 = toLower(str2);
    int result = strcmp(buf1, buf2);
    free(buf1);
    free(buf2);
    return result;
}

typedef int (*ptrf)(const char *, const char *);

void bubbleSort(char *array[], int size, ptrf cmp)
{
    int swap = 1;
    while(swap){
        swap = 0;
        for(int i = 0; i < size - 1; i++) {
            if(cmp(array[i], array[i+1]) > 0) {
                swap = 1;
                char *tmp = array[i];
                array[i] = array[i+1];
                array[i+1] = tmp;
            }
        }
    }
}

void displayNames(char* names[], int size)
{
    for(int i=0; i<size; i++) {
        printf("%s   ",names[i]);
    }
    printf("\n");
}


int main(int argc, char* argv[])
{
    // test case
    char* names[] = {"Bob", "Ted", "Carol", "Alice", "alice"};

    printf("==== Case sensitive.\n");
    bubbleSort(names,5,compare);
    displayNames(names,5);
    printf("==== Case in sensitive.\n");
    bubbleSort(names,5,compareIgnoreCase);
    displayNames(names,5);

    return 0;
}
