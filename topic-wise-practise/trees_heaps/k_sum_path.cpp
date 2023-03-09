/** 
    Problem Link: https://practice.geeksforgeeks.org/problems/k-sum-paths/1
    Date: 06/02/2023 08:37:13
    Level: Medium
    Notes:
        -
*/

struct Node     {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution{
  private:
    void solve(Node* root, int k, long long &count, vector<int> path) {
        if(root==NULL) return ;
        
        path.push_back(root->data);
        
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);
        
        //after returning check for k-sum
        int size = path.size();
        int sum=0;
        for(int i=size-1; i>=0; i--) {
            sum += path[i];
            if(sum == k) {
                count++;
            }
        }
        
        //before returning, remove the last element from the path since the previous node didnt have it
        path.pop_back();
    }
  public:
    int sumK(Node *root,int k) {
        // code here 
        vector<int> path;
        long long count=0;
        solve(root, k, count, path);
        return count;
    }
};

int main() {
    
    return 0;
}