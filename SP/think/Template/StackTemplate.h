/**
 * StackTemplate.h -- A simple stack template.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-08 [Sunday, 251]
 */

#ifndef _HEADER_STACKTEMPLATE_H_
#define _HEADER_STACKTEMPLATE_H_

#include "../require.h"

template<class T>
class StackTemplate {
    enum { ssize = 100 };
    T stack[ssize];
    int top;

    public:
        StackTemplate() : top(0) {}

        void push(const T& i) {
            require(top < ssize, "Too many push()es");
            stack[top++] = i;
        }

        T pop() {
            require(top > 0, "Too many pop()s");
            return stack[--top];
        }

        int size() { return top; }
};

#endif /* :~_HEADER_STACKTEMPLATE_H_ */
