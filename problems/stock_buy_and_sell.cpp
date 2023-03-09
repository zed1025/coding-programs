#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// my code, modified
	void stockBuySell(int price[], int n) {
		int temp, i=0;
	    bool flag=false; //true means inner while executed at least once
	    int start;
	    while(i < n-1) {
	        if(price[i] >= price[i+1]) {
	        	i++;
	        } else {
	        	start=i;
	        	while(price[start]<=price[start+1] && start<n-1) {
	        		start++;
	        	}
	        	flag=true;
	        	cout<<"("<<i<<" "<<start<<")"<<" ";
	        	i=start;
	        }
	    }
	    if(!flag) {
	        cout << "No Profit";
	    }
	    cout << endl;
	}

	void stockBuySell2(int arr[], int n) {
		vector<int>m;
	   	int k;
	   	int i=0;
	   	int count=0; //check if output printed at least once
	   	while(i<n-1) {
			if(arr[i]>=arr[i+1]) {
			   i++;
			} else if(arr[i]<arr[i+1]) {
				k=i;
				m.push_back(i);
				while(arr[k]<=arr[k+1] and k<n-1) {
				   k++;
				};
				i=k;
				count=1;
				cout<<"("<<m[0]<<" "<<k<<")"<<" ";
				m.clear();
			}
   		};
		if(count==0)
			cout<<"No Profit";
		cout<<endl;
	}
};

int main() {
	int arr[] = {5403, 2651, 2754, 2399, 9932, 5060, 9676, 3368, 7739, 12, 6226, 8586, 8094, 7539, 795, 570, 1434, 378, 7467, 6601, 97, 2902, 3317, 492, 6652, 756, 7301, 280, 4286, 9441, 3865, 9689, 8444, 6619, 8440, 4729, 8031, 8117, 8097, 5771, 4481, 675, 709, 8927, 4567, 7856, 9497, 2353, 4586, 6965, 5306, 4683, 6219, 8624, 1528, 2871, 5732, 8829, 9503, 19, 8270, 3368, 9708, 6715, 6340, 8149, 7796, 723, 2618, 2245, 2846, 3451, 2921, 3555, 2379, 7488, 7764, 8228, 9841, 2350, 5193, 1500, 7034, 7764, 124};
	int n = 85;
	Solution ob;
	ob.stockBuySell2(arr, n);
}