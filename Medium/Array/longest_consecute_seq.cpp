#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Brute Force
    bool linear_search(vector<int>& nums, int key) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == key) {
                return true;
            }
        }
        return false;
    }

    int brute(vector<int>& nums) {
        int longest = 0;
        for (int i = 0; i < nums.size(); i++) {
            int cnt = 1, x = nums[i];
            while (linear_search(nums, x + 1) == true) {
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
        return longest;
    }

    // Better Solution
    int better(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int longest = 1, cnt = 0, last_smaller = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - 1 == last_smaller) {
                cnt++;
                last_smaller = nums[i];
            } else if (nums[i] != last_smaller) {
                cnt = 1;
                last_smaller = nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }

    // Optimal Solution
    int optimal(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int longest = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    x = x + 1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }

public:
    int longestConsecutive(vector<int>& nums) { return optimal(nums); }
};