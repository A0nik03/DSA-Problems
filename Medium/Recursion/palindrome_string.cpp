#include <iostream>
using namespace std;

// Brute(Advanced)
bool check(string &str) {
        int left = 0, right = str.size() - 1;
        while (left <= right) {
            if (!isalnum(str[left])) {
                left++;
                continue;
            }
            if (!isalnum(str[right])) {
                right--;
                continue;
            }

            if (tolower(str[left]) != tolower(str[right])) {
                return false;
            } else {
                left++;
                right--;
            }
        }
        return true;
    }
// Time Complexity:  O(N)
// Space Complexity: O(1)


// Reccursive(One)
bool checkOne(string &str, int i)
{
    if (i >= str.size() / 2)
    {
        return true;
    }
    if (str[i] != str[str.size() + i - 1])
    {
        return false;
    }
    return checkOne(str, i + 1);
}

bool isPalindromeOne(string &str)
{
    return checkOne(str, 0);
}
// Time Complexity:  O(N)
// Space Complexity: O(1)

// Reccursive(Two) --> Better
void checkbet(string &str, int i, bool &val)
{
    if (i >= str.size() / 2)
    {
        return;
    }
    if (str[i] != str[str.size() - i - 1])
    {
        val = false;
        return;
    }

    checkbet(str, i + 1, val);
}

bool isPalindrome(string &str)
{
    return check(str);
}

// Time Complexity: O(N) { Precisely, O(N/2) as we compare the elements N/2 times and swap them}.
// Space Complexity: O(1) { The elements of the given array are swapped in place so no extra space is required}.

int main()
{
    string name = "race a car";
    cout << isPalindrome(name);
}