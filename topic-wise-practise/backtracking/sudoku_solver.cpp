/**
Problem Link: https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919
Date: 2023-03-11 09:50:14
Level: Hard
Notes:
    - Backtracking
    - TC: O(9^m), m is the no of empty cells
    - SC: O(1)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isSafe(int row, int col, vector<vector<int>>& board, int val) {
    for(int i=0; i<board.size(); i++) {
        //row check
        if(board[row][i] == val) {
            return false;
        }

        //col check
        if(board[i][col] == val) {
            return false;
        }

        //check 3*3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val) {
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>>& board) {
    int n = board[0].size();
    for(int row=0; row<n; row++) {
        for(int col=0; col<n; col++) {
            //cell empty
            if(board[row][col] == 0) {
                for(int val=1; val<=9; val++) {
                    if(isSafe(row, col, board, val)) {
                        board[row][col] = val;
                        //recursive call
                        bool furtherSolutionPossible = solve(board);
                        if(furtherSolutionPossible) {
                            return true;
                        } else {
                            //backtrack
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku) {
	solve(sudoku);
}

int main() {
    
    return 0;
}