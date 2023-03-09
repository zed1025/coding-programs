/**
    Problem Link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1
    Date: 22/01/2023 10:45:58
    Level: Easy
    Notes:
        - AC
        - height = no of nodes in the longest path from root to leaf
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
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(node->left == NULL && node->right == NULL) {
            return 1;
        }
        int left=0, right=0;
        if(node->left) {
            left = 1+height(node->left);
        }
        if(node->right) {
            right = 1+height(node->right);
        }
        if(left == right) {
            return left;
        } else if(left > right) {
            return left;
        }
        return right;
    }
};

int main() {
    
    return 0;
}