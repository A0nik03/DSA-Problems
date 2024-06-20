// Find Minimum in Rotated Sorted Array

/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int Binary_One(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mini = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= mini) {
                mini = nums[mid];
            }

            if (nums[low] < nums[mid] && nums[low] < nums[high]) {
                high = mid - 1;
            } else if(nums[mid] > nums[high] && nums[high] < nums[low]) {
                low = mid + 1;
            }
            else{
                low++;
                high--;
            }
        }
        return mini;
    }

     int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int mini = INT_MAX;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[low] <= nums[mid]){
                mini = min(mini,nums[low]);
                low = mid + 1;
            }
            else{
                mini = min(mini,nums[mid]);
                high = mid - 1;
            }
        }
        return mini;
    }
};