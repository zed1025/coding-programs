#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
	// my solution, not working, some error with indexing
	int searchInsertK(vector<int> a, int N, int k){
		// cout << "Hello\n";
		if(k > a[N-1]) {
            return N;
        } 
        if(k < a[0]) {
        	cout << "Hello 2\n";
            return 1;
        }
        int l=0,h=N;
        int mid;
        while(l<h) {
            mid=(l+h)/2;
            if(a[mid]==k){
                return mid;
            } else if(k > a[mid]) {
                l=mid+1;
            } else {
                h=mid-1;
            }
        }
        if(a[mid] < k) {
            return mid+1;
        }
        return mid;
    }



    int searchInsertK_working(vector<int> arr, int N, int k) {
    	int low = 0;
        int high = N-1;
        
        if(k > arr[N-1]) return N;
        
        while(low < high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] >= k){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};

int main() {
	int n=6;
	vector<int> ar = {-14, -3, 1, 4, 5, 13 };
	int k = -12;
	Solution ob;
	// cout << ob.searchInsertK(ar, n, k) << endl;
	cout << ob.searchInsertK_working(ar, n, k) << endl;
}