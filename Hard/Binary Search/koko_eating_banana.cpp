// Koko Eating Bananas


/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long timeEatPile(vector<int> & piles,int mid){
        long long time = 0;
        for(int i = 0; i < piles.size();i++){
            int el = ceil((double)piles[i] / (double)mid);
            time = time + el;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for(int i = 0; i < piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        long start = 1;
        long end = maxi;
       
        while(start <= end){
            long mid = start + (end - start)/2;
            long time = timeEatPile(piles,mid);
            if(time <= h){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};