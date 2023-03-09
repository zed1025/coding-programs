#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	//using dictionary, O(n) time, O(n) space
	int singleNumber(vector<int> nums) {
		map<int, int> m;
		int ans=0;
		for(auto x: nums) {
			if(m.find(x) != m.end()) {
				m[x] += 1;
			} else {
				m[x] = 1;
			}
		}
		for(auto x: m) {
			if(x.second == 1) {
				ans = x.first;
			}
		}
		return ans;
	}

	int singleNumber_XOR(vector<int> nums) {
		int x=0;
		for(int i=0; i<nums.size(); i++) {
			x ^= nums[i];
		}
		return x;
	}
};

int main() {
	vector<int> nums = {4,1,2,1,2};
	Solution ob;
	// cout << ob.singleNumber(nums);
	cout << ob.singleNumber_XOR(nums);
}