/**
https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549
https://www.youtube.com/watch?v=zD2Jg3alZV8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=13

Find first and last occurence of an element k in the given array arr, Array can have duplicate elements
If the element does not exist return -1 -1

Solution
- solve left and right half separately
- for left half
    - if the mid element is equal to the key, they store the mid index and continue the search in the left half, this is because the 
        element(key) can be repeated
    - the cases for arr[mid]<key and arr[mid]>key remain same
- for right half
    - similar approach as the left part


- Applications
    - find total number of occurence of an element in the array (return rightend-leftend)

*/

#include<bits/stdc++.h>
using namespace std;

int binarySearchLeftEnd(int *arr, int s, int e, int key) {
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e) {
        if(arr[mid] == key) {
            ans = mid;
            e = mid-1; //new addition to binary search
        } else if(arr[mid] < key) {
            s = mid+1;
        } else if(arr[mid] > key) {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int binarySearchRightEnd(int *arr, int s, int e, int key) {
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e) {
        if(arr[mid] == key) {
            ans = mid;
            s = mid+1; //new addition to binary search
        } else if(arr[mid] < key) {
            s = mid+1;
        } else if(arr[mid] > key) {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {
    int arr[] = {0, 0, 1, 1, 2, 2, 2, 2};
    int size = 8;
    int key = 1;

    int left = binarySearchLeftEnd(arr, 0, size-1, key);
    cout << "Left Index: " << left << endl;
    int right = binarySearchRightEnd(arr, 0, size-1, key);
    cout << "Right Index: " << right << endl;

    return 0;
}