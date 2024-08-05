// Solve the Sudoku


/*
Given an incomplete Sudoku configuration in terms of a 9 x 9  2-D square matrix (grid[][]), the task is to find a solved Sudoku. For simplicity, you may assume that there will be only one unique solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Zeros in the grid indicates blanks, which are to be filled with some number between 1-9. You can not replace the element in the cell which is not blank.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int sudoku[N][N], int row, int col, int c) {
      for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == c)
          return false;
        if (sudoku[i][col] == c)
          return false;
    
        if (sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
          return false;
      }
      return true;
}

    bool SolveSudoku(int sudoku[N][N])  
    { 
        for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
    
          if (sudoku[i][j] == 0) {
            for (int c = 1; c <= 9; c++) {
              if (isValid(sudoku, i, j, c)) {
                sudoku[i][j] = c;
    
                if (SolveSudoku(sudoku) == true) {
                  return true;
                } else
                  sudoku[i][j] = 0;
              }
            }
            return false;
          }
        }
      }
      return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid(int grid[N][N]) {
        SolveSudoku(grid);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << grid[i][j]<<" ";
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends