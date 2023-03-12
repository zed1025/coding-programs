/** 
Problem Link: https://leetcode.com/contest/weekly-contest-336/problems/rearrange-array-to-maximize-prefix-score/
Date: 2023-03-12 09:12:20
Level: 
Notes:
    - AC
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int ans=0;
        long long prefixsum=0;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(prefixsum>0)ans++;
            else break;
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2,-1,0,1,-3,3,-3};
    vector<int> nums2 = {-687767,-860350,950296,52109,510127,545329,-291223,-966728,852403,828596,456730,-483632,-529386,356766,147293,572374,243605,931468,641668,494446};
    Solution s;
    cout << s.maxScore(nums) << endl;
    cout << s.maxScore(nums2) << endl;
    return 0;
}