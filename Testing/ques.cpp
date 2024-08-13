#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        int cnt = 1;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1] + 1){
                cnt++;
            }
            else{
                maxi = max(maxi,cnt);  
                cnt = 1;
            }
            cout<<cnt<<endl;
        }
        return maxi;
    }

int main()
{
    // string s = "Nikhil";
    // int c = 'a';
    // cout<<(char)(c + 8)<<endl;
    cout<<lengthOfLongestSubstring("abcabcbb")<<endl;
    return 0;
}