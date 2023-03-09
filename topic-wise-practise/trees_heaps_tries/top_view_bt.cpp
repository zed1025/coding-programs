/**
    Problem Link: https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
    Date: 30/01/2023 09:54:02
    Level: Medium
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root) {
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
            
            if(topNode.find(hd) == topNode.end()) { //hd not found in topNode
                topNode[hd] = front->data;
            }
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