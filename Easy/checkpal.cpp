#include <iostream>
using namespace std;

// Given an integer x, return true if x is a palindrome, and false otherwise.
bool brute(int n)
{
    long long temp = n;
    if (n == 0)
    {
        return true;
    }
    else if (n < 0)
    {
        return false;
    }
    else
    {
        long long ans = 0;
        while (n != 0)
        {
            int rem = n % 10;
            ans = ans * 10 + rem;
            n /= 10;
        }
        if (ans == temp)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

bool better(int n)
{
    string num = to_string(n);
    int i = 0, j = num.size() - 1;
    while (i <= j)
    {
        if (num[i] != num[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

bool palindrome(int n)
{
    return better(n);
}