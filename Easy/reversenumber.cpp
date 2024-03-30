#include <iostream>
using namespace std;

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