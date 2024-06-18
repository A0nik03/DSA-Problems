#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    void brute(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                ans[j][n - 1 - i] = matrix[i][j];
            }
        }

        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
        
    }

    void optimal(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0 ; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0 ; i < n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }


    }
public:
    void rotate(vector<vector<int>>& matrix) {
        optimal(matrix);
    }
};