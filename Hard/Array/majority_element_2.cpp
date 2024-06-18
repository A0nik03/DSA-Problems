#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> brute(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (ans.size() == 0 || nums[i] != ans[0]) {
                int cnt = 0;
                for (int j = 0; j < nums.size(); j++) {
                    if (nums[i] == nums[j]) {
                        cnt++;
                    }
                }
                if (cnt > nums.size() / 3) {
                    ans.push_back(nums[i]);
                }
            }
        }
        return ans;
    }

    vector<int> better_Hash_One(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        for (auto it : mpp) {
            if (it.second > nums.size() / 3) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }

    vector<int> better_Hash_Two(vector<int>& nums) {
        vector<int> ans;
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
            if (mpp[nums[i]] == (int)nums.size() / 3 + 1) {
                ans.push_back(nums[i]);
            }

            if (ans.size() == 2) {
                break;
            }
        }
        return ans;
    }

    vector<int> optimal_Moore_Algo(vector<int>& nums) {

        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1 = 1;
                el1 = nums[i];
            } else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2 = 1;
                el2 = nums[i];
            } else if (el1 == nums[i]) {
                cnt1++;
            } else if (el2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (el1 == nums[i])
                cnt1++;
            if (el2 == nums[i])
                cnt2++;
        }

        int mini = (int)(nums.size() / 3) + 1;
        if (cnt1 >= mini)
            ans.push_back(el1);
        if (cnt2 >= mini)
            ans.push_back(el2);
        sort(ans.begin(), ans.end());
        return ans;
    }

public:
    vector<int> majorityElement(vector<int>& nums) {
        return optimal_Moore_Algo(nums);
    }
};