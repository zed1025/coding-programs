//https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int remove_duplicate(int arr[], int n) {
		int i=0, current, count=0, size=n;
		vector<int> aa;
		while(n--) {
			aa.push_back(arr[i]);
			current = arr[i++];
			while(arr[i] == current) {
				arr[i++] = -1;
				n--;
			}
		}
		for(int i=0; i<size; i++) {
			if(arr[i]!=-1) count++;
		}
		fill(arr, arr+size, 0);
		for(int i=0; i<aa.size(); i++){
			arr[i] = aa[i];
		}
		for(int i=0; i<size; i++) {
			cout << arr[i] << " ";
		}cout << endl;
		return count;
	}

	int remove_duplicate_optimised(int arr[], int n) {
		int i=0;
        for(int j=0;j<n;j++){
           if(arr[i]!=arr[j]) i++;
           arr[i] = arr[j];
        }
        return i+1;
	}
};

int main() {
	int arr[] = {1, 1, 2, 2, 2, 2, 3, 4, 5};
	int n = 9;
	Solution ob;
	// cout << ob.remove_duplicate(arr, n);
	cout << ob.remove_duplicate_optimised(arr, n);
}