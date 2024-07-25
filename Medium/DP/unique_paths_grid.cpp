// 62. Unique Paths

#include <bits/stdc++.h>
using namespace std;

/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
*/

class Solution {
public:
    int f_r(int i, int j){
        if(j == 0 && i == 0){
            return 1;
        }
        if(i < 0 || j < 0) return 0;

        int up = f_r(i - 1,j);
        int left = f_r(i,j - 1);
        return up + left;
    }

    int f_memo(vector<vector<int>>& dp,int i, int j){
        if(j == 0 && i == 0){
            return 1;
        }
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = f_memo(dp,i - 1,j);
        int left = f_memo(dp,i,j - 1);
        return dp[i][j] = up + left;
    }

    int f_tabu(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    dp[0][0] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(i > 0) up = dp[i - 1][j];
                if(j > 0) left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int> (n , -1));
        return f_tabu(m, n);
    }
};