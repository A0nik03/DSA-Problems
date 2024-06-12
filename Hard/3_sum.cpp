#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Brute Force
    vector<vector<int>> brute_loop(vector<int>& nums) {

        set<vector<int>> st;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
    // Better(Hashing)
    vector<vector<int>> better_HashSet(vector<int>& nums) {

        set<vector<int>> st;

        for (int i = 0; i < nums.size(); i++) {
            set<int> hashSet;
            for (int j = i + 1; j < nums.size(); j++) {
                int third = -1 * (nums[i] + nums[j]);
                if (hashSet.find(third) != hashSet.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashSet.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
    // Optimal (Two Pointer)

    vector<vector<int>> optimal_Two_Point(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i - 1] == nums[i])
                continue;

            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j - 1] == nums[j])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return optimal_Two_Point(nums);
    }
};