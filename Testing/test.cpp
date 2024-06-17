#include <bits/stdc++.h>
using namespace std;

int brute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = 0,maxi = 0;

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i - 1] + 1 == nums[i]){
                cout<<nums[i - 1] + 1 << " == " <<nums[i]<<endl;
                len++;
                
                cout<<"Maxi In:"<<maxi<<endl;
                cout<<"Len: "<<len<<endl;
            }else{
                len = 0;
            }
        }
        cout<<"Maxi: "<<maxi<<endl;
        return maxi + 1;
    }

int main(){
    vector<int> arr = {0,3,7,2,5,8,4,6,0,1};
    return brute(arr);
}