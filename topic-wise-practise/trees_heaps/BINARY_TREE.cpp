/**
    Problem Link:
    Date: 20/01/2023 10:24:35
    Level: 
    Notes:
        -
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class node {
    public:
        int data;
        node *left;
        node *right;
    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

//recursively building the tree, -1=NULL
node *buildTree(node *root) {
    //enter data for root
    cout << "Enter data for root: \n";
    int data;
    cin >> data;
    root = new node(data);

    //base case for recursion
    if(data == -1) {
        return NULL;
    }

    //recursively building the tree
    cout << "Enter data for left subtree of " << data << ": \n";
    root->left = buildTree(root->left);
    cout << "Enter data for right subtree of " << data << ": \n";
    root->right = buildTree(root->right);

    return root;
}

//level order traversal, root at level 0
// uses -> print tree on terminal
void levelOrderTraversal(node *root) {
    // logic: use queue and BFS
    queue<node *> q;
    q.push(root);
    q.push(NULL); //seperator

    while(!q.empty()) {
        node *temp = q.front();
    
        q.pop();

        if(temp == NULL) { //previous level traversed
            cout << endl;
            if(!q.empty()) { //if queue still has elements they must be the children, so add NULL at the end
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

//reverse level order traversal
//The idea is to print the last level first, then the second last level, and so on. 
//Like Level order traversal, every level is printed from left to right.
//https://www.geeksforgeeks.org/reverse-level-order-traversal/
void reverseLevelOrder(node *root) {
    //using a stack and queue
    stack<node* > s;
    queue<node *> q;

    q.push(root);
    while(!q.empty()) {
        node *temp = q.front();
        s.push(temp);
        q.pop();

        if(temp->right) {
            q.push(temp->right);
        }
        if(temp->left) {
            q.push(temp->left);
        }
    }

    //print while stack is not empty
    while(!s.empty()) {
        node *temp = s.top();
        cout << temp->data << " ";
        s.pop();
    }
}

//inorder
void inorder(node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//preorder
void preorder(node *root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//postorder
void postorder(node *root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//build tree from level order traversal
void buildFromLevelOrder(node* &root) {
    //level order => use queue
    queue<node *> q;

    cout << "Enter data for root: ";
    int n;
    cin >> n;
    root = new node(n);

    q.push(root);

    while(!q.empty()) {
        node *temp = q.front();
        q.pop();
        cout << "Enter left node for " << temp->data << ": ";
        int left;
        cin >> left;
        if(left != -1) {
            temp->left = new node(left);
            q.push(temp->left);
        }
        cout << "Enter right node for " << temp->data << ": ";
        int right;
        cin >> right;
        if(right != -1) {
            temp->right = new node(right);
            q.push(temp->right);
        }

    }
}



int main() {
    node *root = NULL;

    buildFromLevelOrder(root); //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1
    levelOrderTraversal(root);

    /*
    //creating a tree
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    //level order traversal
    cout << endl;
    levelOrderTraversal(root);

    //inorder traversal
    cout << endl;
    inorder(root);

    //reverse level order traversal
    cout << endl;
    reverseLevelOrder(root);
    */
    
    return 0;
}