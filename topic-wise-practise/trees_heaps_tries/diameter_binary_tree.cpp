/**
    Problem Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
    Date: 24/01/2023 23:00:58
    Level: Medium
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Utility function to create a new Tree Node
struct Node* newNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int height(struct Node* root) {
    if(root == NULL) {
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}


// Function to return the diameter of a Binary Tree.
// time complexity is O(n^2) because of calling height() within diameter()
int diameter(struct Node* root) {
    // code here
    if(root == NULL) {
        return 0;
    }
    
    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left) + 1 + height(root->right);
    return max(max(opt1, opt2), opt3);
}



//optimised solution
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int, int> diameterFast(Node* root) {
        //first element of pair is diameter, second element is height
        if(root == NULL) {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);
        
        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second + 1;
    
        //first item returned is the diameter, and the second element is height
        pair<int, int> ans;
        ans.first = max(opt1, max(opt2, opt3));
        ans.second = max(left.second, right.second) + 1;
        return ans;
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};

//functions

int main() {
    
    return 0;
}