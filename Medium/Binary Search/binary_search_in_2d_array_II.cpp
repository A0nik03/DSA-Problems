// 74. Search a 2D Matrix

/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bs(vector<int> nums, int target){
        int low = 0;
        int high = nums.size() - 1;
    
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }


    bool brute_SearchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans = false;
        int m = matrix[0].size();
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] <= target && target <= matrix[i][m - 1] ){
                return bs(matrix[i],target);
            }
        }
        return false;
    }

    // Optimal

    bool Optimal_SearchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() * matrix[0].size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            int row = mid/matrix[0].size();
            int col = mid % matrix[0].size();

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return Optimal_SearchMatrix(matrix,target);
    }
};