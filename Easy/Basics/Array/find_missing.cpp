// Ques: Find Missing Number
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int brute(vector<int>& nums) {
        int ans = -1;
        for (int i = 1; i <= nums.size(); i++) {
            int flag = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                ans = i;
            }
        }
        return ans;
    }

    int betterHash(vector<int>& nums){
        int ans = 0;
        vector<int> hash(nums.size()+1,0);
        for(int i = 0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        for(int i = 1;i < nums.size()+1;i++){
            if(hash[i] == 0){
                ans = i;
            }
        }
        return ans;
    }

    int optimalOne_sum(vector<int>& nums){
        int n = nums.size() + 1;
        int total_sum = (n)*(n-1)/2;
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
        }
        return total_sum - sum;
    }

    int optimalTwo_Xor(vector<int>& nums){
        int xor1 = 0,xor2 = 0;
        for(int i = 0;i<nums.size();i++){
            xor1 = xor1 ^ (i+1);
            xor2 = xor2 ^ nums[i];
        }
        return xor1 ^ xor2;
    }

    int optimal_Three_Binary(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int left = 0,right = n;
        int mid = left + (right - left)/2;
        while(left < right){
            if(nums[mid] > mid){
                right = mid;
            }
            else{
                left = mid + 1;
            }
            mid = left + (right - left)/2;
        }
        return left;
    }


public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return optimalTwo_Xor(nums);
    }
};