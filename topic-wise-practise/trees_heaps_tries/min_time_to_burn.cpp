/**
    Problem Link: https://practice.geeksforgeeks.org/problems/burning-tree/1
    Date: 13/02/2023 08:02:01
    Level: Hard
    Notes:
        - https://www.youtube.com/watch?v=XLdpy0_6MR4&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=73
        - TC=O(n)+O(n)
            - if map<> we choose has O(1) insertion then TC=O(n)
            - if map<> we choose has O(log n) insertion then TC=O(nlog n)
        - SC=O(n)+O(n)=O(n)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  private:
  //creates nodeToParent mapping and returns target node
  Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
    Node* res=NULL;
    queue<Node*> q;
    q.push(root);
    nodeToParent[root]=NULL;
    while(!q.empty()) { //level order traversal to find Node-to-Parent mapping and finding the target node
        Node* front = q.front();
        q.pop();
        if(front->data == target) {
            res=front;
        }
        if(front->left) {
            nodeToParent[front->left]=front;
            q.push(front->left);
        }
        if(front->right) {
            nodeToParent[front->right]=front;
            q.push(front->right);
        }
    }
    return res;
  }
  int burnTree(Node* root, map<Node*, Node*> nodeToParent) {
      map<Node*, bool> visited;
      int ans=0;
      queue<Node* > q;
      q.push(root);
      visited[root]=true;
      while(!q.empty()) {
          bool flag=false;
          int size=q.size();
          for(int i=0; i<size; i++) {
              //process neighbouring nodes
              Node* front = q.front();
              q.pop();
              if(front->left && !visited[front->left]) {
                  flag=true;
                  q.push(front->left);
                  visited[front->left] = true;
              }
              if(front->right && !visited[front->right]) {
                  flag=true;
                  q.push(front->right);
                  visited[front->right] = true;
              }
              if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                  flag=true;
                  q.push(nodeToParent[front]);
                  visited[nodeToParent[front]]=true;
              }
          }
          if(flag) {
              ans++;
          }
      }
      return ans;
  }
  public:
    int minTime(Node* root, int target)  {
        //steps to follow
        //S1: create node to parent mapping
        //S2: find target node
        //S3: burn the tree in min time
        int ans=0;
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        ans = burnTree(targetNode, nodeToParent);
        return ans;
    }
};

int main() {
    
    return 0;
}