// https://leetcode.com/problems/max-consecutive-ones/
// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximize-number-of-1s
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	// https://leetcode.com/problems/max-consecutive-ones/
	int findMaxConsecutiveOnes(vector<int> &nums) {
		// int max=0;
		// int size=nums.size();
		// int j;
		// int count;
		// for(int i=0; i<size; i++) {
		// 	j = i;
		// 	count = 0;
		// 	while(j<size) {
		// 		if(nums[j] == 1) {
		// 			j++;
		// 			count++;
		// 		} else {
		// 			break;
		// 		}
		// 	}
		// 	if(count>max) max = count;
		// }
		// return max;

		int count=0, max=0;
        int size=nums.size();
        for(int i=0; i<size; i++){
            if(nums[i]) {
                count++;
                max = std::max(count, max);
            } else {
                count=0;
            }
        }
        return max;
	}

	// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximize-number-of-1s
	// brute force, time ~ O(n^2)
	int findMaxConsecutiveOnes2(int arr[], int n, int m) {
		int count, j, max=0;
		int M=m;
		for(int i=0; i<n; i++) {
			j = i;
			count = 0;
			m=M;
			while(j < n) {
				if(arr[j] == 1) {
					count++;
					j++;
					continue;
				} else if(arr[j] == 0 && m > 0) {
					count++;
					m--; j++;
					continue;
				} else {
					break;
				}
			}
			if(count > max) {
				max = count;
			}
		}
		return max;
	}

	// optimised O(n) solution
	int findMaxConsecutiveOnes2Optimised(int arr[], int n, int m) {
		// Solution using Sliding Window Technique.
        int ans=0,curr=0,zeroes=0,l=0,r=0;
        while(r<n){
            if(!arr[r]){ //if a[r]==0 then true
                if(zeroes<m){
                    zeroes++;
                    curr++;
                }else {
                    while(arr[l++]) {
                        curr--;
                    }
                }
            } else {
                curr++;
            }
            ans=max(ans,curr);
            r++;
        }
        return ans;
	}
	// optimised O(n) solution, approach 2
	int findMaxConsecutiveOnes2Optimised2(int arr[], int n, int m) {
		// Solution using Sliding Window Technique.
        int left=0, right=0, best_window=0, zero_count=0;
        while(right < n) {
        	if(zero_count <= m) {
        		if(arr[right] == 0) {
        			zero_count++;
        		}
        		right++;
        	}
        	if(zero_count > m) {
        		if(arr[left] == 0) {
        			zero_count--;
        		}
        		left++;
        	}
        	best_window = std::max(best_window, (right-left));
        }
        return best_window;
	}
};

int main() {
	vector<int> nums = {1,1,0,1,1,1};
	int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
	int n=11, m=2;
	Solution ob;
	// int x = ob.findMaxConsecutiveOnes(nums);
	// int x = ob.findMaxConsecutiveOnes2(arr, n, m);
	// int x = ob.findMaxConsecutiveOnes2Optimised(arr, n, m);
	int x = ob.findMaxConsecutiveOnes2Optimised2(arr, n, m);
	cout << x << endl;
}