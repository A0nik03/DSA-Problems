#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int brute(vector<int>& A, int K) {
        int cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A.size(); j++) {
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum += A[k];
                }
                if (sum == K) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int better(vector<int>& A, int K) {
        int cnt = 0;
        for (int i = 0; i < A.size(); i++) {
            int sum = 0;
            for (int j = i; j < A.size(); j++) {
                sum += A[j];
                if (sum == K) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int optimal_map(vector<int>& A, int K) {
        map<int,int> mpp;
        mpp[0] = 1;
        int preSum = 0,cnt = 0;
        for(int i = 0 ; i < A.size(); i++){
            preSum += A[i];
            int remaining = preSum - K;
            cnt += mpp[remaining];
            mpp[preSum] += 1;
        }
        return cnt;
    }

public:
    int subarraySum(vector<int>& A, int K) { return optimal_map(A, K); }
};