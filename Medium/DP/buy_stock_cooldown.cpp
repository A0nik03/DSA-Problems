// 309. Best Time to Buy and Sell Stock with Cooldown

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long f(int ind,int buy,vector<int>& prices){
        if(ind >= prices.size()) return 0;

        long profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind + 1,0,prices),0 + f(ind + 1,1,prices));
        }
        else{
            profit = max(prices[ind] + f(ind + 2,1,prices),0 + f(ind + 1,0,prices));
        }
        return profit;
    }

    long f_memo(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp){
        if(ind >= prices.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        long profit = 0;
        if(buy == 1){
            profit = max(-prices[ind] + f_memo(ind + 1,0,prices,dp),0 + f_memo(ind + 1,1,prices,dp));
        }
        else{
            profit = max(prices[ind] + f_memo(ind + 2,1,prices,dp),0 + f_memo(ind + 1,0,prices,dp));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2,vector<int> (2,0));

        for(int i = n - 1; i >= 0;i--){
            for(int buy = 0; buy <= 1;buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[i + 1][0],0 + dp[i + 1][1]);
                }
                else{
                    profit = max(prices[i] + dp[i + 2][1],0 + dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};