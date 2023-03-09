//https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%3BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
	int findFloor2(vector<long long> v, long long n, long long x){
		long long l=0, h=n-1;
        int mid;
        int temp=INT_MIN;
		while(l<=h) {
			mid=(l+h)/2;
			if(v[mid]==x) {
				return mid;
			} else if(v[mid] < x) {
				temp = max(temp, mid);
				l = mid+1;
			} else {
				h = mid-1;
			}
		}
		return (temp==INT_MIN)?-1:temp;
	}
};

int main() {
	ll arr[] = {1,2,8,10,11,12,19};
	ll n=7, x=173;
	vector<ll> v(arr, arr+n);
	Solution ob;
	cout << ob.findFloor2(v, n, x);
}