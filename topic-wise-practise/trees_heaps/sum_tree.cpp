/**
    Problem Link: https://practice.geeksforgeeks.org/problems/sum-tree/1
    Date: 26/01/2023 10:38:51
    Level: Medium
    Notes:
        - https://youtu.be/nHMQ33LZ6oA
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    Node* left, * right;
};

class Solution {
    private:
    pair<bool, int> isSumTreeFast(Node* root) {
        if(root == NULL) {
            return make_pair(true, 0);
        }
        if(root->left==NULL and root->right==NULL) {
            return make_pair(true, root->data);
        }
        
        pair<bool, int> left = isSumTreeFast(root->left);
        pair<bool, int> right = isSumTreeFast(root->right);
        
        if(left.first and right.first and (left.second+right.second) == root->data) {
            // return make_pair(true, left.second + root->data + right.second);
            return make_pair(true, 2*root->data);
        }
        // return make_pair(false, left.second + root->data + right.second);
        return make_pair(false, 2*root->data);
    }
    public:
    bool isSumTree(Node* root) {
        pair<bool, int> ans = isSumTreeFast(root);
    }
};

int main() {
    
    return 0;
}