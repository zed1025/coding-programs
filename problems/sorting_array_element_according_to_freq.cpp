#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int t,size,j;
    cin>>t;
    while(t--){
        cin>>size;
        vector<int> nums;
        unordered_map<int,int> mp; 
        for(int i=0;i<size;i++){
            cin>>j;
            nums.push_back(j);
            mp[j]++;
        }
        //cpp lambdas
        sort(nums.begin(), nums.end(), [&](int a, int b) { return mp[a] != mp[b] ? mp[a] > mp[b] : a < b; });
        for(auto it : nums)
            cout<<it <<" ";
        cout<<endl;
    }
    return 0;
}