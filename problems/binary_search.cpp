#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int binarysearch(int arr[], int n, int k) {
		int mid, low=0, high=n-1;
        while(high>=low) {
            mid=(high+low)/2;
            if(arr[mid] == k) {
                return mid;
            } 
            if (k < arr[mid]) {
                high=mid-1;
            } else {
                low=mid+1;
            }
        }
        return -1;
	}
};

int main() {
	int arr[] = {11, 22, 33, 44, 55};
	int n=5;
	int k=55;
	Solution ob;
	int x = ob.binarysearch(arr, n, k);
	cout << x << endl;
}