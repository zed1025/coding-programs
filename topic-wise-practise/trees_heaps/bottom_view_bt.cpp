/**
    Problem Link: https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
    Date: 30/01/2023 12:42:43
    Level: Medium
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        //Your code here
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        
        map<int, int> topNode;
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0)); //int stores the HD
        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* front = temp.first;
            int hd = temp.second;
            
            //dont check any condition just add node or replace if a mapping already exists for key
            topNode[hd] = front->data;
            
            if(front->left) {
                q.push(make_pair(front->left, hd-1));
            }
            if(front->right) {
                q.push(make_pair(front->right, hd+1));
            }
        }
        
        for(auto i: topNode) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}