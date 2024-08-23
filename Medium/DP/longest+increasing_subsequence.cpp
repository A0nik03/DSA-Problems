// Longest Increasing Subsequence

/*
Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence.

A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the term that comes after it.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind, int prev, vector<int>& nums) {
        if (ind == nums.size())
            return 0;

        int len = 0 + f(ind + 1, prev, nums);
        if (prev == -1 || nums[prev] < nums[ind]) {
            len = max(len, 1 + f(ind + 1, ind, nums));
        }
        return len;
    }

    int f_memo(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size())
            return 0;
        if (dp[ind][prev] != -1)
            return dp[ind][prev];
        int len = 0 + f_memo(ind + 1, prev, nums, dp);
        if (prev == -1 || nums[prev] < nums[ind]) {
            len = max(len, 1 + f_memo(ind + 1, ind, nums, dp));
        }
        return dp[ind][prev] = len;
    }

    int f_tabu(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int len = 0 + dp[ind + 1][prev + 1];
                if (prev == -1 || nums[prev] < nums[ind]) {
                    len = max(len, 1 + dp[ind + 1][ind + 1]);
                }
                dp[ind][prev + 1] = len;
            }
        }
        return dp[0][0];
    }

    int f_tabu_opti(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n + 1, 0), curr(n + 1, 0);

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int len = 0 + next[prev + 1];
                if (prev == -1 || nums[prev] < nums[ind]) {
                    len = max(len, 1 + next[ind + 1]);
                }
                curr[prev + 1] = len;
            }
            next = curr;
        }
        return next[0];
    }

    int f_tabu_two(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[prev] < nums[ind]) {
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxi = max(maxi, dp[ind]);
        }
        return maxi;
    }
    // Using Binary Search 

    int longestSubsequence(int n, int nums[])
    {
         vector<int> temp;
          temp.push_back(nums[0]);
          int len = 1;
          for(int i = 1; i < n;i++){
            if(nums[i] > temp.back()){
              temp.push_back(nums[i]);
              len++;
            }
            else{
              int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
              temp[ind] = nums[i];
            }
          }
          return len;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // vector<vector<int>> dp(n + 1,vector<int> (n + 1,-1));
        return f_tabu_two(nums);
    }
};