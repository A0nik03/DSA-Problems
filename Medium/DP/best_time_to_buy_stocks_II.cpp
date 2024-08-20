// 122. Best Time to Buy and Sell Stock II

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long f(int ind,int buy,vector<int>& prices){
        if(ind == prices.size()) return 0;

        long profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind + 1,0,prices),0 + f(ind + 1,1,prices));
        }
        else{
            profit = max(prices[ind] + f(ind + 1,1,prices),0 + f(ind + 1,0,prices));
        }
        return profit;
    }

    long f_memo(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp){
        if(ind == prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        long profit = 0;
        if(buy){
            profit = max(-prices[ind] + f_memo(ind + 1,0,prices,dp),0 + f_memo(ind + 1,1,prices,dp));
        }
        else{
            profit = max(prices[ind] + f_memo(ind + 1,1,prices,dp),0 + f_memo(ind + 1,0,prices,dp));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int> (2,-1));
        dp[n][1] = dp[n][0] = 0;
        for(int i = n - 1; i >= 0;i--){
            for(int buy = 0; buy <= 1;buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[i + 1][0],0 + dp[i + 1][1]);
                }
                else{
                    profit = max(prices[i] + dp[i + 1][1],0 + dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};