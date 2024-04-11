#include <iostream>
using namespace std;

// Problem Statement: Given a number N reverse the number and print it.

int reverse(int n)
{
    long ans = 0;
    while (n)
    {
        int rem = n % 10;
        ans = ans * 10 + rem;
        n /= 10;
    }
    if (ans > INT64_MAX|| ans < INT64_MIN)
    {
        return 0;
    }
    return ans;
}

// Time Complexity: O(n), where n is the length of the given number

// Space Complexity: O(1)