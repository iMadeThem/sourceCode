/**
 * testStructSize.c -- Test the struct size, to see padding
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-07-08 [Monday, 189]
 */

#include <stdio.h>

int main(int argc, char* argv[])
{
    typedef struct _person
    {
        char* firstName;
        char* lastName;
        char* title;
        unsigned int age;
    }Person;

    typedef struct _alternatePerson
    {
        char* firstName;
        char* lastName;
        char* title;
        short age;
    } AlternatePerson;

    Person person;
    AlternatePerson otherPerson;

    printf("size of pointer: %ld\n", sizeof(void *));
    printf("size of int: %ld\n", sizeof(int));
    printf("size of short: %ld\n", sizeof(short));

    printf("%ld\n",sizeof(Person));
    // Displays 32
    printf("%ld\n",sizeof(AlternatePerson));
    // Displays 32

    return 0;
}
