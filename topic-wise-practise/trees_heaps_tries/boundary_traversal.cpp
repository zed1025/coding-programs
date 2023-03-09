/**
    Problem Link: https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
    Date: 27/01/2023 19:21:31
    Level: Medium
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    Node* left, * right;
};

class Solution {
public:
    void traverseLeft(Node* root, vector<int> &ans) {
        if(root == NULL) return ;
        if(root->left == NULL and root->right==NULL) return ; //leaf node
        //can even combine the above two statements
        
        ans.push_back(root->data);
        if(root->left) {
            traverseLeft(root->left, ans);
        } else {
            traverseLeft(root->right, ans);
        }
    }
    
    void traverseLeaf(Node* root, vector<int> &ans) {
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL) {
            ans.push_back(root->data);
        }
        if(root->left) {
            traverseLeaf(root->left, ans);
        }
        if(root->right) {
            traverseLeaf(root->right, ans);
        }
    }
    
    void traverseRight(Node* root, vector<int> &ans) {
        //base cases
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL) {
            return;
        }
        
        //main logic
        if(root->right) {
            traverseRight(root->right, ans);
        } else { //go left
            traverseRight(root->left, ans);
        }
        
        //wapas aane pe print root value
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root) {
        //Your code here
        vector<int> ans;
        if(root == NULL) return ans;
        
        //root added
        ans.push_back(root->data);
        
        //left part added
        traverseLeft(root->left, ans);
        //leaf nodes added, for left and right subtree of root
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
        //right nodes added in reverse
        traverseRight(root->right, ans);
        
        return ans;
    }
};

int main() {
    
    return 0;
}