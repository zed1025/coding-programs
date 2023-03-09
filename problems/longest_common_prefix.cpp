#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
        int len=INT_MAX;
        string output = "";
        string smallest;
        for(int i=0; i<strs.size(); i++) {
            if(strs[i].length() < len) {
            	len = strs[i].length();
            	smallest = strs[i];
            }
        }
        // cout << smallest << ": "  << len << endl;

        int max_len=0;
        char ch;
        for(int i=0; i<len; i++) {
        	ch = smallest[i];
        	// cout << ch << endl;
        	for(int j=0; j<strs.size(); j++) {
        		// cout << strs[j][i] << endl;
        		if(strs[j][i] != ch) {
        			return output;
        		}
        	}
        	output.push_back(ch);
        }
        return output;
    }

    void test(vector<string> st) {
    	for(int j=0; j<4; j++) {
    		for(int i=0; i<st.size(); i++) {
    			cout << st[i][j] << " ";
    		} cout << endl;
    	}
    	
    }
};

int main() {
	vector<string> strs = {"flower","flow","flight"};
	// vector<string> strs = {"dog","racecar","car"};
	Solution ob;
	string st = ob.longestCommonPrefix(strs);
	// ob.test(strs);
	cout << st << endl;
}