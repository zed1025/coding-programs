/**
    Problem Link:
    Date: 14/02/2023 09:52:44
    Level: 
    Notes:
        -
*/

// #include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;
// typedef long long int ll;

class Node {
    public:
        int data;
        Node *left;
        Node *right;

        Node (int d) {
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};

Node* insertIntoBST(Node* root, int data) {
    //base case 
    if(root == NULL) {
        root = new Node(data);
        return root;
    }

    if(data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;
    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node *root) {
    // logic: use queue and BFS
    queue<Node *> q;
    q.push(root);
    q.push(NULL); //seperator

    while(!q.empty()) {
        Node *temp = q.front();
    
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


bool searchInBST(Node *root, int x) {
    // Write your code here.
    if(root == NULL) return false;
    if(root->data == x) {
        return true;
    }
    if(x > root->data) {
        return searchInBST(root->right, x);
    } else {
        return searchInBST(root->left, x);
    }
    return false;
}

//inorder
void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//preorder
void preorder(Node *root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

//postorder
void postorder(Node *root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

//min value
Node* minValue(Node* root) {
    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

//max value
Node* maxValue(Node* root) {
    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

//TODO: function to find inorder predecessor

//TODO: function to find inorder successor

//Deletion in BST
/*
    - Algo
        - reach the node(recursively)
        - 4 cases for deletion
            - node to delete has 0 child -> delete node(free space), return NULL
            - node to delete has 1 child -> temp=root->left, delete root, return temp [same for right]
            - node to delete has 2 child -> replace the node by its inorder successor/predecessor, recursively delete the inorder succ./pred.
*/
Node* deleteFromBST(Node* root, int val) {
    if(root == NULL) return root;

    if(root->data == val) {
        //0 child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        //1 child 
        //left child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL) {
            int mini = minValue(root->right)->data; //will give inorder successor
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }else if (root->data > val) {
        root->left = deleteFromBST(root->left, val);
        return root;
    } else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
    return NULL;
}

int main() {
    Node* root = NULL;
    cout << "Enter data to create BST: ";
    takeInput(root);
    cout << "Printing the level order traversal of BST: \n";
    levelOrderTraversal(root);
    cout << searchInBST(root, 5);

    cout << "\n\nMin Value: " << minValue(root)->data << "\tMax Value: " << maxValue(root)->data << endl;
    
    //DELETION
    root = deleteFromBST(root, 50);

    levelOrderTraversal(root);
    return 0;
}