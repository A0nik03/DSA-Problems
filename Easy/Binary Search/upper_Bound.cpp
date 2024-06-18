// Ceil in a Sorted Array

/*
Given a sorted array arr[] of size n without duplicates, and given a value x. Ceil of x is defined as the largest element k in arr[] such that k is larger than or equal to x. Find the index of k(0-based indexing).
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find Celi of x
    // n: size of vector
    // x: element whose Ceil is to find
    int findCeil(vector<long long> v, long long n, long long x)
    {
        int ans = -1;

        int start = 0, end = n - 1;
        int mid = start + (end - start) / 2;
        while (start <= end)
        {
            if (v[mid] > x)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        long long x;
        cin >> x;

        vector<long long> v;

        for (long long i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findCeil(v, n, x) << endl;
    }

    return 0;
}
// } Driver Code Ends