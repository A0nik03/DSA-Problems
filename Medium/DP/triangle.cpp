// 120. Triangle

/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f_rec(vector<vector<int>>& triangle,int n, int i, int j) {
        if(i == n - 1) return triangle[n - 1][j];

        int d = triangle[i][j] + f_rec(triangle,n,i + 1,j);
        int dg = triangle[i][j] + f_rec(triangle,n,i + 1, j + 1);
        return min(d,dg);
    }

    int f_memo(vector<vector<int>>& triangle,int n, int i, int j, vector<vector<int>> &dp) {
        if(i == n - 1) return triangle[n - 1][j];

        if(dp[i][j] != -1) return dp[i][j];

        int d = triangle[i][j] + f_memo(triangle,n,i + 1,j,dp);
        int dg = triangle[i][j] + f_memo(triangle,n,i + 1, j + 1,dp);
        return dp[i][j] = min(d,dg);
    }

    int f_tabu(vector<vector<int>>& triangle,int n) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int j = 0; j < n; j++){
            dp[n - 1][j] = triangle[n - 1][j];
        }
        for(int i = n - 2; i >= 0; i--){
            for(int j = i; j >= 0; j--){
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        return f_tabu(triangle,n);
    }
};