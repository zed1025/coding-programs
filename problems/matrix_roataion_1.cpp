#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
	// roatate matrix by 90deg anti-clockwise
	// https://practice.geeksforgeeks.org/problems/rotate-by-90-degree-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotate-by-90-degree
	void rotateby90(vector<vector<int> >& matrix, int n) {
		for(int i=0; i<n; i++) {
			sort(matrix[i].begin(), matrix[i].end());
		}

		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				cout << matrix[i][j] << " ";
			}cout << endl;
		}
	}
};

int main() {
	vector<vector<int>> matrix;
	int n=3;
	int mat[n][n] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	for(int i=0; i<n; i++) {
		matrix[i].assign(n, 0);
		for(int j=0; j<n; j++) {
			matrix[i][j] = mat[i][j];
		}
	}
	Solution ob;
	ob.rotateby90(matrix, n);
}
