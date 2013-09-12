/**
 * AutoCounter.cpp -- Definition of static class members.
 *
 * Copyright (c) Leon (yong.he1982(at)gmail.com)
 * Date : 2013-09-12 [Thursday, 255]
 *
 * Build:
 *   g++ AutoCounter.cpp -o AutoCounter
 */

#include "AutoCounter.h"
AutoCounter::CleanupCheck AutoCounter::verifier;
int AutoCounter::count = 0;

///:~
