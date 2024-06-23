// Split Array Largest Sum

/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    bool isPossible(vector<int>& nums, int k,int mid){
        int division = 1;
        int maxSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(maxSum + nums[i] <= mid){
                maxSum+=nums[i];
            }
            else{
                division++;
                if(division > k){
                    return false;
                }
                else{
                    maxSum = nums[i];
                }
            }
        }
        return true;
    } 
public:
    int splitArray(vector<int>& nums, int k) {
        if(k > nums.size()){
            return -1;
        }
        int maxi = INT_MIN,sum = 0;
        for(auto it : nums){
            sum += it;
            maxi = max(maxi,it);
        }

        int start = maxi;
        int end = sum;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(isPossible(nums,k,mid)){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};