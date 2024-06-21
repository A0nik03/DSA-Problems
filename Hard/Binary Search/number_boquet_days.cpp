// Minimum Number of Days to Make m Bouquets

/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>& bloomDay, int day, int m, int k) {

        int cnt = 0, boq = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                boq += (cnt / k);
                cnt = 0;
            }
        }
        boq += cnt / k;
        return boq >= m;
    }

    int brute(vector<int>& bloomDay, int m, int k) {
        int reqFlower = (long long)m * (long long)k;
        int n = bloomDay.size();
        if (reqFlower > n) {
            return -1;
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (auto it : bloomDay) {
            mini = min(mini, it);
            maxi = max(maxi, it);
        }

        for (int i = mini; i <= maxi; i++) {
            if (helper(bloomDay, i, m, k)) {
                return i;
            }
        }
        return -1;
    }

    int optimal(vector<int>& bloomDay, int m, int k) {
        long long reqFlower = (long long)m * (long long)k;
        int n = bloomDay.size();
        if (reqFlower > n) {
            return -1;
        }
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (auto it : bloomDay) {
            mini = min(mini, it);
            maxi = max(maxi, it);
        }

        int start = mini;
        int end = maxi;
        while(start <= end){
            int mid = start + (end - start)/2;
            if(helper(bloomDay,mid,m,k)){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
       return optimal(bloomDay,m,k);
    }
};