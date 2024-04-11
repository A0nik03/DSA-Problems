#include <iostream>
using namespace std;

// Problem statement
// You are given two integers 'n', and 'm'.

// Calculate 'gcd(n,m)', without using library functions.

// Note:
// The greatest common divisor (gcd) of two numbers 'n' and 'm' is the largest positive number that divides both 'n' and 'm' without leaving a remainder.

// Brute
int calcGCD(int n, int m)
{

    while (n != 0 && m != 0)
    {

        if (n > m)
        {

            n = n % m;
        }
        else
        {

            m = m % n;
        }
    }

    return (n == 0) ? m : n;
}

// Better(Recurssion)
int gcd(int n, int m) 
{
    if (n == 0)
    {
        return m;
    }
    if (m == 0)
    {
        return n;
    }

    if (n < m)
    {
        return gcd(n, m % n);
    }
    else
    {
        return gcd(n % m, m);
    }
}

int calcGCD(int n, int m)
{
    return gcd(n, m);
}