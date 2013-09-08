/**
 * fibonacci.h -- Fibonacci number generator.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-08 [Sunday, 251]
 */

#ifndef _HEADER_FIBONACCI_H_
#define _HEADER_FIBONACCI_H_

#include "../require.h"

int fibonacci(int n) {
    const int sz = 100;
    require(n < sz);

    static int f[sz]; // Initialized to zero
    f[0] = f[1] = 1;
    // Scan for unfilled array elements:
    int i;
    for(i = 0; i < sz; i++)
        if(f[i] == 0) break;
    while(i <= n) {
        f[i] = f[i - 1] + f[i - 2];
        i++;
    }
    return f[n];
}

#endif /* :~_HEADER_FIBONACCI_H_ */
