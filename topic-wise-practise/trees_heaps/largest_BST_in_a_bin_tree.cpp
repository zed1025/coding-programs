/**
Problem Link: https://www.codingninjas.com/codestudio/problems/largest-bst-subtree_893103
Date: 2023-03-04 09:19:02
Level: 
Notes:
    - NOT AC
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

template <typename T>
class TreeNode {
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
        if(left)
            delete left;
        if(right)
            delete right;
    }
};


class info {
    public:
        int maxi, mini, size;
        bool isBST;
};

info solve(TreeNode<int>* root, int &ans) {
    if(root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + 1 + right.size;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    } else {
        currNode.isBST = false;
    }

    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }
    return currNode;    
}

int largestBST(TreeNode<int>* root)  {
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}



int main() {
    
    return 0;
}