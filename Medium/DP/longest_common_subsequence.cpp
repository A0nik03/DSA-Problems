// Longest Common Subsequence

/*
Given two strings str1 & str 2 of length n & m respectively, return the length of their longest common subsequence. If there is no common subsequence then, return 0. 

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "abe" is a subsequence of "abcde".
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends
// function to find longest common subsequence

class Solution {
  public:
    // Function to find the length of longest common subsequence in two strings.
    int f(int ind1, int ind2,string text1, string text2){
        if(ind1 < 0 || ind2 < 0) return 0;

        if(text1[ind1] == text2[ind2]){
            return 1 + f(ind1 - 1, ind2 - 1,text1,text2);
        }
        return 0 + max(f(ind1 - 1,ind2,text1,text2),f(ind1,ind2 - 1,text1,text2));
    }

    int f_memo(int ind1, int ind2,string text1, string text2,vector<vector<int>> &dp){
        if(ind1 < 0 || ind2 < 0) return 0;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(text1[ind1] == text2[ind2]){
            return 1 + f_memo(ind1 - 1, ind2 - 1,text1,text2,dp);
        }
        return dp[ind1][ind2] = 0 + max(f_memo(ind1 - 1,ind2,text1,text2,dp),f_memo(ind1,ind2 - 1,text1,text2,dp));
    }

    // Index Shifting is Applied, i - 1 is actually i
    int f_tabu(string text1, string text2){
        int n = text1.size(),m = text2.size();
        vector<vector<int>> dp(n + 1,vector<int> (m + 1,0));
        for(int i = 0; i <= n;i++) dp[i][0] = 0;
        for(int j = 0; j <= m;j++) dp[0][j] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m;j++){
                if(text1[i - 1] == text2[j - 1]){
                   dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else dp[i][j] = 0 + max(dp[i][j - 1],dp[i - 1][j]);
            }
        }
        return dp[n][m];
    }
    
    int lcs(int n, int m, string str1, string str2) {
        return f_tabu(str1,str2);
    }
};


//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends