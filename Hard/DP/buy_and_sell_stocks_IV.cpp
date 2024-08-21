// 188. Best Time to Buy and Sell Stock IV

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind,int tranNo,vector<int>& prices,int n,int k){
        if(ind == n || tranNo == 2*k) return 0;

        if(tranNo % 2 == 0){
            return max(-prices[ind] + f(ind + 1,tranNo + 1,prices,n,k),0 + f(ind + 1,tranNo,prices,n,k));
        }
        return max(prices[ind] + f(ind + 1,tranNo + 1,prices,n,k),0 + f(ind + 1,tranNo,prices,n,k));
    }

    int f_memo(int ind,int tranNo,vector<int>& prices,int n,int k,vector<vector<int>> &dp){
        if(ind == n || tranNo == 2*k) return 0;
        if(dp[ind][tranNo] != -1) return dp[ind][tranNo];
        
        if(tranNo % 2 == 0){
            return dp[ind][tranNo] = max(-prices[ind] + f_memo(ind + 1,tranNo + 1,prices,n,k,dp),0 + f_memo(ind + 1,tranNo,prices,n,k,dp));
        }
        return dp[ind][tranNo] = max(prices[ind] + f_memo(ind + 1,tranNo + 1,prices,n,k,dp),0 + f_memo(ind + 1,tranNo,prices,n,k,dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n  + 1,vector<int> (2*k  + 1,0));
        for(int ind = n - 1; ind >= 0; ind--){
            for(int trans = 2*k - 1; trans >= 0;trans--){
                if(trans % 2 == 0){
                    dp[ind][trans] = max(-prices[ind] + dp[ind + 1][trans + 1],0 + dp[ind + 1][trans]);
                }
                else dp[ind][trans] = max(prices[ind] + dp[ind + 1][trans + 1],0 + dp[ind + 1][trans]);
            }
        }
        return dp[0][0];        
    }
};