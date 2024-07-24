// 198. House Robber

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve_s(vector<int> &nums,int n){
    int prev = nums[0];
    int prev2 = 0;

    for(int i = 1; i < n; i++){
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = prev;

        int curr = max(take,notTake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

    int rob(vector<int>& nums) {
        return solve_s(nums,nums.size());
    }
};