#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	int secondLargest(int arr[], int n) {
		if (n < 2) return -1;
	    sort(arr, arr+n, greater<int>());
	    for(int i=1; i<n; i++) {
	        if(arr[i]!=arr[0]) {
	            return arr[i];
	        }
	    }
	    return -1;
	}
};
int main() {
	int arr[] = {12, 35, 1, 10, 34, 1};
	int n = 6;
	Solution ob;
	cout << ob.secondLargest(arr, n);
	return 0;
}