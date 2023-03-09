/**
    Problem Link: https://www.codingninjas.com/codestudio/problems/count-leaf-nodes_893055
    Date: 20/01/2023 10:18:42
    Level: Easy
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Following is the Binary Tree Node class structure:
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

//functions
int noOfLeafNodes(BinaryTreeNode<int> *root){
    if(root->left == NULL && root->right == NULL) {
        return 1;
    }
    int x=0, y=0;
    if(root->right) {
        x = noOfLeafNodes(root->right);
    }
    if(root->left) {
        y = noOfLeafNodes(root->left);
    }
    return x+y;
}


int main() {
    
    return 0;
}