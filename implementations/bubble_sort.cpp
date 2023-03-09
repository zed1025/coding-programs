/**
 * @Amit Kumar, 27-Aug-2022
 * Bubble Sort Implementation
 * OOG: O(n^2)
 */
#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

vector<int> bubbleSort(vector<int> arr) {
	int n = arr.size();
	for(int i=0; i<n-1; i++) {
		cout << "\nIteration " << i << ": "; 
		for(int j=0; j<n-i-1; j++) { // go only till n-1-i because the rest are already sorted from back
			if(arr[j] > arr[j+1]) {
				swap(&arr[j+1], &arr[j]);
			}
		}
		for(auto x: arr) {cout << x << " ";}
	}
	return arr;
}

int main() {
	vector<int> m = {45, 7, 89, 10, 8, 2, 90, 1, -1, -999, 88};
	cout << "Elements: \t\t\t";
	for(auto x: m) {
		cout << x << " ";
	}cout << "\n\n";
	m = bubbleSort(m);
	cout << "\n\n\nElements after sorting: \t";
	for(auto x: m) {
		cout << x << " ";
	}
}