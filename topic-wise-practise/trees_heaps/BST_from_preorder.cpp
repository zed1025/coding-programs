/**
Problem Link: https://www.codingninjas.com/codestudio/problems/preorder-traversal-to-bst_893111
Date: 2023-03-04 07:19:04
Level: 
Notes:
    - 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left){
            delete left;
        }
        if (right){
            delete right;
        }
    }
};

BinaryTreeNode<int>* solve(vector<int> &preorder, int mini, int maxi, int &index) {
    if(index >= preorder.size()) {
        return NULL;
    }
    if(preorder[index] < mini || preorder[index] > maxi) {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[index++]);
    root->left = solve(preorder, mini, root->data, index);
    root->right = solve(preorder, root->data, maxi, index);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int index=0;
    return solve(preorder, mini, maxi, index);
}

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    
    return 0;
}