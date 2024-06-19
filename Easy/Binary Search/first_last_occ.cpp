// Find First and Last Position of Element in Sorted Array

/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/ 
#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // Brute
    vector<int> brute(vector<int>& nums, int target) {
        int first = -1;
        int last = -1;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] == target){
                if(first == -1){
                    first = i;
                }
                last = i;
            }
        }
        return {first,last};
    }

    //Better 
    int lower_bound(vector<int>& nums, int target){
        int first = nums.size();
        int start = 0;
        int end = nums.size() - 1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid] >= target){
                first = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return first;
    }

    int upper_bound(vector<int>& nums, int target){
        int last = nums.size();
        int start = 0;
        int end = nums.size() - 1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid] > target){
                last = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return last;
    }

    vector<int> better(vector<int>& nums, int target) {
        int lb = lower_bound(nums,target);
        if(lb == nums.size() || nums[lb] != target){
            return {-1,-1};
        }

        return {lb,upper_bound(nums,target) - 1};
        
    }

    // Optimal
    
    int first_Occ(vector<int>& nums, int target){
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans = mid;
                end = mid - 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }

    int last_Occ(vector<int>& nums, int target){
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                ans = mid;
                start = mid + 1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return ans;
    }
    

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(first_Occ(nums,target) == -1)
        {
            return {-1,-1};
        }
        return {first_Occ(nums,target),last_Occ(nums,target)};
    }
};