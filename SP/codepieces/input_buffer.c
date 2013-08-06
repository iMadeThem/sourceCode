/**
 * input_buffer_test.c -- Demostration of input buffer.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-08-06 [Tuesday, 218]
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> // fork()

int main()
{
    pid_t pid;

    fprintf(stdout, "%s", "Start fork...");
    //fflush(stdout); // flush the buffer

    pid = fork();

    switch(pid) {
    case -1:
        printf("%s", "Parent process/\n");
        break;
    case 0:
        printf("%s", "Child process.\n");
        break;
    default:
        printf("%s", "Parent process\n");
    }

    return 0;
}

// Output
// Start fork...Parent process
// Start fork...Child process.
