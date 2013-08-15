/**
 * Integer.h -- Integer class with binary operator overriding.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-15 [Thursday, 227]
 */

#ifndef _HEADER_INTEGER_H_
#define _HEADER_INTEGER_H_

#include <iostream>
// Non-member functions:
class Integer
{
    long i;
    public:
        Integer(long ll = 0) : i(ll) {}
        // Operators that create new, modified value:
        friend const Integer operator + (const Integer &left, const Integer &right);
        friend const Integer operator - (const Integer &left, const Integer &right);
        friend const Integer operator*(const Integer &left, const Integer &right);
        friend const Integer operator / (const Integer &left, const Integer &right);
        friend const Integer operator % (const Integer &left, const Integer &right);
        friend const Integer operator ^ (const Integer &left, const Integer &right);
        friend const Integer operator& (const Integer &left, const Integer &right);
        friend const Integer operator | (const Integer &left, const Integer &right);
        friend const Integer operator << (const Integer &left, const Integer &right);
        friend const Integer operator >> (const Integer &left, const Integer &right);
        // Assignments modify & return lvalue:
        friend Integer& operator += (Integer & left, const Integer &right);
        friend Integer& operator -= (Integer & left, const Integer &right);
        friend Integer& operator *= (Integer & left, const Integer &right);
        friend Integer& operator /= (Integer & left, const Integer &right);
        friend Integer& operator %= (Integer & left, const Integer &right);
        friend Integer& operator ^= (Integer & left, const Integer &right);
        friend Integer& operator &= (Integer & left, const Integer &right);
        friend Integer& operator |= (Integer & left, const Integer &right);
        friend Integer& operator >>= (Integer & left, const Integer &right);
        friend Integer& operator <<= (Integer & left, const Integer &right);

        // Conditional operators return true/false:
        friend int operator == (const Integer &left, const Integer &right);
        friend int operator != (const Integer &left, const Integer &right);
        friend int operator < (const Integer &left, const Integer &right);
        friend int operator > (const Integer &left, const Integer &right);
        friend int operator <= (const Integer &left, const Integer &right);
        friend int operator >= (const Integer &left, const Integer &right);
        friend int operator && (const Integer &left, const Integer &right);
        friend int operator || (const Integer &left, const Integer &right);

        // Write the contents to an ostream:
        void print(std::ostream& os) const {
            os << i;
        }
};

#endif /* ~_HEADER_INTEGER_H_ */
