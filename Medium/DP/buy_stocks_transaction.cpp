//714. Best Time to Buy and Sell Stock with Transaction Fee

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1,vector<int> (2,0));

        for(int i = n - 1; i >= 0;i--){
            for(int buy = 0; buy <= 1;buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[i] + dp[i + 1][0],0 + dp[i + 1][1]);
                }
                else{
                    profit = max(prices[i] - fee + dp[i + 1][1],0 + dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};