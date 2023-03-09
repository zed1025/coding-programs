/**
Problem Link: https://www.codingninjas.com/codestudio/problems/h_920474
Date: 2023-03-04 08:03:48
Level: Hard
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


template <typename T>
class TreeNode{
public :
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
    if (left){
    delete left;
    }

    if (right){
    delete right;
    }
}   
};



//Approach 1
void findInorder(TreeNode<int>* root, vector<int> &inorder) {
    //Inorder: LNR
    if (root == NULL) return ;
    findInorder(root->left, inorder);
    inorder.push_back(root->data);
    findInorder(root->right, inorder);
}

vector<int> mergeArrays (vector<int> a, vector<int> b) {
    int m=a.size();
    int n=b.size();
    vector<int> ans(m+n);
    
    int i=0, j=0, k=0;
    while(i < m && j < n) {
        if(a[i] < b[j]) {
            ans[k++] = a[i++];
        } else {
            ans[k++] = b[j++];
        }
    }
    while(i<m) {
        ans[k++] = a[i++];
    }
    while(j<n) {
        ans[k++] = b[j++];
    }
    return ans;
}

TreeNode<int>* inorderToBST(int s, int e, vector<int> &inorder) {
    if(s > e) return NULL;

    int mid = (e+s)/2;
    TreeNode<int>* balancedRoot = new TreeNode<int>(inorder[mid]);
    balancedRoot->left = inorderToBST(s, mid-1, inorder);
    balancedRoot->right = inorderToBST(mid+1, e, inorder);
    return balancedRoot;
}









//Approach 2
void convertIntoDoublySortedLL(TreeNode<int> *root, TreeNode<int>* &head) { //dry run this
    //base case
    if(root == NULL) return ;

    convertIntoDoublySortedLL(root->right, head);
    root->right = head;
    if(head != NULL) {
        head->left = root;
    }
    head = root;
    convertIntoDoublySortedLL(root->left, head);
}

TreeNode<int> *mergeTwoLL(TreeNode<int> *head1, TreeNode<int> *head2) {
    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = NULL;

    while(head1 != NULL && head2 != NULL) {
        if(head1->data < head2->data) {
            if(head==NULL) {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }else { //insert at end
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }

        } else {
            if(head==NULL) {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }else { //insert at end
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while(head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }
    while(head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(TreeNode<int> *head) {
    int cnt=0;
    TreeNode<int> *temp=head;
    while(temp!=NULL) {
        temp=temp->right;
        cnt++;
    }
    return cnt;
}

TreeNode<int> *sortedLLToBST(TreeNode<int>* &head, int n) { //dry run this
    //base case
    if(n<=0 || head==NULL) {
        return NULL;
    }
    TreeNode<int> *left = sortedLLToBST(head, n/2);
    TreeNode<int> *root = head;
    root->left = left;

    head = head->right;

    root->right = sortedLLToBST(head, n-n/2-1);
    return root;
}





TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Driver Code for Approach 1.
    // vector<int> inorder1;
    // vector<int> inorder2;
    // findInorder(root1, inorder1);
    // findInorder(root2, inorder2);

    // vector<int> mergedArray = mergeArrays(inorder1, inorder2);
    // return inorderToBST(0, mergedArray.size()-1, mergedArray);





    // Driver Code for Approach 2.
    // Step 1: Convert BST to sorted LL in place
    TreeNode<int> *head1 = NULL;
    convertIntoDoublySortedLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoDoublySortedLL(root2, head2);
    head2->left = NULL;

    // Step 2: Merge sorted LL
    TreeNode<int> *head = mergeTwoLL(head1, head2);

    // Step 3: convert sorted LL to BST
    return sortedLLToBST(head, countNodes(head));
}





int main() {
    
    return 0;
}