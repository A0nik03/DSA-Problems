#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int count = 0;
    const int mod = 1e9 + 7;

    void solve(const string &str, int ind, string per, set<string> &arrange) {
        if (ind == str.size()) {
            if (!per.empty()) {
                arrange.insert(per);
            }
            return;
        }
        // Include the current character
        per.push_back(str[ind]);
        solve(str, ind + 1, per, arrange);
        per.pop_back(); // Exclude the current character
        solve(str, ind + 1, per, arrange);
    }

    int distinctSubseqII(const string &s) {
        string per = "";
        set<string> arrange;
        solve(s, 0, per, arrange);
        return arrange.size() % mod;
    }
};

// Main function to test the Solution class
int main() {
    Solution solution;
    string testString = "aba";
    int result = solution.distinctSubseqII(testString);
    cout << "Number of distinct subsequences of \"" << testString << "\": " << result << endl;
    return 0;
}
