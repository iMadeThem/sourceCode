/**
 * PStash.h -- Test object holds pointers instead of objects.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-22 [Thursday, 234]
 */

#ifndef _HEADER_PSTASH_H_
#define _HEADER_PSTASH_H_

class PStash
{
    int quantity; // Number of storage spaces
    int next; // Next empty space
    // Pointer storage:
    void** storage;
    void inflate(int increase);

    public:
        PStash() : quantity(0), storage(0), next(0) {}
        ~PStash();

        int add(void* element);

        void* operator[] (int index) const;
        // Fetch
        // Remove the reference from this PStash:
        void* remove(int index);

        // Number of elements in Stash:
        int count() const {
            return next;
        }
};

#endif /* ~_HEADER_PSTASH_H_ */
