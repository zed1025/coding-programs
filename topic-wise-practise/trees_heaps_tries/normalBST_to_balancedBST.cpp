/**
Problem Link: https://www.codingninjas.com/codestudio/problems/normal-bst-to-balanced-bst_920472
Date: 2023-03-04 06:48:38
Level: 
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

template <typename T>
class TreeNode
{
public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};


void findInorder(TreeNode<int>* root, vector<int> &inorder) {
    //Inorder: LNR
    if (root == NULL) return ;
    findInorder(root->left, inorder);
    inorder.push_back(root->data);
    findInorder(root->right, inorder);
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> inorder) {
    if(s > e) return NULL;

    int mid = (e+s)/2;
    TreeNode<int>* balancedRoot = new TreeNode<int>(inorder[mid]);
    balancedRoot->left = inorderToBST(s, mid-1, inorder);
    balancedRoot->right = inorderToBST(mid+1, e, inorder);
    return balancedRoot;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> inorder;
    findInorder(root, inorder);

    return inorderToBST(0, inorder.size()-1, inorder);
}



int main() {
    
    return 0;
}