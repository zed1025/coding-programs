//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	void intersection2(int arr1[], int arr2[], int n, int k) {
		int i=0, j=0;
		vector<int> inter;
		while(i<n && j<k) {
			if(arr1[i] == arr2[j]) {
				inter.push_back(arr1[i]);
				i++;
				j++;
				continue;
			}
			if(arr1[i] < arr2[j]) {
				i++;
			} else {
				j++;
			}
		}
		for(auto x: inter) {cout << x << " ";} cout << endl;
	}


	// brute force, working
	void intersection(int arr1[], int arr2[], int n, int k) {
		displayArray(arr1, n, 1);
		displayArray(arr2, k, 2);
		map<int, int> m;
		for(int i=0; i<n; i++) {
			if(m.find(arr1[i]) != m.end()) {
				m[arr1[i]] += 1;
			} else {
				m[arr1[i]] = 1;
			}
		}
		vector<int> elements;
		for(int j=0; j<k; j++) {
			if(m.find(arr2[j]) != m.end()) {
				if(m[arr2[j]] > 0) {
					elements.push_back(arr2[j]);
					m[arr2[j]] -= 1;
				}
			}
		}
		for(auto x: elements) {cout << x << " ";} cout << endl;
	}

	void displayArray(int arr[], int n, int rank) {
		cout << "Displaying array " << rank << ": ";
		for(int i=0; i<n; i++) {
			cout << arr[i] << " ";
		}cout << endl;
	}
	void displayMap(map<int, int> m) {
		for(auto x: m) {
			cout << x.first << " -> " <<  x.second << endl;
		}
	}
};

int main() {
	Solution ob;
	int arr1[] = {1, 3, 4, 8, 8, 9, 10, 13, 15, 99};
	int arr2[] = {3, 4, 8, 8, 99};
	int n = sizeof(arr1)/sizeof(arr1[0]);
	int m = sizeof(arr2)/sizeof(arr2[0]);
	ob.intersection2(arr1, arr2, n, m);
}