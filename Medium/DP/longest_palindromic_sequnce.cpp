// 516. Longest Palindromic Subsequence

/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(string str1,string str2){
        int n = str1.size(),m = str2.size();
        vector<vector<int>> dp(n + 1,vector<int> (m + 1, 0));
        for(int i = 0; i < n; i++) dp[i][0] = 0;
        for(int j = 0; j < m; j++) dp[0][j] = 0;

        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= m;j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
};