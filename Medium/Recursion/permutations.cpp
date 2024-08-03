// 46. Permutations

/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void permute(vector<int>& nums,vector<int>& freq,vector<vector<int>>& ds,vector<int>& ans){
        if(ans.size() == nums.size()){
            ds.push_back(ans);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(!freq[i]){
                ans.push_back(nums[i]);
                freq[i] = 1;
                permute(nums,freq,ds,ans);
                freq[i] = 0;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ds;
        vector<int> ans;
        vector<int> freq(nums.size(),0);
        permute(nums,freq,ds,ans);
        return ds;
    }
};