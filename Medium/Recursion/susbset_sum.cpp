// Subset Sum

/*
You are given an array 'A' of 'N' integers. You have to return true if there exists a subset of elements of 'A' that sums up to 'K'. Otherwise, return false.
*/
#include <bits/stdc++.h>
using namespace std;

bool f(vector<int>& arr,int n,int k,int ind,int sum){
    if(ind >= n){
        return sum == k;
    }

    if(sum <= k){
        sum += arr[ind];
        if(f(arr,n,k,ind+1,sum) == true) return true;
        sum -= arr[ind];
    }
    
    return f(arr,n,k,ind+1,sum);

}
bool isSubsetPresent(int n, int k, vector<int> &a)
{
 int sum = 0;
 return f(a,n,k,0,sum);   
}