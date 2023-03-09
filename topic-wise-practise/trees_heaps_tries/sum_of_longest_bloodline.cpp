/**
    Problem Link: https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
    Date: 03/02/2023 08:56:01
    Level: Easy
    Notes:
        - https://youtu.be/QG0hE0R_ng4
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

//my solution -> AC
class Solution {
private:
    void solve(Node* root, pair<int, int> &ans, int level, int sumSoFar) { //pair<sum, no_of_nodes>
        if(root == NULL) {
            return ; //change
        }
        sumSoFar = sumSoFar+root->data;
        level=level+1;
        // pair<int, int> temp;
        // temp->first = sumSoFar;
        // temp->second = level;
        if(root->left == NULL and root->right == NULL) { //we evaluate longest path at each leaf node
            if(level >= ans.second) {
                ans.first = sumSoFar;
                ans.second = level;
                return ;
            }
        }
        
        //recursive calls
        solve(root->left, ans, level, sumSoFar);
        solve(root->right, ans, level, sumSoFar);
    }
public:
    int sumOfLongRootToLeafPath(Node *root) {
        //code here
        if(root==NULL) {
            return 0;
        }
        pair<int, int> ans;
        ans.first=0;
        ans.second=0;
        int level=0;
        int sumSoFar=0;
        solve(root, ans, level, sumSoFar);
        return ans.first;
    }
};

int main() {
    
    return 0;
}