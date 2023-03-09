/**
    Problem Link: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
    Date: 04/02/2023 10:35:06
    Level: 
    Notes:
        - https://www.youtube.com/watch?v=QG0hE0R_ng4&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=71&t=630s
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution {
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 ) {
       //Your code here
       if(root == NULL) {
           return NULL;
       }
       
       if(root->data == n1 || root->data == n2) {
           return root;
       } 
       
       Node* left = lca(root->left, n1, n2);
       Node* right = lca(root->right, n1, n2);
       
       if(left != NULL and right != NULL) {
           return root;
       } else if(left == NULL and right != NULL) {
           return right;
       } else if(left != NULL and right == NULL) {
            return left;
       }
       
       return NULL;
    }
};

int main() {
    
    return 0;
}