/**
Problem Link: https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
Date: 2023-03-06 09:22:08
Level: Easy
Notes:
    - Problem 
        There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 
    - TC: O(n log n)
    - SC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
    public:
    long long minCost(long long arr[], long long n) {
        long long ans=0;
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(long long i=0; i<n; i++) {
            pq.push(arr[i]);
        }
        while(pq.size() != 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            long long temp = first+second;
            ans += temp;
            pq.push(temp);
        }
        return ans;
    }
};

int main() {
    
    return 0;
}