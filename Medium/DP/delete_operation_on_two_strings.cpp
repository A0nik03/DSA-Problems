// 583. Delete Operation for Two Strings

/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lcs(string str,string ptr){
        int n = str.size();
        int m = ptr.size();
        vector<vector<int>> dp (n + 1,vector<int> (m + 1,0));
        for(int i = 1; i <= n;i++){
            for(int j = 1; j <= m;j++){
                if(str[i - 1] == ptr[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2*lcs(word1,word2);
    }
};