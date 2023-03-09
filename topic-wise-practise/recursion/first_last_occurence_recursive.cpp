/**
https://www.codingninjas.com/codestudio/problems/first-and-last-position-of-an-element-in-sorted-array_1082549
https://www.youtube.com/watch?v=zD2Jg3alZV8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=13

Find first and last occurence of an element k in the given array arr, Array can have duplicate elements
If the element does not exist return -1 -1
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearchLeftEnd(int *arr, int s, int e, int key) {
    //base case
    if(s>e) {
        return -1;
    }

    int ans = -1, temp=-1;
    int mid = s + (e-s)/2;

    //recursive case
    if(arr[mid] == key) {
        ans = mid;
        temp = binarySearchLeftEnd(arr, s, mid-1, key);
    } else if(arr[mid] > key) {
        ans = binarySearchLeftEnd(arr, s, mid-1, key);
    } else{
        ans = binarySearchLeftEnd(arr, mid+1, e, key);
    }
    if(temp == -1) {
        return ans;
    }
    return temp;
}

int binarySearchRightEnd(int *arr, int s, int e, int key) {
    //base case
    if(s>e) {
        return -1;
    }

    int ans = -1, temp=-1;
    int mid = s + (e-s)/2;

    //recursive case
    if(arr[mid] == key) {
        ans = mid;
        temp = binarySearchRightEnd(arr, mid+1, e, key);
    } else if(arr[mid] > key) {
        ans = binarySearchRightEnd(arr, s, mid-1, key);
    } else{
        ans = binarySearchRightEnd(arr, mid+1, e, key);
    }
    if(temp == -1) {
        return ans;
    }
    return temp;
}

int main() {
    int arr[] = {0, 0, 1, 1, 2, 2, 2, 2};
    int size = 8;
    int key = 2;

    int left = binarySearchLeftEnd(arr, 0, size-1, key);
    cout << "Left Index: " << left << endl;
    int right = binarySearchRightEnd(arr, 0, size-1, key);
    cout << "Right Index: " << right << endl;

    return 0;
}