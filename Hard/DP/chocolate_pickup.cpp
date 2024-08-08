// Chocolates Pickup

/*
You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of chocolates collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the chocolates.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
//   Recursion
    int f(int i, int j1, int j2,int n,int m, vector<vector<int>>& grid){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
            return -1e8;
        }
        if(i == n - 1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= +1; dj1++){
            for(int dj2 = -1;dj2 <= +1; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f(i + 1,j1 + dj1,j2 + dj2,n,m,grid);
                maxi = max(maxi,value);
            }
        }
        return maxi;
    }
// Memoization

    int f_memo(int i, int j1, int j2,int n,int m, vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
            return -1e8;
        }
        if(i == n - 1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= +1; dj1++){
            for(int dj2 = -1;dj2 <= +1; dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f_memo(i + 1,j1 + dj1,j2 + dj2,n,m,grid,dp);
                maxi = max(maxi,value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    
    // Tabulation
    
    int f_tabu(int n, int m, vector<vector<int>>& grid) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2) dp[n - 1][j1][j2] = grid[n - 1][j1];
            else dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                int maxi = -1e8;
                for (int dj1 = -1; dj1 <= +1; dj1++) {
                    for (int dj2 = -1; dj2 <= +1; dj2++) {
                        int value = 0;
                        if (j1 == j2) value = grid[i][j1];
                        else value = grid[i][j1] + grid[i][j2];
                        
                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;

                        if (nj1 >= 0 && nj1 < m && nj2 >= 0 && nj2 < m)
                            value += dp[i + 1][nj1][nj2];
                        else
                            value += -1e8;

                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][m - 1];
}

    
    
    int solve(int n, int m, vector<vector<int>>& grid) {
        // vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m, -1)));
        return f_tabu(n,m,grid);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends