// 78. Subsets

/*
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(vector<int> &nums,int ind, vector<int> per, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(per);
            return;
        }
        per.push_back(nums[ind]);
        solve(nums, ind + 1, per, ans);
        per.pop_back();
        solve(nums, ind + 1, per, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> per;
        solve(nums,0,per,ans);
        return ans;
    }
};