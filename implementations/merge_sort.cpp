/**
 * @Amit Kumar, 28-Aug-2022
 * Merge Sort Implementation
 * PROBLEM: doesn't work with negative numbers
 */
#include<bits/stdc++.h>
using namespace std;
void merge() {
	
}

void mergeSort() {
	int mid;
	if(start < end) {
		mid = floor((start+end)/2);
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}
int main() {
	int arr[] = {4, 7, 1, 9, 5, 6, 2, 3, -1, -999, 88};
}