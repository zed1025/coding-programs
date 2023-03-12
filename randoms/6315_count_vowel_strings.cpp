/**
Problem Link: https://leetcode.com/contest/weekly-contest-336/problems/count-the-number-of-vowel-strings-in-range/
Date: 2023-03-12 09:06:01
Level: 
Notes:
    - LeetCode Weekly Contest 336
    - AC
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
    
public:
    bool isVowelString(string str, set<char> &vowels) {
        int n = str.length();
        if(vowels.find(str[0]) != vowels.end() && vowels.find(str[n-1]) != vowels.end()) {
            return true;
        }
        return false;

    }
    int vowelStrings(vector<string>& words, int left, int right) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int count=0;
        for(int i=left; i<=right; i++) {
            if(isVowelString(words[i], vowels)) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    
    return 0;
}