// Distinct Subsequences

/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind1, int ind2, string s, string t) {
        if (ind2 < 0)
            return 1;
        if (ind1 < 0)
            return 0;
        if (s[ind1] == t[ind2]) {
            return solve(ind1 - 1, ind2 - 1, s, t) +
                   solve(ind1 - 1, ind2, s, t);
        }
        return solve(ind1 - 1, ind2, s, t);
    }

    int solve_memo(int ind1, int ind2, string s, string t,
                   vector<vector<int>>& dp) {
        if (ind2 < 0)
            return 1;
        if (ind1 < 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        if (s[ind1] == t[ind2]) {
            return solve_memo(ind1 - 1, ind2 - 1, s, t, dp) +
                   solve_memo(ind1 - 1, ind2, s, t, dp);
        }
        return solve_memo(ind1 - 1, ind2, s, t, dp);
    }

    const int MOD = 1000000007;

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};