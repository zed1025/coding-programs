/**
    Problem Link: https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
    Date: 06/02/2023 09:26:41
    Level: Medium
    Notes:
        - https://www.youtube.com/watch?v=QG0hE0R_ng4&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=81
        - TC=O(n), SC=O(height)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution{
  private:
    pair<int, int> solve(Node* root) {
        if(root==NULL) return make_pair(0,0);
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        
        pair<int, int> result;
        
        result.first = root->data+left.second+right.second;//maxSum including all nodes at current level
        result.second = max(left.first, left.second) + max(right.first, right.second);//maxSum excludiing all nodes at current level
        return result;
    }
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root)  {
        //pair.first = maxSum including the nodes in current level
        //pair.second = maxSum excluding the nodes in current level
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};

int main() {
    
    return 0;
}