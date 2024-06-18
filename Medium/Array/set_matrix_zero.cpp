#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Brute Force

    void markRow(int i, vector<vector<int>>& matrix) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void markCol(int j, vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = -1;
            }
        }
    }

    void brute(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    markRow(i, matrix);
                    markCol(j, matrix);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // Better Solution
    void better(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) { better(matrix); }
};