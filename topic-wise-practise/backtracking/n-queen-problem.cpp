/**
Problem Link: https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286
Date: 2023-03-10 10:13:41
Level: 
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;



//Approach 1
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
	vector<int> temp;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			temp.push_back(board[i][j]);
		}
	}

	ans.push_back(temp);
}
bool isSafe(int row, int col, vector<vector<int>> &board, int n) {
	//must not attack
	//does not share -> row or col or diagonal
	int x=row, y=col;
	//check for same row
	while(y >= 0) {
		if(board[x][y] == 1) {
			return false;
		}
		y--;
	}
	//no need to check col, because we only place one queen in each column
	//checking diagonal
	x=row, y=col;
	//check for diagonal
	while((x>=0 && y>=0)) {
		if(board[x][y] == 1) {
			return false;
		}
		y--;x--;
	}
	x=row, y=col;
	while((x<n && y>=0)) {
		if(board[x][y] == 1) {
			return false;
		}
		y--;x++;
	}
	return true;
}
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {
	//base case
	if(col == n) {
		addSolution(board, ans, n); //add solutin from board to ans
		return ;
	}

	//placing in column 1, solve 1 case recursion will take care of rest
	for(int row=0; row<n; row++) {
		if(isSafe(row, col, board, n)) {
			board[row][col] = 1;	
			solve(col+1, ans, board, n);
			board[row][col] = 0; //for backtracking
		}
	}
}
vector<vector<int>> nQueens(int n) {
	vector<vector<int>> board(n, vector<int>(n, 0)); 
	vector<vector<int>> ans;

	solve(0, ans, board, n);

	return ans;
	
}

int main() {
    
    return 0;
}