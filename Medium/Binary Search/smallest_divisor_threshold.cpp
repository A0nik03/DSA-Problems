// 1283. Find the Smallest Divisor Given a Threshold

/*
Given an array of integers nums and an integer threshold, we will choose a positive integer divisor, divide all the array by it, and sum the division's result. Find the smallest divisor such that the result mentioned above is less than or equal to threshold.

Each result of the division is rounded to the nearest integer greater than or equal to that element. (For example: 7/3 = 3 and 10/2 = 5).

The test cases are generated so that there will be an answer.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Brute
    int possible(vector<int>& nums,long long number) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)nums[i] / (double)number);
        }
        return (int)sum;
    }

    int brute(vector<int>& nums, int threshold) {

        int mini = INT_MAX, maxi = INT_MIN;
        for (auto it : nums) {
            mini = min(mini, it);
            maxi = max(maxi, it);
        }

        for (int i = mini; i <= maxi; i++) {
            if (possible(nums, i) == true) {
                return i;
            }
        }
        return -1;
    }

    // Optimal
    int optimal(vector<int>& nums, int threshold) {

        int mini = INT_MAX, maxi = INT_MIN;
        if (nums.size() > threshold) {
            return -1;
        }
        for (auto it : nums) {
            mini = min(mini, it);
            maxi = max(maxi, it);
        }

        long long low = 1;
        long long high = maxi;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (possible(nums, mid) <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        return optimal(nums, threshold);
    }
};

