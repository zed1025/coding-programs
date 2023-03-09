/**
Problem Link: https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379
Date: 2023-03-07 09:11:47
Level: Medium
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class node {
    public: 
        int data;
        int i, j;

        node(int data, int row, int col) {
            this->data = data;
            i = row;
            j = col;
        }
};

class compare{
    public:
        bool operator() (node* a, node *b) {
            return a->data > b->data;
        }
};

//optimised
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*, vector<node*>,  compare> minHeap;

    //step1: insert first element of all the arrays in the minHeap
    for(int i=0; i<k; i++) {
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    //step2: 
    while(minHeap.size() > 0) {
        node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->i;
        int j = tmp->j;
        if(j+1 < kArrays[i].size()) {
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    } 

    return ans;
}

int main() {
    
    return 0;
}