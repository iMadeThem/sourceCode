/**
 * Integer.cpp -- Realization of Integer class with binary operator overriding.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-08-15 [Thursday, 227]
 *
 */

#include "Integer.h"
#include "../require.h"
const Integer operator+(const Integer& left, const Integer& right)
{
    return Integer(left.i + right.i);
}

const Integer operator-(const Integer& left, const Integer& right)
{
    return Integer(left.i - right.i);
}

const Integer operator*(const Integer& left, const Integer& right)
{
    return Integer(left.i * right.i);
}

const Integer operator/(const Integer& left, const Integer& right)
{
    require(right.i != 0, "divide by zero");
    return Integer(left.i / right.i);
}

const Integer operator%(const Integer& left, const Integer& right)
{
    require(right.i != 0, "modulo by zero");
    return Integer(left.i % right.i);
}

const Integer operator^(const Integer& left, const Integer& right)
{
    return Integer(left.i ^ right.i);
}

const Integer operator&(const Integer& left, const Integer& right)
{
    return Integer(left.i & right.i);
}

const Integer operator|(const Integer& left, const Integer& right)
{
    return Integer(left.i | right.i);
}

const Integer operator<<(const Integer& left, const Integer& right)
{
    return Integer(left.i << right.i);
}

const Integer operator>>(const Integer& left, const Integer& right)
{
    return Integer(left.i >> right.i);
}

// Assignments modify & return lvalue:
Integer& operator+=(Integer& left, const Integer& right)
{
    if(&left == &right) {
        /* self-assignment */
    }
    left.i += right.i;
    return left;
}

Integer& operator-=(Integer& left, const Integer& right)
{
    if(&left == &right) {
        /* self-assignment */
    }
    left.i -= right.i;
    return left;
}

Integer& operator*=(Integer& left, const Integer& right)
{
    if(&left == &right) {
        /* self-assignment */
    }
    left.i *= right.i;
    return left;
}

Integer& operator/=(Integer& left, const Integer& right)
{
    require(right.i != 0, "divide by zero");
    if(&left == &right) {
        /* self-assignment */
    }
    left.i /= right.i;
    return left;
}

Integer& operator%=(Integer& left, const Integer& right)
{
    require(right.i != 0, "modulo by zero");
    if(&left == &right) {
        /* self-assignment */
    }
    left.i %= right.i;
    return left;
}

Integer& operator^=(Integer& left, const Integer& right)
{
    if(&left == &right) {
        /* self-assignment */
    }
    left.i ^= right.i;
    return left;
}

Integer& operator&=(Integer& left, const Integer& right)
{
    if(&left == &right) {
        /* self-assignment */
    }
    left.i &= right.i;
    return left;
}

Integer& operator|=(Integer& left, const Integer& right)
{
    if(&left == &right) {
        /* self-assignment */
    }
    left.i |= right.i;
    return left;
}

Integer& operator>>=(Integer& left, const Integer& right)
{
    if(&left == &right) {
        /* self-assignment */
    }
    left.i >>= right.i;
    return left;
}

Integer& operator<<=(Integer& left, const Integer& right)
{
    if(&left == &right) {
        /* self-assignment */
    }
    left.i <<= right.i;
    return left;
}

// Conditional operators return true/false:
int operator==(const Integer& left, const Integer& right)
{
    return left.i == right.i;
}

int operator!=(const Integer& left, const Integer& right)
{
    return left.i != right.i;
}

int operator<(const Integer& left, const Integer& right)
{
    return left.i < right.i;
}

int operator>(const Integer& left, const Integer& right)
{
    return left.i > right.i;
}

int operator<=(const Integer& left, const Integer& right)
{
    return left.i <= right.i;
}

int operator>=(const Integer& left, const Integer& right)
{
    return left.i >= right.i;
}

int operator&&(const Integer& left, const Integer& right)
{
    return left.i && right.i;
}

int operator||(const Integer& left, const Integer& right)
{
    return left.i || right.i;
} ///:~