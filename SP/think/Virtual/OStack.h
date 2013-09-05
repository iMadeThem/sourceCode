/**
 * OStack.h -- Using a singly-rooted hierarchy.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-05 [Thursday, 248]
 */

#ifndef _HEADER_OSTACK_H_
#define _HEADER_OSTACK_H_

#include <iostream>

class Object {
    public:
        virtual ~Object() = 0;
};

// Required definition:

inline Object::~Object() {std::cout << "~Object()" << std::endl; }

class Stack {
    struct Link {
        Object* data;
        Link* next;
        Link(Object * dat, Link * nxt) : data(dat), next(nxt) {}
    }* head;

    public:
        Stack() : head(0) {}

        ~Stack() {
            std::cout << "~Stack() enter" << std::endl;
            while(head) {
                std::cout << "~Stack()" << std::endl;
                delete pop();
            }
        }

        void push(Object* dat) {
            head = new Link(dat, head);
        }

        Object* peek() const {
            return head ? head->data : 0;
        }

        Object* pop() {
            if(head == 0) return 0;
            Object* result = head->data;
            Link* oldHead = head;
            head = head->next;
            delete oldHead;
            return result;
        }
};

#endif /* ~_HEADER_OSTACK_H_ */
