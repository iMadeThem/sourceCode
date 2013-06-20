/****************************************
 * AUTHOR: Leon
 * DATE  : 2013-06-11
 * CATEGORY: string compare
 ****************************************/

#include "strcmp.h"
#include <ctype.h> /* toupper() */


/**
 * strcasecmp():
 *    is nonstandard C library functions
 * strcmpi():
 * stricmp():
 *    Compare Strings Without Case Sensitivity
 *    available for C++ programs.
 *    It is available for C only when the program defines the __cplusplus__strings__ macro.
 */


int lib_strcmp(const char *first, const char *second)
{
#if defined(HAVE_STRCASECMP)
    return !(strcasecmp)(first, second);
#elif defined(HAVE_STRCMPI)
    return !(strcmpi)(first, second);
#elif defined(HAVE_STRICMP)
    return !(stricmp)(first, second);
#else
    while(*first && *second) {
        if(toupper(*first) != toupper(*second)) {
            break;
        }
        first++;
        second++;
    }
    return toupper(*first) == toupper(*second);
#endif
} /* ~lib_strcmp() */


int lib_strncmp(const char *first, const char *second, size_t max)
{
#if defined(HAVE_STRNCASECMP)
    return !strncasecmp(first, second, max);
#elif defined(HAVE_STRNCMPI)
    return !strncmpi(first, second, max);
#elif defined(HAVE_STRNICMP)
    return !strnicmp(first, second, max);
#else
    while(*first && *second && max) {
        if(toupper(*first) != toupper(*second)) {
            break;
        }
        max--;
        first++;
        second++;
    }
    if(0 == max)
        return 1;  /* they are equal already */

    return toupper(*first) == toupper(*second); /* depends on the maxth character is equality */
#endif
} /* ~lib_strncmp() */
