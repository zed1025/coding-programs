/**
 * @Amit Kumar, 27-Aug-2022
 * Selection Sort Implementation
 * OOG: O(n^2)
 */
#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr) {
	int n = arr.size();
	int temp, minIndex;
	int i, j;
	for(i=0; i<n-1; i++) {
		cout << "\nElement " << arr[i] << " swapped with element ";
		minIndex = i;
		for(j=i+1; j<n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		cout << arr[minIndex] << endl;
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
		for(auto x: arr) {cout << x << " ";} cout << endl;
	}
}
int main() {
	vector<int> arr = {4, 7, 1, 9, 5, 6, 2, 3, -1, -999, 88};
	cout << "Original Array: ";
	for(auto i: arr) {cout << i << " ";} cout << endl;
	selectionSort(arr);
	cout << "Sorted Array: ";
	for(auto i: arr) {cout << i << " ";} cout << endl;
}