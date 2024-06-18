// Binary Search

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
// While Loop
    int while_BS(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid = low + (high - low) / 2;
        while (low <= high) {
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            mid = low + (high - low) / 2;
        }
        return -1;
    }
// Reccursion
    int recc_BS(vector<int>& nums, int low, int high, int target) {
        int mid = low + (high - low) / 2;
        if (low > high) {
            return -1;
        }
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return recc_BS(nums, mid + 1, high, target);
        } else {
            return recc_BS(nums, low, mid - 1, target);
        }
    }

public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        return recc_BS(nums, low, high, target);
    }
};