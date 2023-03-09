/**
    Problem Link: https://leetcode.com/problems/subsets/solutions/3051293/subsets-c-solution/
    Date: 17/01/2023 22:49:34
    Level: 
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//functions
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> val;
    int n;

    void solve(vector<int> &a, int id) {
        ans.push_back(a);
        for(int i=id; i<n; i++) {
            a.push_back(val[i]);
            solve(a, i+1);
            a.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        for(auto x: nums) val.push_back(x);
        vector<int> a;
        solve(a, 0);
        return ans;
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