// 44. Wildcard Matching

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool f(int i, int j, string s, string p) {
        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;
        if (i < 0 && j >= 0) {
            for (int jj = 0; jj <= j; jj++) {
                if (p[jj] != '*')
                    return false;
            }
            return true;
        }

        if (s[i] == p[j] || p[j] == '?') {
            return f(i - 1, j - 1, s, p);
        }
        if (p[j] == '*') {
            return f(i, j - 1, s, p) | f(i - 1, j, s, p);
        }
        return false;
    }

    bool f_memo(int i, int j, string s, string p, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return true;
        if (i > 0 && j == 0)
            return false;
        if (i == 0 && j > 0) {
            for (int jj = 1; jj <= j; jj++) {
                if (p[jj - 1] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[j - 1] == '*') {
            return dp[i][j] = f_memo(i, j - 1, s, p, dp) | f_memo(i - 1, j, s, p, dp);
        }
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
            return dp[i][j] = f_memo(i - 1, j - 1, s, p, dp);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            dp[i][0] = false;
        }
        for(int j = 1; j <=m;j++){
            bool flag = true;
            for (int jj = 1; jj <= j; jj++) {
                if (p[jj - 1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for(int i = 1; i <=n;i++){
            for(int j = 1; j <= m;j++){
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};