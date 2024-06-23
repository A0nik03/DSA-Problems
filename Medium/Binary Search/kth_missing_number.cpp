// 1539. Kth Missing Positive Number

/*
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.

Return the kth positive integer that is missing from this arr
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    int Brute01(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());
        int cnt = 0;

        for (int i = 1; i <= maxi + k; i++) {
            bool found = false;
            for (int j = 0; j < arr.size(); j++) {
                if (arr[j] == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cnt++;
                if (cnt == k) {
                    return i;
                }
            }
        }
        return -1;
    }

    int Brute02(vector<int>& arr, int k) {
        int maxi = *max_element(arr.begin(), arr.end());

        vector<int> map(10001, 0);

        for (int i = 0; i < arr.size(); i++) {
            map[arr[i] + 0]++;
        }

        int x, cnt = 0;

        for (int i = 1; i < 10001; i++) {
            if (map[i] == 0) {
                cnt++;
            }

            if (cnt == k) {
                x = i;
                break;
            }
        }
        return x;
    }

    int Better(vector<int>& arr, int k) {

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= k) {
                k++;
            } else {
                break;
            }
        }
        return k;
    }

    int Optimal(vector<int>& arr, int k) {

        int low = 0, high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high + k + 1;
    }

    public:
        int findKthPositive(vector<int> & arr, int k) {
            return Optimal(arr, k);
        }
    };