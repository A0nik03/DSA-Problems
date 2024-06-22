// Capacity To Ship Packages Within D Days

/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    int possibleDays(vector<int>& weights, int capacity) {
        int sum = 0, day = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] > capacity) {
                sum = weights[i];
                day++;
            } else {
                sum += weights[i];
            }
        }
        return day;
    }

    int Brute(vector<int>& weights, int days) {

        int maxi = *max_element(weights.begin(), weights.end());
        long long totalWeight = accumulate(weights.begin(), weights.end(), 0);

        int start = maxi;
        int end = totalWeight;
        for (int i = maxi; i <= totalWeight; i++) {
            if (possibleDays(weights, i) <= days) {
                return i;
            }
        }
        return -1;
    }

    int Optimal(vector<int>& weights, int days) {

        int maxi = *max_element(weights.begin(), weights.end());
        long long totalWeight = accumulate(weights.begin(), weights.end(), 0);


        int start = maxi;
        int end = totalWeight;
        while(start <= end){
            int mid = start + (end - start)/2;
            if (possibleDays(weights, mid) <= days) {
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {

        return Optimal(weights,days);
    }
};