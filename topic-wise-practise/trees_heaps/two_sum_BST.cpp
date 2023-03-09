/**
Problem Link: https://www.codingninjas.com/codestudio/problems/two-sum-in-a-bst_1062631
Date: 2023-03-04 06:09:28
Level: Medium
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
    
};

void findInorder(BinaryTreeNode<int>* root, vector<int> &inorder) {
    //Inorder: LNR
    if (root == NULL) return ;
    findInorder(root->left, inorder);
    inorder.push_back(root->data);
    findInorder(root->right, inorder);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> inorder;
    findInorder(root, inorder);
    int i=0, j=inorder.size()-1, temp=0;
    while(i < j) {
        temp = inorder[i]+inorder[j];
        if(temp == target) {
            return true;
        } else if(temp > target) {
            j = j-1;
        } else {
            i = i+1;
        }
    }
    return false;
}

int main() {
    
    return 0;
}