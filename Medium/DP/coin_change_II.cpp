// 518. Coin Change II

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int f(int ind,int target, vector<int>& coins){
        if(ind == 0){
            return target % coins[0] == 0;
        }
        int notTake = f(ind - 1,target,coins);
        int take = 0;
        if(coins[ind] <= target) take = f(ind, target - coins[ind],coins);
        return take + notTake;
    }

    int f_memo(int ind,int target, vector<int>& coins,vector<vector<int>> &dp){
        if(ind == 0){
            return target % coins[0] == 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = f_memo(ind - 1,target,coins,dp);
        int take = 0;
        if(coins[ind] <= target) take = f_memo(ind, target - coins[ind],coins,dp);
        return dp[ind][target] = take + notTake;
    }

    int f_tabu(int target, vector<int>& coins){
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (target + 1,0));
        for(int T = 0;T <= target; T++) dp[0][T] = (T % coins[0] == 0);
        for(int ind = 1; ind < n; ind++){
            for(int T = 0; T <= target; T++){
                int notTake = dp[ind - 1][T];
                int take = 0;
                if(coins[ind] <= T) take = dp[ind][T - coins[ind]];
                dp[ind][T] = take + notTake;
            }
        }
        return dp[n - 1][target];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n,vector<int> (amount + 1,-1));
        return f_tabu(amount,coins);;
    }
};