#include <stdio.h>
#include <stdlib.h>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


/**
 * Test a number whether is palindrome or not using reverting the number method
 * No auxilliary memory is needed
 */
int isPalindromeByCompareReversing(unsigned long int n)
{
    long int reverse = 0;
    long int copy = n;
    while(0 != n){
        reverse = reverse * 10 + n % 10;  // compse the reverse of the number
        n /= 10;
    }
    return (reverse == copy) ? 1 : 0;
}

int main(int argc, char *argv[])
{
    if (1 == argc) {
        printf("Usage: %s NUMBER.\n", argv[0]);
        exit(0);
    }

    long int n = atol(argv[1]);
    printf("%ld %s a palindrome number!\n", n, isPalindromeByCompareReversing(n)? BOLD GREEN "is"RESET: BOLD RED"is not"RESET);

    return 0;
}
