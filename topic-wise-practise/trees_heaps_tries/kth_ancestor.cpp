/**
    Problem Link: https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
    Date: 06/02/2023 09:24:19
    Level: Medium
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


struct Node{
	int data;
	struct Node *left, *right;
};

Node* solve(Node* root, int &k, int node) {
    //base case
    if(root==NULL) return NULL;
    if(root->data==node) return root;
    
    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k, node);
    
    //after coming back from left and right calls
    if(left!=NULL and right==NULL) {
        k--;
        if(k<=0) {
            k = INT_MAX; //answer found and we dont want k to go anywhere near 0 again
            return root;
        }
        return left;
    } else if(left==NULL and right!=NULL) {
        k--;
        if(k<=0) {
            k = INT_MAX; //answer found and we dont want k to go anywhere near 0 again
            return root;
        }
        return right;
    }
    return NULL;
}

// your task is to complete this function
int kthAncestor(Node *root, int k, int node) {
    // Code here
    Node* ans = solve(root, k, node);
    if(ans==NULL || ans->data==node) return -1; //IMP: OR handles the case when we find node in the root and k>0
    else return ans->data;
}

int main() {
    
    return 0;
}