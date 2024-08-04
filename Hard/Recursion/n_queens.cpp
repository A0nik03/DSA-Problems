// 51. N-Queens

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row,int col,vector<string>& boards,int n){
        int dupRow = row;
        int dupCol = col;

        while(row >= 0 && col >= 0){
            if(boards[row][col] == 'Q') return false;
            col--;
            row--;
        }

        row = dupRow;
        col = dupCol;
        while(col >= 0){
            if(boards[row][col] == 'Q') return false;
            col--;
        }

        row = dupRow;
        col = dupCol;
        while(row < n  && col >= 0){
            if(boards[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }

    void solve(int col,vector<string>& boards,vector<vector<string>> &ans,int n){
        if(col == n){
            ans.push_back(boards);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(row,col,boards,n)){
                boards[row][col] = 'Q';
                solve(col + 1, boards, ans, n);
                boards[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
       vector<vector<string>> ans;
       vector<string> boards(n);
       string s(n,'.');
       for(int i = 0; i < n; i++){
        boards[i] = s;
       }
       solve(0,boards,ans,n);
       return ans;
    }
};