//  Maximum Product Subarray

/* 
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
private: 

// Brute (Loops - O(n^3)) 

    int brute_Loops(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                int prod = 1;
                for(int k = i; k <= j; k++){
                    prod *= nums[k];
                    maxi = max(maxi,prod);
                }
            }
        }
        return maxi;
    }

// Better (Loops - O(n^2)) 

    int better_Loops(vector<int> &nums){
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int prod = 1;
            for(int j = i; j < nums.size(); j++){
                prod *= nums[j];
                maxi = max(maxi,prod);
            }
        }
        return maxi;
    }

// Optimal (Intution - O(n)) 

        int optimal_Intut(vector<int>&nums){
        double maxi = INT_MIN;
        double prefix = 1,suffix = 1;
        for(int i = 0; i < nums.size(); i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[nums.size() - i - 1];
            maxi = max(maxi,max(prefix,suffix));
        }
        return (int)maxi;
    }

public:
    int maxProduct(vector<int>& nums) {
        return optimal_Intut(nums);
    }
};