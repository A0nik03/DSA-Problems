// Find a Peak Element II

/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {

        int low = 0, high = mat[0].size() - 1;
        while(low <= high){
            int midCol = (low + high) >> 1;

            int row = 0;
            for(int i = 0; i < mat.size();i++){
                if(mat[i][midCol] > mat[row][midCol]){
                    row = i;
                }
            }
            int currCol = mat[row][midCol];
            int leftcol = (midCol == 0) ? -1 : mat[row][midCol - 1]; 
            int rightcol = (midCol == mat[0].size() - 1) ? -1 : mat[row][midCol + 1]; 

            if(currCol > leftcol && currCol > rightcol){
                return {row,midCol};
            }
            
            if(currCol < leftcol){
                high = midCol - 1;
            }
            else{
                low = midCol + 1;
            }
        }
        return {-1,-1};
    }
};