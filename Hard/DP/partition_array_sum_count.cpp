// 2035. Partition Array Into Two Arrays to Minimize Sum Difference

/*
You are given an integer array nums of 2 * n integers. You need to partition nums into two arrays of length n to minimize the absolute difference of the sums of the arrays. To partition nums, put each element of nums into one of the two arrays.

Return the minimum possible absolute difference.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int n = arr.size();
        int totSum = 0;
        for (int i = 0; i < n; i++)
            totSum += arr[i];
        int k = totSum;
        vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        dp[0][0] = true;

        for (int i = 1; i <= k; i++) {
            dp[0][i] = (arr[0] == i);
        }

        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (arr[ind] <= target)
                    take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = take | notTake;
            }
        }

        int mini = 1e9;
        for (int s1 = 0; s1 <= totSum / 2; s1++) {
            if (dp[n - 1][s1] == true) {
                int s2 = totSum - s1;
                mini = min(mini, abs(s2 - s1));
            }
        }
        return mini;
    }
};