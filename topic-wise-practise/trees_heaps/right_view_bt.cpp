/**
    Problem Link: https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1
    Date: 30/01/2023 13:23:51
    Level: Easy
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Should return  right view of tree
class Solution {
    private:
    void solve(Node* root, vector<int> &ans, int level) {
        if(root == NULL) {
            return;
        }
        
        //we entered into new level
        if(level == ans.size()) {
            ans.push_back(root->data);
        }
        
        solve(root->right, ans, level+1);
        solve(root->left, ans, level+1);
        
    }
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root) {
       // Your Code here
       vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

int main() {
    
    return 0;
}