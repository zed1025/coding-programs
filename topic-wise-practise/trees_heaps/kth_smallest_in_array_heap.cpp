/**
Problem Link: https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
Date: 2023-03-06 08:03:50
Level: 
Notes:
    - Problem
        Given an array arr[] and an integer K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
        Note :-  l and r denotes the starting and ending index of the array.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//solution using sorting
//User function template for C++

class Solution1{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        std::sort(arr, arr+(r-l+1));
        return arr[k-1];
    }
};


//solution using heap
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> pq;
        for(int i=0; i<k; i++) {
            pq.push(arr[i]);
        }
        for(int i=k; i<=r; i++) {
            if(arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};

int main() {
    
    return 0;
}