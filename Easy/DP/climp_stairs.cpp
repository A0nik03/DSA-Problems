// 70. Climbing Stairs

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long int stairs(int n) {
    long long int prev1 = 1;
    long long int prev2 = 1;
    for(int i = 2; i <= n; i++){
        int curri = (prev1 + prev2);
        prev2 = prev1;
        prev1 = curri;
    }
    return prev1;
    }
    int climbStairs(int n) {
        return stairs(n);
    }
};