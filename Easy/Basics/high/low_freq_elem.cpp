#include <iostream>
#include <vector>
using namespace std;

#include <map>
vector<int> getFrequencies(vector<int>& v) {
   map<int,int> hash;
   vector<int> ans;
   for (int i = 0; i < v.size(); i++) {
     hash[v[i]]++;
   }
   int max_key = 0;
   int max_value = INT32_MIN;
   int min_key = 0;
   int min_value = INT32_MAX;
   for(auto it:hash){
       if(max_value < it.second){
           max_value = it.second;
           max_key = it.first;
       }

       if(min_value > it.second){
           min_value = it.second;
           min_key = it.first;
       }
   }

   ans.push_back(max_key);
   ans.push_back(min_key);
   return ans;
}