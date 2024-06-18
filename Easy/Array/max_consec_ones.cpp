// Max Consecutive Ones
/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0,maxi = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != 0){
                cnt++;
                maxi = max(maxi,cnt);
            }
            else{
                cnt = 0;
            }
        }
        return maxi;
    }
};