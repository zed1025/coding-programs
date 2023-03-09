/**
    Problem Link: https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
    Date: 30/01/2023 13:24:36
    Level: Medium
    Notes:
        - https://www.youtube.com/watch?v=s1d8UGDCCN8
        - Similar to vertical traversal
        - when going right, do not change the value of HD
        - when going left, increment the value of HD
        - try using a recursive approach
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Approach 1
// Keep in mind to give priority to right subtree of root first
vector<int> diagonal1(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    queue<Node*> q;
    q.push(root);
    // Give priority to left part first
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        while(temp != NULL){
            ans.push_back(temp->data);
            if(temp->left != NULL){
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}


//Approach 2
void solve(Node* root, int level, map<int, vector<int> > &values) {
    //base case
    if(root == NULL) {
        return ;
    }
    
    values[level].push_back(root->data);
    if(root->left) {
        solve(root->left, level+1, values);
    }
    if(root->right) {
        solve(root->right, level, values);
    }
}
vector<int> diagonal2(Node *root) {
   //Your code here
    vector<int> ans;
    if(root == NULL) {
        return ans;
    }
    map<int, vector<int> > values;
    int level=0; //initial level
    solve(root, level, values);
    
    for(auto i: values) {
        for(auto j: i.second) {
            ans.push_back(j);
        }
    }
    return ans;
}



int main() {
    
    return 0;
}