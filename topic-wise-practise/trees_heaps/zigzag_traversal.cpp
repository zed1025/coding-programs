/**
    Problem Link: https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
    Date: 27/01/2023 18:39:43
    Level: Easy
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root) {
    	vector<int> result;
    	if(root == NULL) return result;
    	
    	queue<Node* > q;
    	q.push(root);
    	
    	bool leftToRight=true;
    	
    	while(!q.empty()) {
    	    //find level size
    	    int size = q.size();
    	    //initialize a temp vector of size=level size
    	    vector<int> ans(size);
    	    //iterate through each element in the queue
    	    for(int i=0; i<size; i++) {
    	        Node* front = q.front();
    	        q.pop();
                //insert element based on direction, either to the start or to the end of the temp array, ans
    	        int index = leftToRight ? i:size-i-1;
    	        ans[index] = front->data;
    	        if(front->left) q.push(front->left);
    	        if(front->right) q.push(front->right);
    	    }
    	    for(auto i: ans) {
        	    result.push_back(i);
        	}
    	    //level completed, change direction
    	    leftToRight = !leftToRight;
    	}
    	
    	return result;
    }
};

int main() {
    
    return 0;
}