/*

Ques: Move Zeroes:

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
*/

#include <iostream>
#include <vector>
using namespace std;


// Brute
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> arr;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] != 0){
                arr.push_back(nums[i]);
            }
        }
        for(int i = 0;i<nums.size()-1;i++){
            nums[i] = arr[i];
        }
        for(int i = arr.size();i<nums.size();i++){
            nums[i] = 0;
        }

    }
};

// Optimal
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }
        if (j == -1)
            return;
        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};