#include <bits/stdc++.h>
#include <vector>
using namespace std;

int brute_loop(vector<int> &arr, int x)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xorr = 0;
            for (int k = i; k <= j; k++)
            {
                xorr = xorr ^ arr[k];
            }
            if (xorr == x)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int better_loop(vector<int> &arr, int x)
{
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int xorr = 0;
        for (int j = i; j < n; j++)
        {
            xorr = xorr ^ arr[j];
            if (xorr == x)
            {
                cnt++;
            }
        }
    }
    return cnt;
}

int optimal_hashing(vector<int> &arr, int x)
{
    int n = arr.size();
    map<int, int> mpp;
    int xorr = 0, cnt = 0;
    mpp[xorr]++;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
        int rem = xorr ^ x;
        cnt += mpp[rem];
        mpp[xorr]++;
    }
    return cnt;
}

int solve(vector<int> &A, int B)
{
    return optimal_hashing(A, B);
}
