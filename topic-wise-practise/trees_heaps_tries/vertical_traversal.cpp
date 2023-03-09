/**
    Problem Link: https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
    Date: 30/01/2023 09:11:04
    Level: Medium
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    Node* left;
    Node* right;
};

//utility function to create a tree node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//function to build tree
Node* buildTree(string str) {
    //corner case
    if(str.length() == 0 || str[0]=='N') {
        return NULL;
    }

    //creating a vector of strings from input string after splitting by space
    vector<string> ip;

    istringstream iss(str);
    for(string ss; iss >> str;) {
        ip.push_back(str);
    }

    //create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    //push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    //starting fron second element
    int i=1;
    while(!queue.empty() && i < ip.size()) {
        //get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        //get the current node's value fron the string
        string currVal = ip[i];

        //if the left child is not null
        if(currVal != "N") {
            //create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        //for the right child
        i++;
        if(i >= ip.size()) {
            break;
        }
        currVal = ip[i];

        //if the right child is not null
        if(currVal != "N") {
            //create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            //push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

//function for inorder traversal
void printInorder(Node* root) {
    if(!root) {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


//main logic
class Solution {
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root) {
        //Your code here
        map<int, map<int, vector<int> > > nodes; //nodes[x][y]=vector
        queue<pair<Node*, pair<int, int> > > q; //the inner pair is pair<HD, level>
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        
        q.push(make_pair(root, make_pair(0, 0))); //root has horizonatal_dist(HD)=0 and level=0
        while(!q.empty()) {
            pair<Node*, pair<int, int> > temp = q.front();
            q.pop();
            Node* front = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            //the node which you are currently processing make an entry for it in the map
            nodes[hd][level].push_back(front->data);
            
            if(front->left) {
                q.push(make_pair(front->left, make_pair(hd-1, level+1)));
            }
            if(front->right) {
                q.push(make_pair(front->right, make_pair(hd+1, level+1)));
            }
        }
        for(auto i: nodes) { //extract final answer from map
            // i represents: <int, map>, map represents: <int, vector<int>>
            for(auto j: i.second) { //i.second represnts the map inside the map
                for(auto k: j.second) { //j.second is the vector<int>, NOTE map is sorted in ascending according to keys
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--) {
        string s;
        getline(cin, s);
        Solution obj;
        Node* root = buildTree(s);

        vector<int> res = obj.verticalOrder(root);
        for(int i: res) {
            cout << i << " ";
        } cout << endl;
    }
    return 0;
}