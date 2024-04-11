
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

// Hashing using Vector
vector<int> countFrequency(int n, int x, vector<int> &nums){
    vector<int> hash(n,0);
    for(int i = 0;i<n;i++){
        if(nums[i] >= 1 && nums[i] <= x){
            // Subtracting bcz we want to store value from 0th Index
            hash[nums[i] - 1]+=1;
        }
    }
return hash;
}

// Hashing using map

vector<int> countFrequency(int n, int x, vector<int> &nums){
    map<int,int> mpp;
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(nums[i] >= 1 && nums[i] <=x){
            mpp[nums[i]]++;
        }
    }
    for(int i = 1;i<=n;i++){
        ans.push_back(mpp[i]);
    }
    return ans;
}

// Hashing using unordered_map


vector<int> countFrequency(int n, int x, vector<int> &nums){
    unordered_map<int,int> mpp;
    vector<int> ans;
    for(int i = 0;i<n;i++){
        if(nums[i] >= 1 && nums[i] <=x){
            mpp[nums[i]]++;
        }
    }
    for(int i = 1;i<=n;i++){
        ans.push_back(mpp[i]);
    }
    return ans;
}