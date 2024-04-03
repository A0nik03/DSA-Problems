#include <iostream>
#include <vector>
using namespace std;

// Brute
vector<int> reverseArrayBru(int n, vector<int> &nums)
{
    vector<int> ans;
    int i = n - 1;
    while(i!=-1){
        ans.push_back(nums[i]);
        i--;
    }
    return ans;
}
// Time Complexity: O(n)
// Space Complexity: O(1)

// Better(Loop)
vector<int> reverseArrayBet(int n, vector<int> &nums)
{
    int i = 0;
    int j = n - 1;
    while(i < j){
        swap(nums[i++],nums[j--]);
    }
    return nums;
}
// Time Complexity: O(n)
// Space Complexity: O(1)

// Better(Recurssive)
void reverse(vector<int>& nums,int i,int j){
    if(i > j){
        return;
    }
    swap(nums[i],nums[j]);
    reverse(nums, i+1, j-1);
}
// Time Complexity: O(n)
// Space Complexity: O(1)

vector<int> reverseArray(int n, vector<int> &nums)
{
    int i = 0;
    int j = n - 1;
    reverse(nums, i,j);
    return nums;
}