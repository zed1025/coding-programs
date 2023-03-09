/**
    Problem Link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
    Date: 14/01/2023 22:35:35
    Level: Easy
    Notes:
        - https://leetcode.com/problems/largest-substring-between-two-equal-characters/submissions/878181454/
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
public:
    //brute force -> AC
    int maxLengthBetweenEqualCharacters(string s) {
        int max_len = -1;
        for(int i=0; i<s.length(); i++) {
            for(int j=i+1; j<s.length(); j++) {
                if(s[i] == s[j]) {
                    int len = j-i-1;
                    max_len = max(len, max_len);
                }
            }
        }
        return max_len;
    }

    //better solution -> using hashing
    //https://leetcode.com/problems/largest-substring-between-two-equal-characters/solutions/2747693/c-easy-short/
    //in idx we store when a character when it is first encountered, sotring the first occurence
    //on subsequesnt occurence we compare the difference of the stored index and current index, and compare it to the max seen so far
    int maxLengthBetweenEqualCharacters2(string s) {
        int idx[26] = {}, res = -1;
        for (auto i = 0; i < s.size(); ++i) {
            if (idx[s[i] - 'a'] == 0)
                idx[s[i] - 'a'] = i + 1;
            res = max(res, i - idx[s[i] - 'a']);
        }
        return res;
    }
};

//functions

int main() {
    Solution s;
    string st = "cbzxy";
    cout << s.maxLengthBetweenEqualCharacters2(st);
    return 0;
}