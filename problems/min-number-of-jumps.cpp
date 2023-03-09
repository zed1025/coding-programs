/**
 * https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1
 */ 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int minJumps(int arr[], int n) {
		return *max_element(arr+2, arr+8);
	}
};

int main() {
	int N = 11;
	int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	Solution ob;
	int x = ob.minJumps(arr, N);
	cout << x << endl;
}