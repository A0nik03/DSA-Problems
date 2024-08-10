// Count Subsets with Sum K

/*
You are given an array 'arr' of size 'n' containing positive integers and a target sum 'k'.
Find the number of ways of selecting the elements from the array such that the sum of chosen elements is equal to the target 'k'.
Since the number of ways can be very large, print it modulo 10 ^ 9 + 7.
Example:
Input: 'arr' = [1, 1, 4, 5]
*/

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int f(int ind, vector<int> &arr, int k) {
  if (k == 0)
    return 1;
  if (ind == 0)
    return arr[0] == k;

  int notPick = f(ind - 1, arr, k);
  int pick = 0;
  if (arr[ind] <= k) {
    pick = f(ind - 1, arr, k - arr[ind]);
  }
  return pick + notPick;
}

int f_memo(int ind, vector<int> &arr, int k, vector<vector<int>> &dp) {
  if (k == 0)
    return 1;
  if (ind == 0)
    return arr[0] == k;
  if (dp[ind][k] != -1)
    return dp[ind][k];
  int notPick = f_memo(ind - 1, arr, k, dp);
  int pick = 0;
  if (arr[ind] <= k) {
    pick = f_memo(ind - 1, arr, k - arr[ind], dp);
  }
  return dp[ind][k] = (pick + notPick) % mod;
}

int f_tabu(vector<int> &arr, int k) {
   int n = arr.size();
   vector<vector<int>> dp(n,vector<int> (k + 1, 0));
   const int mod = 1e9 + 7;
    for(int i = 0; i < n; i++) dp[i][0] = 1;
    
    for (int j = 0; j <= k; j++) {
        if (arr[0] == 0) {
            dp[0][0] = 2;
        } else if (arr[0] == j) {
            dp[0][j] = 1;
        }
    }

    for(int ind = 1; ind < n; ind++){
        for(int sum = 0; sum <= k;sum++){
            int notPick = dp[ind - 1][sum];
            int pick = 0;
            if(arr[ind] <= sum){
                pick = dp[ind - 1][sum - arr[ind]];
            }
            dp[ind][sum] = (pick + notPick)%mod;
        }
    }
    return dp[n - 1][k];
}

int findWays(vector<int> &arr, int k) { return f_tabu(arr, k); }


