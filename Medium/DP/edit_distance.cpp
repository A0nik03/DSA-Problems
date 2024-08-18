// 72. Edit Distance

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int i,int j,string s, string t){
        if(i == 0) return j;
        if(j == 0) return i;
        if(s[i - 1] == t[j - 1]){
            return f(i - 1,j - 1,s,t);
        }
        else{
            return 1 + min(f(i,j - 1,s,t),min(f(i - 1,j - 1,s,t),f(i - 1,j,s,t)));
        }
    }

    int f_memo(int i,int j,string s, string t,vector<vector<int>> dp){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i - 1] == t[j - 1]){
            return dp[i][j] = f(i - 1,j - 1,s,t);
        }
        else{
            return dp[i][j] = 1 + min(f_memo(i,j - 1,s,t,dp),min(f_memo(i - 1,j - 1,s,t,dp),f_memo(i - 1,j,s,t,dp)));
        }
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>> dp(n + 1,vector<int> (m + 1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = i;
        for(int j = 0; j <= m; j++) dp[0][j] = j;
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i][j - 1],min(dp[i - 1][j - 1],dp[i - 1][j]));
                }
            }
        }
        return dp[n][m];
    }
};