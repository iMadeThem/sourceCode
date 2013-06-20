#include <stdio.h>
#include <sys/types.h>

int main()
{
    
    pid_t pid;
    
    fprintf(stdout, "%s", "Start fork...");
    //fflush(stdout); // flush the buffer
    
    pid = fork();
    
    switch(pid)
    {
    case -1:
        break;
    case 0:
        printf("%s", "Child process.\n");
        break;
    default:
        printf("%s", "Parent process/\n");
    }
    
    return 0;
    
}
