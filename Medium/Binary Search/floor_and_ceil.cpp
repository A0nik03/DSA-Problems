// Ceil The Floor

/*
You're given a sorted array 'a' of 'n' integers and an integer 'x'.

Find the floor and ceiling of 'x' in 'a[0..n-1]'.

Note:
Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.
*/

#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
    int floor = -1,ceil = -1;
    int start = 0,end = n - 1;
    
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == x){
            return {arr[mid],arr[mid]};
        }
        
        if(arr[mid] < x){
            floor = arr[mid];
            start = mid + 1;
        }
        else{
            ceil = arr[mid];
            end = mid - 1;
        }
        
    }
    return {floor,ceil};
}