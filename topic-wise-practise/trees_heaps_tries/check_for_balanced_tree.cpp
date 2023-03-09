/**
    Problem Link: https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1
    Date: 26/01/2023 09:43:34
    Level: Easy
    Notes:
        - https://youtu.be/nHMQ33LZ6oA
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

//brute-force
class Solution1{
    public:
    //Function to check whether a binary tree is balanced or not.
    int height(Node* root) {
        if(root == NULL) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right)+1;
    }
    bool isBalanced(Node *root) {
        if(root == NULL) {
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        if(left && right && diff) {
            return true;
        }
        return false;
    }
};



//optimised
class Solution2{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool, int> isBalancedHelper(Node *root) { //first=isBalanced or not, second=height
        if(root == NULL) {
            return make_pair(true, 0);
        }
        pair<bool, int> left = isBalancedHelper(root->left);
        pair<bool, int> right = isBalancedHelper(root->right);
        
        
        bool diff = abs(left.second - right.second) <= 1;
        if(left.first && right.first && diff) {
            return make_pair(true, max(left.second, right.second)+1);
        }
        return make_pair(false, max(left.second, right.second)+1);
    }
    
    bool isBalanced(Node* root) {
        pair<bool, int> ans = isBalancedHelper(root);
        return ans.first;
    }
};

int main() {
    
    return 0;
}