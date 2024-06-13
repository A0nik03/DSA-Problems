#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

// Brute Force(Takes Extra space)

    void brute(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int temp[n + m];
        int i = 0,j = 0,index = 0;
        while(i < m && j < m){
            if(nums1[i] <= nums2[j]){
                temp[index++] = nums1[i];
                i++;
            }
            else{
                temp[index++] = nums2[j];
                j++;
            }
        }
        while(i < m){
            temp[index++] = nums1[i++];
        }
        while(j < n){
            temp[index++] = nums2[j++];
        }
        for(int i = 0; i < n+m;i++){
            if(i < n){
                nums1[i] = temp[i];
            }
            else{
                nums2[i - m] = temp[i];
            }
        }
    }

// Optimal - 1 (Sort both Arrays)

    void optimal_One(vector<int>& nums1, int n, vector<int>& nums2, int m){
        int i = n - 1,j = 0;
        while(i >= 0 && j < m){
            if(nums1[i] > nums2[j]){
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
    }

// Optimal - 2 (Uses 3rd Variable to merge both arrays in one)

    void optimal_Two(vector<int>& nums1, int n, vector<int>& nums2, int m){
        int i = n - 1,j = m - 1,k = n + m - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]){
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }

        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }

// Optimal - Three (Gap Method) 
    void SwapIfGreater(vector<int>& nums1, vector<int>& nums2, int ind1,int ind2){
        if(nums1[ind1] > nums2[ind2]){
            swap(nums1[ind1],nums2[ind2]);
        }
    }

    void optimal_Three(vector<int>& nums1, int n, vector<int>& nums2, int m){
        int len = n + m;
        int gap = len/2 + len%2;
        while(gap > 0){
            int left = 0;
            int right = left + gap;
            while(right < len){
                if(left < n && right >= n){
                    SwapIfGreater(nums1,nums2,left,right - n);
                }
                else if(left >= n){
                    SwapIfGreater(nums1,nums2,left - n,right - n);
                }
                else{
                    SwapIfGreater(nums1,nums2,left,right);
                }
            }
        }
    }


public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        return optimal_Two(nums1,m,nums2,n);
    }
};