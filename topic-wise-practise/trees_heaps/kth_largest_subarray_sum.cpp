/**
Problem Link: https://www.codingninjas.com/codestudio/problems/k-th-largest-sum-contiguous-subarray_920398
Date: 2023-03-07 08:19:18
Level: Medium
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//comparator function for descending order sort
struct greater1 {
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

//brute force -> AC
//O(n^2) time and O(n^2) space
int getKthLargest1(vector<int> &arr, int k) {
	//	Write your code here.
	vector<int> sums;
	int sumSoFar=0;
	int n = arr.size();
	for(int i=0; i<n; i++) {
		sumSoFar = 0;
		for(int j=i; j<n; j++) {
			sumSoFar += arr[j];
			sums.push_back(sumSoFar);
		}
	}
    //printing the subarray sums
    for(auto i: sums) {
        cout << i << " ";
    } cout << endl;

	// sort(sums.begin(), sums.end(), greater1());
    // sort(sums.begin(), sums.end(), std::greater<>());
    sort(sums.begin(), sums.end(), [](const int a, const int b) {return a > b; });

    cout << "Sorted array: ";
    for(auto i: sums) {
        cout << i << " ";
    } cout << endl;
	return sums[k-1];
}


//optimised
//O(k) space only used
int getKthLargest1(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int sumSoFar=0;
    int n = arr.size();
    for(int i=0; i<n; i++) {
        sumSoFar = 0;
        for(int j=i; j<n; j++) {
            sumSoFar += arr[j];
            if(pq.size() < k) {
                pq.push(sumSoFar);
            } else {
                if(sumSoFar > pq.top()) {
					pq.pop();
                	pq.push(sumSoFar);
				} 
            }
        }
    }
    return pq.top();
}


int main() {
    vector<int> arr = {1, 2, 6};
    int k = 4;
    int ans = getKthLargest1(arr, k);
    cout << "kth largest subarray sum is: " << ans << endl;
    return 0;
}