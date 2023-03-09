/**
    Problem Link: https://leetcode.com/problems/permutations/
    Date: 18/01/2023 08:49:41
    Level: Medium
    Notes:
        - https://youtu.be/va3NEycUxsg
        - https://leetcode.com/problems/permutations/submissions/880296148/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//functions
//another solution using cpp built in function
class Solution2 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        do{
            ans.emplace_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};


class Solution {
private:
    void solve(vector<int> &nums, vector<vector<int>> &ans, int index) {
        //base case 
        if(index >= nums.size()) {
            ans.push_back(nums);
            return ;
        }

        //recursive case
        for(int i=index; i<nums.size(); i++) {
            swap(nums[i], nums[index]);
            solve(nums, ans, index+1);
            //extra line for backtracking
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;

        solve(nums, ans, index);
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 2, 3};
    vector<vector<int>> vv = s.permute(v);
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