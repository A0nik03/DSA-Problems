// Merge Intervals

/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

// Brute

    vector<vector<int>> brute_Merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            if (!ans.empty() && ans.back()[1] >= end) {
                continue;
            }
            int maxi = 0;
            for (int j = 0; j < intervals.size(); j++) {
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                } else {
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }

// Optimal - 1

    vector<vector<int>> optimal_Merge_One(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            if (ans.empty() || ans.back()[1] < intervals[i][0]) {
                ans.push_back(intervals[i]);
            } else {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }

// Optimal - 2

    vector<vector<int>> optimal_Merge_Two(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int a = intervals[0][0];
        int b = intervals[0][1];
        for(auto v: intervals){
            if(v[0] > b){
                ans.push_back({a,b});
                a = v[0];
                b = v[1];
            }
            else if(v[1] > b){
                b = v[1];
            }
        }
        ans.push_back({a,b});
        return ans;
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        return optimal_Merge_One(intervals);
    }
};