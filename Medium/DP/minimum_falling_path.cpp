// 931. Minimum Falling Path Sum

/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f_rec(vector<vector<int>>& matrix,int i,int j){
        if(j < 0 || j >= matrix[0].size()) return 1e8;
        if(i == 0) return matrix[0][j];
        int u = matrix[i][j] + f_rec(matrix,i - 1, j);
        int ul = matrix[i][j] + f_rec(matrix,i - 1, j - 1);
        int ur = matrix[i][j] + f_rec(matrix,i - 1, j + 1);
        return min(u,min(ul,ur));
    }

    int f_memo(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(j < 0 || j >= matrix[0].size()) return 1e8;
        if(i == 0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int u = matrix[i][j] + f_memo(matrix,i - 1, j,dp);
        int ul = matrix[i][j] + f_memo(matrix,i - 1, j - 1,dp);
        int ur = matrix[i][j] + f_memo(matrix,i - 1, j + 1,dp);
        return dp[i][j] = min(u,min(ul,ur));
    }

    int f_tabu(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int j = 0; j < m; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                int up = matrix[i][j] + dp[i - 1][j];

                int leftUp = matrix[i][j];
                if(j - 1 >= 0){
                    leftUp += dp[i - 1][j - 1];
                }else{
                    leftUp += 1e9;
                }

                int rightUp = matrix[i][j];
                if(j + 1 < m){
                    rightUp += dp[i - 1][j + 1];
                }else{
                    rightUp += 1e9;
                }

                dp[i][j] = min(up,min(leftUp,rightUp));
            }
        }

        int mini = INT_MAX;
        for(int j = 0; j < m; j++){
            mini = min(mini,dp[n - 1][j]);
        }
        return mini;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        // int mini = 1e8;
        // for(int j = 0; j < m; j++){
        //     mini = min(mini,f_memo(matrix,n - 1, j,dp));
        // }
        return f_tabu(matrix);
    }
};