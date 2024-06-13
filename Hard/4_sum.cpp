#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

// Brute (Loops)
    vector<vector<int>> brute_Loop(vector<int>& nums, int target) {
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    for (int l = k + 1; l < nums.size(); l++) {
                        long long sum = nums[i] + nums[j];
                        sum += nums[k];
                        sum += nums[l];

                        if (sum == target) {
                            vector<int> temp = {nums[i], nums[j], nums[k],
                                                nums[l]};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

// Better (Hashing)
    vector<vector<int>> better_HashSet(vector<int>& nums, int target) {
        set<vector<int>> st;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                set<long long> hashSet;
                for (int k = j + 1; k < nums.size(); k++) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    long long fourth = target - sum;
                    if (hashSet.find(fourth) != hashSet.end()) {
                        vector<int> temp = {nums[i], nums[j], nums[k],
                                            (int)fourth};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                    hashSet.insert(nums[k]);
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

// Optimal (Two Pointer)
    vector<vector<int>> optimal_Two_Point(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j != i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l) {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if (sum == target) {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k - 1] == nums[k])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    } else if (sum < 0) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return optimal_Two_Point(nums, target);
    }
};