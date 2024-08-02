// 90. Subsets II

/*
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void find(vector<int>& nums,vector<vector<int>>& ds,vector<int> &arr,int ind){
        ds.push_back(arr);
        for(int i = ind; i < nums.size(); i++){
            if(i != ind && nums[i] == nums[i - 1]) continue;
            arr.push_back(nums[i]);
            find(nums,ds,arr,i + 1);
            arr.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ds;
        vector<int> arr;
        sort(nums.begin(),nums.end());
        find(nums,ds,arr,0);
        return ds;
    }
};