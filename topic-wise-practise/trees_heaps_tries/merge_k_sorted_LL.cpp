/**
Problem Link: https://www.codingninjas.com/codestudio/problems/merge-k-sorted-lists_992772
Date: 2023-03-07 09:43:22
Level: 
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};



class compare {
    public:
        bool operator() (Node<int> *a, Node<int> *b) {
            return a->data > b->data;
        }
};


Node<int>* mergeKLists(vector<Node<int>*> &listArray) {
    priority_queue<Node<int>*, vector<Node<int>* >, compare > minHeap;

    //insert the first k elements of each list
    int k = listArray.size();
    if(k == 0) return NULL;
    for(int i=0; i<k; i++) {
        if(listArray[i] != NULL) {
            minHeap.push(listArray[i]);
        }
    }

    Node<int> *head = NULL;
    Node<int> *tail = NULL;

    while(minHeap.size() > 0) {
        Node<int> *top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL) {
            minHeap.push(top->next);
        }

        if(head == NULL) { //LL is empty
            head = top;
            tail = top;
        } else { //insert at end of the answer
            tail->next = top;
            tail = top; 
        }
    }
    return head;
}

int main() {
    
    return 0;
}