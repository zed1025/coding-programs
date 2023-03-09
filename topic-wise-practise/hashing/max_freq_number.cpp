/**
Problem Link: https://www.codingninjas.com/codestudio/problems/maximum-frequency-number_920319
Date: 2023-03-08 10:57:48
Level: Easy
Notes:
    - Problem Statement
        Ninja is given an array of integers that contain numbers in random order. He needs to write a program to find and return the number which occurs the maximum times in the given input. He needs your help to solve this problem.
        If two or more elements contend for the maximum frequency, return the element which occurs in the array first i.e. whose index is lowest.
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


int maximumFrequency(vector<int> &arr, int n) {
    unordered_map<int, int> count;
    int maxFreq=0;
    int maxAns = 0;

    for(int i=0; i<arr.size()   ; i++) {
        count[arr[i]]++;
        maxFreq = max(maxFreq, count[arr[i]]);
    }

    for(int i=0; i<arr.size(); i++) {
        if(maxFreq == count[arr[i]]) {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main() {
    
    return 0;
}