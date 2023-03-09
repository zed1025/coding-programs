#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int findMissingNumber(int A[], int n) {
		sort(A, A+n);
		for(int i=0; i<n-1; i++) {cout << A[i] << " ";} cout << endl;
		for(int i=0; i<n-1; i++) {
			if(i+1 != A[i]) {
				return i+1;
			}
		}
		return n;
	}
	int findMissingNumberOptimised(int A[], int n) {
		int sum = (n*(n+1))/2;
		int temp = 0;
		for(int i=0; i<n-1; i++) {
			temp += A[i];
		}
		return sum-temp;
	}
};

int main() {
	int arr[] = {2, 5, 3, 1};
	int n = 5;
	Solution ob;
	int x = ob.findMissingNumberOptimised(arr, n);
	cout << x << endl;
	return 0;
}