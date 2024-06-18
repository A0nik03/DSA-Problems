#include <bits/stdc++.h>
using namespace std;

// Variety - 1(positive and negative are same)
class Solution {
private: 
    vector<int> brute(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(int i = 0; i < nums.size();i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }
            else{
                neg.push_back(nums[i]);
            }
        }
        for(int i = 0; i < nums.size()/2;i++){
            nums[2*i] = pos[i];
            nums[2*i + 1] = neg[i];
        }
        return nums;
    }

    vector<int> optimal(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int posIndex = 0,negIndex = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
            else{
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;        
    }
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    return optimal(nums);    
    }

// Variety - 2 (Positive Number != Negative Numbers)

void rearrange(vector<int> &arr)
{
	vector<int> pos;
	vector<int> neg;
	for(int i = 0;i<arr.size();i++){
		if(arr[i] < 0){
			neg.push_back(arr[i]);
		}
		else{
			pos.push_back(arr[i]);
		}
	}

	if(pos.size() > neg.size()){
		for(int i = 0; i < neg.size();i++){
			arr[2*i+1] = neg[i];
			arr[2*i] = pos[i];
		}
		int index = 2 * neg.size();
		for(int i = neg.size();i < pos.size();i++){
			arr[index] = pos[i];
			index++;
		}
	}
	else{
		for(int i = 0; i < pos.size();i++){
			arr[2*i+1] = neg[i];
			arr[2*i] = pos[i];
		}
		int index = 2 * pos.size();
		for(int i = pos.size();i < neg.size();i++){
			arr[index] = neg[i];
			index++;
		}
	}
}

};