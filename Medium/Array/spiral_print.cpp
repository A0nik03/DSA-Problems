#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
// Strivers
    vector<int> spiralOrder_methOne(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;
        int left = 0, right = m - 1, bottom = n - 1, top = 0;
        while (left <= right && top <= bottom) {
            // Top
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            // Right
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if (top <= bottom) {
                // Bottom
                for (int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if (left <= right) {
                // Left
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
// Strivers Modified 
    vector<int> spiralOrder_methTwo(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int count = 0;
        int total = n * m;
        vector<int> ans;
        int left = 0, right = m - 1, bottom = n - 1, top = 0;
        while (count < total) {
            // Top
            for (int i = left; count < total && i <= right; i++) {
                ans.push_back(matrix[top][i]);
                count++;
            }
            top++;
            // Right
            for (int i = top; count < total && i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
                count++;
            }
            right--;
            // Bottom
            for (int i = right; count < total && i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
                count++;
            }
            bottom--;

            // Left
            for (int i = bottom; count < total && i >= top; i--) {
                ans.push_back(matrix[i][left]);
                count++;
            }
            left++;
        }
        return ans;
    }

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return spiralOrder_methTwo(matrix);
    }
};