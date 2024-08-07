// 2588. Count the Number of Beautiful Subarrays

/*
You are given a 0-indexed integer array nums. In one operation, you can:

Choose two different indices i and j such that 0 <= i, j < nums.length.
Choose a non-negative integer k such that the kth bit (0-indexed) in the binary representation of nums[i] and nums[j] is 1.
Subtract 2k from nums[i] and nums[j].
A subarray is beautiful if it is possible to make all of its elements equal to 0 after applying the above operation any number of times.

Return the number of beautiful subarrays in the array nums.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& arr) {
    long long count = 0;
    unordered_map<int, int> freq;
    int xorr = 0;
    freq[xorr]++; // Initialize with 0 to handle cases where prefix itself is the target
    int target = 0;
    for(int i = 0; i < arr.size(); i++){
        xorr = xorr ^ arr[i];
        int rem = target ^ xorr;

        if (freq.find(rem) != freq.end()) {
            count += freq[rem];
        }
        
        freq[xorr]++;
    }
    
    return count;
    }
};