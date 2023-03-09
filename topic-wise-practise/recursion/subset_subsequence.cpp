/**
    Problem Link: https://leetcode.com/problems/subsets/submissions/880015788/
    Date: 17/01/2023 21:25:27
    Level: Medium
    Notes:
        - finding subsets of an array
        - https://youtu.be/V0IgCltYgg4

        - Subsequence problem is same(ditto) as subset problem except there the input is a string rather than array
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//functions
class Solution {
private: 
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans) {
        //base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return;
        }

        //recursive case
        //exclude
        solve(nums, output, index+1, ans);

        //imclude
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
public:
    //solution 1-> https://leetcode.com/problems/subsets/submissions/880015788/
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        int index=0;
        solve(nums, output, index, ans);
        return ans;
    }

    //try 1->brutre force using double for loops -> wrong answer
    //Possible approach similar to mine: 
    //https://leetcode.com/problems/subsets/solutions/122645/3ms-easiest-solution-no-backtracking-no-bit-manipulation-no-dfs-no-bullshit/
    //https://leetcode.com/problems/subsets/solutions/27278/c-recursive-iterative-bit-manipulation/
    vector<vector<int>> subsets1(vector<int>& nums) {
        // vector<int> v;
        // vector<vector<int>> vv;
        // vv.push_back(v);
        // for(int i=0; i<nums.size(); i++) {
        //     v.clear();
        //     for(int j=i; j<nums.size(); j++) {
        //         v.push_back(nums[j]);
        //         vv.push_back(v);
        //     }
        // }
        // return vv;


        //https://leetcode.com/problems/subsets/solutions/27278/c-recursive-iterative-bit-manipulation/
        vector<vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); 
                subs.back().push_back(num);
            }
        }
        return subs;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 2, 3, 4};
    vector<vector<int>> vv = s.subsets(v);
    cout << "[ ";
    for(int i=0; i<vv.size(); i++) {
        cout << "[ ";
        for(int j=0; j<vv[i].size(); j++) {
            cout << vv[i][j] << ", ";
        }
        cout <<  " ] ";
    }cout << " ]" << endl;
    return 0;
}