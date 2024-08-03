// Permutations of a given string


/*
Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order. 
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{  private:
    void permute(string& S, int size, vector<string>& ds, int ind) {
        if (ind == size) {
            ds.push_back(S);
            return;
        }

        for (int i = ind; i < size; i++) {
            if (i != ind && S[i] == S[ind]) continue; // Skip duplicate characters
            swap(S[i], S[ind]);
            permute(S, size, ds, ind + 1);
            swap(S[i], S[ind]); // Backtrack
        }
    }

public:
    vector<string> find_permutation(string S) {
        vector<string> ds;
        sort(S.begin(), S.end()); // Sort to ensure duplicates are adjacent
        permute(S, S.size(), ds, 0);
        sort(ds.begin(), ds.end());
        ds.erase(unique(ds.begin(), ds.end()), ds.end());
        return ds;
    }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends