/**
Problem Link: https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
Date: 2023-03-06 08:12:26
Level: 
Notes:
    - Problem
        Given a binary tree. The task is to check whether the given tree follows the max heap property or not.
        Note: Properties of a tree to be a max heap - Completeness and Value of node greater than or equal to its child.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  private:
    int countNodes(struct Node* root) {
        if(root == NULL) {
            return 0;
        }
        int ans = countNodes(root->left) + 1 + countNodes(root->right);
        return ans;
    }

    //function for checking if a binary tree is CBT
    bool isCBT(struct Node* root, int index, int totalCount) {
        if(root == NULL) {
            return true;
        }
        if(index >= totalCount) {
            return false;
        } else {
            bool left = isCBT(root->left, 2*index+1, totalCount);
            bool right = isCBT(root->right, 2*index+2, totalCount);
            return (left && right);
        }
    }

    //function for checking if a CBT follows max-heap property
    bool isMaxOrder(struct Node* root) {
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        if(root->right == NULL) {
            return root->data > root->left->data;
        } else {
            return root->data > root->left->data &&
                    root->data > root->right->data &&
                    isMaxOrder(root->left) &&
                    isMaxOrder(root->right);
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        int index=0; //current index
        int totalCount = countNodes(tree);
        if(isCBT(tree, index, totalCount) && isMaxOrder(tree)) {
            return true;
        }
        return false;
    }
}; 

int main() {
    
    return 0;
}