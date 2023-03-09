/**
Problem Link: https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
Date: 2023-03-06 08:44:45
Level: Easy
Notes:
    - Problem  
        Given two binary max heaps as arrays, merge the given heaps to form a new max heap.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// User function Template for C++

class Solution{
    public:
    void heapify(vector<int> &arr, int n, int i) {
        /**
         * arr: is the heap stored as array
         * n:   is the total no of elements in the heap
         * i:   is the index of the element we want to heapify
         * assuming 0 based indexing
        */
        int largest = i;
        int left = 2*i+1;
        int right = 2*i + 2;
        if(left < n && arr[largest] < arr[left]) {
            largest = left;
        }
        if(right < n && arr[largest] < arr[right]) {
            largest = right;
        }
        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //step1: merge both arrays into 1
        vector<int> ans;
        for(auto i: a) {
            ans.push_back(i);
        }
        for(auto i: b) {
            ans.push_back(i);
        }
        
        //step2: build heap using merged arrays
        //heap creation
        int size = ans.size();
        for(int i=size/2-1; i>=0; i--) {
            heapify(ans, size, i);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}