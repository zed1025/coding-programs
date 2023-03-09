#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// leetcode
	// https://leetcode.com/problems/subarray-sum-equals-k/
	// brute-force, TLE
	int subarraySum(vector<int>& nums, int k) {
		// for(auto x: nums) {cout << x << " ";} cout << endl;
		int sum=0, count=0;
		for(int i=0; i<nums.size(); i++) {
			sum=0;
			for(int j=i; j<nums.size(); j++) {
				sum += nums[j];
				if(sum == k) {
					count++;
				}
			}
		}
		return count;
	}

	//leetcode - optimised
	int subarraySum_optim(vector<int>& nums, int k) {
		// using hashmap and prefix sum
		map<int, int> m;
		vector<int> prefix;
		int ans=0;
		//creating the prefix sum array
		prefix.push_back(nums[0]);
		for(int i=1; i<nums.size(); i++) {
			prefix.push_back(nums[i]+prefix[i-1]);
		}
		// for(auto x: prefix) {cout << x << " ";} cout << endl;
		for(int i=0; i<nums.size(); i++) {
			if (prefix[i] == k) ans++;
			if(m.find(prefix[i]-k) != m.end()) {
				ans += m[prefix[i]-k];
			}
			m[prefix[i]]++;
		}
		return ans;
	}

	// g4g
	// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k
	// brute-force
	int lenOfLongSubarr(int A[],  int N, int K) { 
        return -1;
    } 


    // g4g - optimised
	int lenOfLongSubarr_optim(int A[],  int N, int K) { 
        unordered_map<int,int> map;
		int sum=0,count=0;
		// here
		map[0]=-1;
		for(int i=0;i<n;i++){
			sum+=a[i]; //prefix sum
			if(map.count(sum-k)>0) { //map::count() is a built-in function in C++ STL which returns 1 if the element with key K is present in the map container
				count=max(count,i-map[sum-k]);
			}
			if(!map.count(sum)) map[sum]=i;
		}
		return count;
    } 
};

int main() {
	int arr[] = {1, -1, 0};
	int N=3;
	vector<int> nums(arr, arr+N);
	int k=0;
	Solution ob;
	// cout << ob.subarraySum(nums, k);
	cout << ob.subarraySum_optim(nums, k);
	
}