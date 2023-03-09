/**
 * @Amit Kumar, 27-Aug-2022
 * Insertion Sort Implementation
 * OOG: O(n^2)
 */
#include<bits/stdc++.h>
using namespace std;
void insertionSort(vector<int> &arr) {
	int n = arr.size();
	int current, j;
	for(int i=1; i<n; i++) {
		for(auto x: arr) {cout << x << " ";} 
		cout << "\nCurrent element: " << arr[i] << endl;
		current = arr[i];
		j = i-1;
		while(j>=0 && arr[j] > current) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1]=current;
		for(auto x: arr) {cout << x << " ";} cout << "\n\n";
	}
}

int main() {
	vector<int> arr = {4, 7, 1, 9, 5, 6, 2, 3, -1, -999, 88};
	cout << "Original Array: ";
	for(auto i: arr) {cout << i << " ";} cout << "\n\n";
	insertionSort(arr);
	cout << "Sorted Array: ";
	for(auto i: arr) {cout << i << " ";} cout << endl;
}