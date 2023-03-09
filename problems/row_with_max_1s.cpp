#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	//brute force, O(n^2)
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
		int count, max=0;
		int ans;
		for(int i=0; i<n; i++) {
			count=0;
			for(int j=0; j<m; j++) {
				count += arr[i][j]&1;			
			}
			if(count > max) {
				max = count;
				ans=i;
			}
		}
		return ans;
	}

	//optimised
	int rowWithMax1s_opti(vector<vector<int> > arr, int n, int m) {
		for(int i=0; i<m; i++) {
	        for(int j=0; j<n; j++) {
	            if(arr[j][i] == 1) {
	                return j;
	            }
	        }
	    }
	    return -1;
	}
};

int main() {
	vector<vector<int>> arr = {{0, 0}, {1, 1}};
	Solution ob;
	// cout << ob.rowWithMax1s(arr, arr.size(), arr[0].size());
	cout << ob.rowWithMax1s_opti(arr, arr.size(), arr[0].size());
}