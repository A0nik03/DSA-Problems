// Ques: Find the number that appears once, and other numbers twice.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int brute_Count(vector<int>& nums){
        int ans = -1;
        for(int i = 0; i < nums.size();i++){
            int cnt = 0;
            for(int j = 0;j < nums.size();j++){
                if(nums[i] == nums[j]){
                    cnt++;
                }
            }
            if(cnt == 1){
                ans = nums[i];
            }
        }
        return ans;
    }

    int better_hashing_array(vector<int>& nums){
        int maxi = nums[0];
        for(int i = 0; i < nums.size();i++){
            maxi = max(maxi,nums[i]);
        }
        vector<int> hash(maxi+1,0);
        for(int i = 0;i<nums.size();i++){
            hash[nums[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < hash.size();i++){
            if(hash[i] == 1){
                ans = i;
            }
        }
        return ans;
    }

    int better_hashing_map(vector<int>& nums){
        map<long long,int> mpp;
        for(int i = 0;i<nums.size();i++){
           mpp[nums[i]]++;
        }
        int ans = 0;
        for(auto it:mpp){
            if(it.second == 1){
                ans = it.first;
            }
        }
        return ans;
    }

    int optimal_Xor(vector<int>& nums){
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
public:
    int singleNumber(vector<int>& nums) {
        return optimal_Xor(nums);
    }
};