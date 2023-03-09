/**
Problem Link: https://www.codingninjas.com/codestudio/problems/flatten-bst-to-a-sorted-list_1169459
Date: 2023-03-04 06:28:54
Level: Medium
Notes:
    - 
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

void findInorder(TreeNode<int>* root, vector<int> &inorder) {
    if(root == NULL) return ;
    //inorder: LNR
    findInorder(root->left, inorder);
    inorder.push_back(root->data);
    findInorder(root->right, inorder);
}
TreeNode<int>* flatten(TreeNode<int>* root) {
    vector<int> inorder;
    findInorder(root, inorder);

    int n = inorder.size();
    TreeNode<int>* head = new TreeNode<int>(inorder[0]);
    TreeNode<int>* current = head;
    for(int i=1; i<n; i++) {
        //create new node
        TreeNode<int> *temp = new TreeNode<int>(inorder[i]);
        //change pointers
        current->left = NULL;
        current->right = temp;
        current = temp;
    }
    //for last node
    current->left = NULL;
    current->right = NULL;
    return head;
}

int main() {
    
    return 0;
}