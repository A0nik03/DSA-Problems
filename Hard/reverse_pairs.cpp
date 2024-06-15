// Reverse Pairs

/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

-> 0 <= i < j < nums.length and
-> nums[i] > 2 * nums[j].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Brute - (Loops)
    int brute_Loops(vector<int>&a, int n) {
    // Count the number of pairs:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > 2 * a[j]) cnt++;
        }
    }
    return cnt;
}

    // Optimal - (Merge Sort)

    void count_Pairs(vector<int> & nums,int low, int high, int mid,long long &cnt){
        int right = mid + 1;
        for(int i = low; i <= mid;i++){
            while(right <= high && nums[i] > 2 * (long long)nums[right]){
                right++;
            }
            cnt += right - (mid + 1);
        }
    }

    void merge(vector<int> & nums,int low, int high,int mid,long long &cnt){
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Count
        count_Pairs(nums,low,high,mid,cnt);

        while(left <= mid && right <= high){
            if(nums[left] <= nums[right]){
                temp.push_back(nums[left++]);
            }else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid){
            temp.push_back(nums[left++]);
        }
        while(right<=high){
            temp.push_back(nums[right++]);
        }

        for(int i = low; i <= high;i++){
            nums[i] = temp[i - low];
        }
    } 

    void merge_Sort(vector<int> & nums,int low, int high,long long &cnt){
        if(low>=high){
            return;
        }
        int mid = low + (high - low)/2;
        // Left
        merge_Sort(nums,low,mid,cnt);
        // Right
        merge_Sort(nums,mid + 1,high,cnt);
        // Merge
        merge(nums,low,high,mid,cnt);

    }
public:
    int reversePairs(vector<int>& nums) {
        long long cnt = 0;
        merge_Sort(nums,0,nums.size() - 1,cnt);
        return cnt;
    }
};