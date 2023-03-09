/**
    Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    Date: 18/01/2023 07:54:12
    Level: Medium
    Notes:
        - same as subset/subsequence problem
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//functions
class Solution {
private:
    void solve(string digits, int index, string output, vector<string> &ans, string *mapping) {
        //base case
        if(index >= digits.length()) {
            ans.push_back(output);
            return ;
        }

        //find number pointed by index
        int num = digits[index] - '0'; //converting char to int
        string value = mapping[num];

        //recursive calls
        for(int i=0; i<value.length(); i++) {
            //append char to output
            output.push_back(value[i]);
            //recursive call
            solve(digits, index+1, output, ans, mapping);
            //backtracking -> remove the char from output, because in current call there is no char in output
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0) return ans;
        string output;
        int index=0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, index, output, ans, mapping);
        return ans;
    }
};

int main() {
    Solution s;
    string digits = "23";
    vector<string> ss = s.letterCombinations(digits);
    for(auto i=ss.begin(); i!=ss.end(); i++) {
        cout << *i << " ";
    } cout << endl;
    return 0;
}