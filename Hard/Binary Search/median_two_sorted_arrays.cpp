// Median of Two Sorted Arrays

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

private:
    // Brute

    double Brute_findMedianSortedArrays(vector<int>& nums1,
                                        vector<int>& nums2) {
        vector<int> arr;
        int n1 = nums1.size(), n2 = nums2.size();
        int left = 0, right = 0;

        while (left < n1 && right < n2) {
            if (nums1[left] < nums2[right]) {
                arr.push_back(nums1[left++]);
            } else {
                arr.push_back(nums2[right++]);
            }
        }

        while (left < n1) {
            arr.push_back(nums1[left++]);
        }

        while (right < n2) {
            arr.push_back(nums2[right++]);
        }

        if ((n1 + n2) % 2 == 1) {
            return (double)arr[(n1 + n2) / 2];
        } else {
            return ((double)(arr[(n1 + n2) / 2] + arr[(n1 + n2) / 2 - 1])) /
                   2.0;
        }

        return 0;
    }

    // Better

    double Better_findMedianSortedArrays(vector<int>& nums1,
                                         vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int left = 0, right = 0;

        int n = n1 + n1 + 1;

        int cnt = 0;
        int ind1 = n / 2;
        int ind2 = ind1 - 1;
        int el1 = -1, el2 = -1;

        while (left < n1 && right < n2) {
            if (nums1[left] < nums2[right]) {
                if (cnt == ind1)
                    el1 = nums1[left];
                if (cnt == ind2)
                    el2 = nums1[left];
                cnt++;
                left++;
            } else {
                if (cnt == ind1)
                    el1 = nums2[right];
                if (cnt == ind2)
                    el2 = nums2[right];
                cnt++;
                right++;
            }
        }

        while (left < n1) {
            if (cnt == ind1)
                el1 = nums1[left];
            if (cnt == ind2)
                el2 = nums1[left];
            cnt++;
            left++;
        }

        while (right < n2) {
            if (cnt == ind1)
                el1 = nums2[right];
            if (cnt == ind2)
                el2 = nums2[right];
            cnt++;
            right++;
        }

        if (n % 2 == 1) {
            return (double)el2;
        } else {
            return (double)((double)(el1 + el2)) / 2.0;
        }
    }

public:
    // Optimal

    double Optimal_findMedianSortedArrays(vector<int>& nums1,
                                          vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = n1 + n2;
        int left = (n1 + n2 + 1) / 2;

        int low = 0, high = n1;
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;

            if (mid1 < n1)
                r1 = nums1[mid1];
            if (mid2 < n2)
                r2 = nums2[mid2];
            if (mid1 - 1 >= 0)
                l1 = nums1[mid1 - 1];
            if (mid2 - 1 >= 0)
                l2 = nums2[mid2 - 1];

            if (l1 <= r2 && l2 <= r1) {
                if (n % 2 == 1)
                    return max(l1, l2);
                else
                    return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }

            else if (l1 > r2)
                high = mid1 - 1;
            else
                low = mid1 + 1;
        }
        return 0;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return Better_findMedianSortedArrays(nums1, nums2);
    }
};