// 322. Coin Change

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
    vector<vector<int>> dp(n,vector<int> (amount+1,0));
    for(int T = 0 ; T <= amount; T++){
        if(T % coins[0] == 0) dp[0][T] = T/coins[0];
        else dp[0][T] = 1e9;
    }
    for(int ind = 1; ind < n;ind++){
        for(int T = 0; T <= amount; T++){
            int notTake = 0 + dp[ind - 1][T];
            int Take = INT_MAX;
            if(coins[ind] <= T) Take = 1 + dp[ind][T - coins[ind]];
            dp[ind][T] = min(Take , notTake);
        }
    }
    int ans = dp[n - 1][amount];
    if(ans >= 1e9) return -1;
    return ans;
    }
};