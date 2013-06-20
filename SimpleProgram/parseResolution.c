#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char resolution[18];// = "1024X768";
    char *delims = "xX*";
    char temp[32];
    int width;
    int height;
    int first = 1;
    char *result = NULL;

    printf("Input the resolution as WIDTHxHEIGHT: ");
    
    scanf("%s", resolution);
    snprintf(temp, sizeof(temp), "%s", resolution);
 /* 
    Use a temp buffer to process, 
    because the strtok will change the string when parsing
 */
    result = strtok(temp, delims);

    while(result!=NULL){
        if(first){
            width = atoi(result);
        }
        
        if(!first){
            height = atoi(result);
        }
        first = 0; 
        result = strtok(NULL, delims);
    }


/*     width = strtol(temp, &temp, 10); */
/*     if(*temp) */
/* 	temp++; */
/*     height = strtol(temp, &temp, 10); */

    printf("Width:%d, Height:%d\n", width, height);
    printf("Resolution: %s\n", resolution);

    return 0;
}
