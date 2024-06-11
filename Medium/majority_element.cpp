#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
private:
    int brute_loop(vector<int>& nums) {
        int ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] == nums[j]) {
                    cnt++;
                }
            }
            if (cnt > nums.size() / 2) {
                ans = nums[i];
            }
        }
        return ans;
    }

    int better_hash(vector<int>& nums) {
        int ans = -1;
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        for (auto it : mpp) {
            if (it.second > nums.size() / 2) {
                ans = it.first;
            }
        }
        return ans;
    }

    int optimal_moore_algo(vector<int>& nums) {
        int cnt = 0, el,ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0) {
                cnt = 1;
                el = nums[i];
            } else if (el == nums[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }
        int cnt1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] = el) {
                cnt1++;
            }
        }
        if (cnt1 > nums.size() / 2) {
            ans = el;
        }
        return ans;
    }

public:
    int majorityElement(vector<int>& nums) { return optimal_moore_algo(nums); }
};