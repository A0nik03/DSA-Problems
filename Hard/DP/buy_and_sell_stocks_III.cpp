// 123. Best Time to Buy and Sell Stock III

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind,int buy,int cap,vector<int>& prices,int n){
        if(cap == 0) return 0;
        if(ind == n) return 0;

        if(buy){
            return max(-prices[ind] + f(ind + 1,0,cap,prices,n),0 + f(ind + 1,1,cap,prices,n));
        }  
        return max(prices[ind] + f(ind + 1,1,cap - 1,prices,n),0 + f(ind + 1,0,cap,prices,n));
    }

    int f_memo(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>> &dp){
        if(cap == 0) return 0;
        if(ind == n) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy){
            return dp[ind][buy][cap] = max(-prices[ind] + f_memo(ind + 1,0,cap,prices,n,dp),0 + f_memo(ind + 1,1,cap,prices,n,dp));
        }  
        return dp[ind][buy][cap] = max(prices[ind] + f_memo(ind + 1,1,cap - 1,prices,n,dp),0 + f_memo(ind + 1,0,cap,prices,n,dp));
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>> (2,vector<int> (3,0)));

        for(int ind = n - 1; ind >= 0;ind--){
            for(int buy = 0; buy <= 1;buy++){
                for(int cap = 1; cap <= 2;cap++){
                    if(buy){
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap],0 + dp[ind + 1][1][cap]);
                    }  
                    else dp[ind][buy][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],0 + dp[ind + 1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
};