// 1048. Longest String Chain

/*
You are given an array of words where each word consists of lowercase English letters.

wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

Return the length of the longest possible word chain with words chosen from the given list of words.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool compareStrings(string str1,string str2){
        if(str1.size() != str2.size() + 1) return false;
        int first = 0,second = 0;
        while(first < str1.size()){
            if(second < str2.size() && str1[first] == str2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first == str1.size() && second == str2.size()) return true;
        return false;
    }

    static bool comp(string &s,string &t){
        return s.size() < t.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        int maxi = 1,lastIndex = 0;
        sort(words.begin(),words.end(),comp);
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(compareStrings(words[i],words[prev]) && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};