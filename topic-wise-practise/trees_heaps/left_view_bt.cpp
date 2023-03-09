/**
    Problem Link: https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
    Date: 30/01/2023 12:55:42
    Level: Easy
    Notes:
        -
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

//functions
//my solution -> AC
vector<int> leftView(Node *root) {
   // Your code here
   queue<Node*> q;
   vector<int> ans;
   if(root == NULL) {
       return ans;
   }
   q.push(root);
   q.push(NULL);
   bool mustRead=true;
   while(!q.empty()) {
       Node* temp = q.front();
       q.pop();
       if(temp==NULL) {
           mustRead=true;
           if(!q.empty()) {
                q.push(NULL);
            }
       } else {
           if(mustRead) {
               ans.push_back(temp->data);
               mustRead=false;
           }
           if(temp->left) {
               q.push(temp->left);
           }
           if(temp->right) {
               q.push(temp->right);
           }
       }
   }
   return ans;
}


//approach 2
void solve(Node* root, vector<int> &ans, int level) {
    if(root == NULL) {
        return;
    }
    
    //we entered into new level
    if(level == ans.size()) {
        ans.push_back(root->data);
    }
    
    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView2(Node *root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

int main() {
    
    return 0;
}