/**
    Problem Link: https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
    Date: 26/01/2023 10:14:07
    Level: Easy
    Notes:
        - https://youtu.be/nHMQ33LZ6oA
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
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2) {
        //base case
        if(r1==NULL && r2==NULL) return true;
        if(r1==NULL && r2!=NULL) return false;
        if(r1!=NULL && r2==NULL) return false;
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        
        bool value = r1->data == r2->data;
        
        if(left and right and value) {
            return true;
        }
        return false;
    }
};

int main() {
    
    return 0;
}