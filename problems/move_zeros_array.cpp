// 
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:

	void moveZeros2(int arr[], int n) {
		int c = 0;
		for(int i=0; i<n; i++) {
			if(arr[i]) {
				arr[c++] = arr[i];
			}
		}
		for(; c<n; c++) {
			arr[c] = 0;
		}
		for(int i=0; i<n; i++) {
	    	cout << arr[i] << " ";
	    }cout << endl;
	}
	void moveZeros(int arr[], int n) { //TLE
		int j;
	    bool not_found=false;
	    for(int i=0; i<n; i++) {
	        if(arr[i]==0) {
	            j=i+1;
	            for(j; j<=n-1; j++) {
	                if(arr[j] != 0) {
	                    arr[i] = arr[j];
	                    arr[j] = 0;
	                    break;
	                }
	                if(j == n-1){
	                    not_found=true;
	                    break;
	                }
	            }
	            if(not_found) {
	                break;
	            }
	        }
	    }
	    for(int i=0; i<n; i++) {
	    	cout << arr[i] << " ";
	    }cout << endl;
	}	
};
int main() {
	int a[] = {0,0,1};
	Solution s;
	s.moveZeros2(a, 3);
}