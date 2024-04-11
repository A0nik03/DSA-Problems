#include <iostream>
using namespace std;

// Problem statement
// You are given an integer 'n'.
// Return 'true' if 'n' is an Armstrong number, and 'false' otherwise.

// Note:
// An Armstrong number is a number (with 'k' digits) such that the sum of its digits raised to 'kth' power is equal to the number itself. For example, 371 is an Armstrong number because 3^3 + 7^3 + 1^3 = 371.

// Brute
int cube(int rem, int size)
{
    int mult = rem;
    for (int i = 0; i < size - 1; i++)
    {
        rem = rem * mult;
    }

    return rem;
}

bool checkArmstrong(int n)
{
    string num = to_string(n);
    int ans = 0;
    int temp = n;
    while (n != 0)
    {
        int rem = n % 10;
        int c = cube(rem, num.size());
        ans = ans + c;
        n /= 10;
    }
    if (ans == temp)
    {
        return 1;
    }
    else
    {
        return false;
    }
}
// Time Complexity: O(n) where n is the number of digits since we need to traverse every digit and add digits raised to power no. of digits to sum.
// Space Complexity: O(1) since no extra space is required

int main()
{
    int n = 1634;
    cout << checkArmstrong(n);
}