#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t,x,j;
    string s;
    cin>>t;
    while(t--){
        cin>>s;
        vector<int> nums;
        unordered_map<int,int> mp; 
        for(int i=0;i<s.length();i++){
            x = (int)s[i];
            nums.push_back(x);
            mp[x]++;
        }
        //cpp lambdas
        sort(nums.begin(), nums.end(), [&](int a, int b) { return mp[a] != mp[b] ? mp[a] > mp[b] : a < b; });
        char a[s.length()];
        int i=0;
        for(auto it : nums) {
            a[i++] = (char)it;
            // cout<<(char)it <<" ";
        }
        string a2(a);
        cout<<a2;
    }
    return 0;
}