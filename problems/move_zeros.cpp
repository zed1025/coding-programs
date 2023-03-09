//https://leetcode.com/problems/move-zeroes/
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
	void moveZeros(vector<int>& nums) {
		if(nums.size() == 1) return;
		int count = 0;
		int size = nums.size();
        for(int i=0; i<size; i++) {
            if(nums[i] == 0) {
            	count++;          
            }
        }
    	nums.erase(remove(nums.begin(), nums.end(), 0), nums.end());
    	nums.insert(nums.end(), count, 0);
	}	
};
int main() {
	vector<int> a = {0,0,1};
	Solution s;
	s.moveZeros(a);
}