/**
    Problem Link: https://practice.geeksforgeeks.org/problems/construct-tree-1/1
    Date: 11/02/2023 18:20:14
    Level: Medium
    Notes:
        - Algorithm
            - take first elemetn of preorder as index
            - take index as root
            - find root element's position in inorder, call it pos
            - recursive_call(root->left, start_of_inorder, pos-1)
            - recursive_call(root_,right, pos+1, end_of_inorder)

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

//SOLUTION 1
class Solution{
public:
    int pos(int in[], int start , int end , int key){
        for(int i=start; i<=end;i++) {
            if(in[i] == key){
                return i;
            }
        }
        return -1;
    }
     
     
    Node* solve(int in[], int pre[], int &index, int instart, int inend, int n) {
        if(instart > inend || index >=n) {
            return NULL;
        }
            
        int element = pre[index];
        index++;
        
        int position = pos(in,instart,inend,element);
        
        Node* root = new Node(element);
        root->left = solve(in,pre,index,instart,position-1,n);
        root->right = solve(in,pre,index,position+1,inend,n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n) {
        int preorderIndex=0;

        Node* ans= solve(in,pre,preorderIndex,0,n-1,n);
        return ans;
    }
};

//SOLUTION 2: Small optimization
// https://www.youtube.com/watch?v=ffE1xj51EBQ&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=72
// NOT WORKING! -> see my other failed submissions, same code but not working


int main() {
    
    return 0;
}