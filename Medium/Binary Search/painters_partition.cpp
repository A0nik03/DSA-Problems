//  Painter's Partition Problem

/*
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.



You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that any painter will only paint the continuous sections of boards.


*/


#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &boards, int k,int mid){
    int painters = 1;
    int time = 0;
    for(int i = 0 ; i < boards.size(); i++){
        if(time + boards[i] <= mid){
            time += boards[i];
        }
        else{
            painters++;
            if(painters > k){
                return false;
            }
            else{
                time = boards[i];
            }
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int sum = 0,maxi = -1;
    for(auto it: boards){
        sum += it;
        maxi = max(maxi,it);
    }
    int start = maxi;
    int end = sum;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(isPossible(boards,k,mid)){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return start;
}